#include <stdio.h>
#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#include "../../lib/ES8388.h"
#include "../../lib/ButtonHandler.h"
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
  
  ButtonHandler buttonHandler(2,10);

  // infinite loop
  while(1) {
    buttonHandler.tick();
    if(buttonHandler.getParamNumber() == 0){
      float freq = buttonHandler.getValue()*100 + 80;
      std::cout << "Freq: " << freq << "\n";
      audioDsp.setFreq(freq);
    }
    if(buttonHandler.getParamNumber() == 1){
      float gain = buttonHandler.getValue()*0.1;
      std::cout << "Gain: " << gain << "\n";
      audioDsp.setGain(gain);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}