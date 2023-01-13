#include <stdio.h>
#include <cmath>
#include <algorithm>

#include "AudioDsp.h"
#include "driver/i2s.h"

#define MULT_S16 32767
#define DIV_S32 4.6566129e-10

AudioDsp::AudioDsp(int SR, int BS) : 
fSampleRate(SR),
fBufferSize(BS),
fNumOutputs(2),
fHandle(nullptr),
fRunning(false),
sawtooth(SR),
echo(SR,10000)
{
  // config i2s pin numbers
  i2s_pin_config_t pin_config;
  pin_config = {
    .bck_io_num = 5,
    .ws_io_num = 25,
    .data_out_num = 26,
    .data_in_num = 35
  };
  
  // config i2
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX),
    .sample_rate = fSampleRate,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // high interrupt priority
    .dma_buf_count = 3,
    .dma_buf_len = fBufferSize,
    .use_apll = false,
    .tx_desc_auto_clear = true,
    .fixed_mclk = false
  };
  
  // installing i2s driver
  i2s_driver_install((i2s_port_t)0, &i2s_config, 0, nullptr);
  i2s_set_pin((i2s_port_t)0, &pin_config);
  PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
  REG_WRITE(PIN_CTRL, 0xFFFFFFF0);
  
  // setting up DSP objects
  echo.setDel(10000);
  echo.setFeedback(0.5);
}

// starts audio task
bool AudioDsp::start()
{
  if (!fRunning) {
    fRunning = true;
    return (xTaskCreatePinnedToCore(audioTaskHandler, "Audio DSP Task", 4096, (void*)this, 24, &fHandle, 0) == pdPASS);
  } 
  else {
    return true;
  }
}

// stops audio task
void AudioDsp::stop()
{
  if (fRunning) {
    fRunning = false;
    vTaskDelay(1/portTICK_PERIOD_MS);
    fHandle = nullptr;
  }
}

// set sine wave frequency
void AudioDsp::setFreq(float freq){
  sawtooth.setFrequency(freq);
}

void AudioDsp::audioTask()
{
  // inifinite loop
  while (fRunning) {
    int16_t samples_data_out[fNumOutputs*fBufferSize];
    
    // processing buffers
    for (int i = 0; i < fBufferSize; i++) {
      // DSP
      float currentSample = echo.tick(sawtooth.tick()*2 - 1)*0.5;
      
      // copying to output buffer
      samples_data_out[i*fNumOutputs] = currentSample*MULT_S16;
      samples_data_out[i*fNumOutputs+1] = samples_data_out[i*fNumOutputs];
    }
    // transmitting output buffer
    size_t bytes_written = 0;
    i2s_write((i2s_port_t)0, &samples_data_out, fNumOutputs*sizeof(int16_t)*fBufferSize, &bytes_written, portMAX_DELAY);
  }
  // Task has to deleted itself beforee returning
  vTaskDelete(nullptr);
}

// static cast of the audio task
void AudioDsp::audioTaskHandler(void* arg)
{
  AudioDsp* audio = static_cast<AudioDsp*>(arg);
  audio->audioTask();
}
