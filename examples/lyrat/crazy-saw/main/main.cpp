#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "../../lib/ES8388.h"

#include "AudioDsp.h"

extern "C" {
  void app_main(void);
}

void app_main(void)
{
  // initialize Audio Codec
  ES8388 es8388;
  es8388.init();
  
  // start audio DSP
  AudioDsp audioDsp(48000,16);
  audioDsp.start();

  // infinite loop
  while(1) {
    // changing frequency randomly every 100ms
    audioDsp.setFreq(rand()%(2000-50 + 1) + 50);
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}