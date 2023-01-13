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
  
  ButtonHandler buttonHandler(4,20);

  // infinite loop
  while(1) {
    buttonHandler.tick();
    if(buttonHandler.getParamNumber() == 0){
      float freq = buttonHandler.getValue()*100 + 80;
      std::cout << "Carrier Freq: " << freq << "\n";
      audioDsp.setCFreq(freq);
    }
    if(buttonHandler.getParamNumber() == 1){
      float freq = buttonHandler.getValue()*100 + 80;
      std::cout << "Mod Freq: " << freq << "\n";
      audioDsp.setMFreq(freq);
    }
    if(buttonHandler.getParamNumber() == 2){
      float index = buttonHandler.getValue()*20;
      std::cout << "Index: " << index << "\n";
      audioDsp.setIndex(index);
    }
    if(buttonHandler.getParamNumber() == 3){
      float gain = buttonHandler.getValue()*0.05;
      std::cout << "Gain: " << gain << "\n";
      audioDsp.setGain(gain);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}