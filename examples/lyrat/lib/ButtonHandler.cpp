#include "driver/gpio.h"

#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(int nParams, int precision) :
n(nParams),
p(precision),
param(0),
value(0),
paramChange(true),
valueChange(true)
{
  gpio_config_t io_conf;
  io_conf.intr_type = (gpio_int_type_t) GPIO_PIN_INTR_POSEDGE;
  io_conf.pin_bit_mask = ((1ULL<<36) | (1ULL<<39));
  io_conf.mode = GPIO_MODE_INPUT;
  io_conf.pull_up_en = (gpio_pullup_t)1;
  gpio_config(&io_conf);
}

int ButtonHandler::getParamNumber()
{
  return param;
}

int ButtonHandler::getValue()
{
  return value;
}
    
void ButtonHandler::tick()
{
  if((gpio_get_level(GPIO_NUM_36) == 0) && paramChange){
    param = (param + 1)%n;
    paramChange = false;
  }
  else if(gpio_get_level(GPIO_NUM_36) == 1){
    paramChange = true;
  }
  if((gpio_get_level(GPIO_NUM_39) == 0) && valueChange){
    value = (value + 1)%(p + 1);
    valueChange = false;
  }
  else if(gpio_get_level(GPIO_NUM_39) == 1){
    valueChange = true;
  }
}
