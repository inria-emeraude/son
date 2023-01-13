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
  
  ButtonHandler buttonHandler(1,10);

  // infinite loop
  while(1) {
    buttonHandler.tick();
    float b1 = buttonHandler.getValue()*0.2 - 1.0;
    std::cout << "b1: " << b1 << "\n";
    audioDsp.setB1(b1);
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}