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
  
  ButtonHandler buttonHandler(2,20);

  // infinite loop
  while(1) {
    buttonHandler.tick();
    int del = buttonHandler.getValue()*6 + 50;
    std::cout << "Del: " << del << "\n";
    audioDsp.setDel(del);
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}