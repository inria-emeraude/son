/* Blink-timer Example buidt from IDF Blink example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/timer.h"
#include "soc/timer_group_reg.h"
#include "sdkconfig.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO


#define TIMER_DIVIDER         16  //  Hardware timer clock divider
#define TIMER_SCALE           (TIMER_BASE_CLK / TIMER_DIVIDER)  // convert counter value to seconds
#define TIMER_INTERVAL_SEC   (0.01) // used to tune timer interrupt intervals 


/*
 * A sample structure to pass events
 * from the timer interrupt handler to the main program.
 */
int level=0; //global variable maintaining level of LED
int slowdown=1; //used to slow down the blink

/**********************************************************************/
/* raw register value reading                                         */
/**********************************************************************/
int read_reg(int address)
{
  int *p,reg;
  p=(int *)address;
  reg=*p;
  return reg;
}

/**********************************************************************/
/* raw register value writing                                         */
/**********************************************************************/
void write_reg(int address, int value)
{
  int *p;
  p=(int *)address;
  *p=value;
}

/**********************************************************************/
/* printing one register value                                        */
/**********************************************************************/
void print_one_register(char *name, int value)
{
  int *p,reg;
  p=(int *)value;
  reg=*p;
  printf("[%s] = 0x%X\n",name,reg);
}

/**********************************************************************/
/* printing timer0 registers                                          */
/**********************************************************************/
void print_timer_registers()
{
  /* CONFIG_REG: 400C0200 = 01000000000000100000110000000000             */
  /*                        ^increase    ^16   ^^ level int & int enable */
  print_one_register("TIMG_T0CONFIG_REG(0)",TIMG_T0CONFIG_REG(0));
  print_one_register("TIMG_T0LO_REG(0)",TIMG_T0LO_REG(0));
  print_one_register("TIMG_T0HI_REG(0)",TIMG_T0HI_REG(0));
  print_one_register("TIMG_T0ALARMLO_REG(0)",TIMG_T0ALARMLO_REG(0));
  print_one_register("TIMG_T0LOADLO_REG(0)",TIMG_T0LOADLO_REG(0));
  print_one_register("TIMG_T0LOADLO_REG(0)",TIMG_T0LOADLO_REG(0));
  print_one_register("TIMG_T0LOADHI_REG(0)",TIMG_T0LOADHI_REG(0));
  print_one_register("TIMG_INT_RAW_TIMERS_REG(0)",TIMG_INT_RAW_TIMERS_REG(0));
  print_one_register("TIMG_INT_ST_TIMERS_REG(0)",TIMG_INT_ST_TIMERS_REG(0));
  print_one_register("TIMG_INT_ENA_TIMERS_REG(0)",TIMG_INT_ENA_TIMERS_REG(0));
  print_one_register("TIMG_INT_CLR_TIMERS_REG(0)",TIMG_INT_CLR_TIMERS_REG(0));
}


/**********************************************************************/
/*  timer0 ISR                                                        */
/**********************************************************************/
void IRAM_ATTR timer_group0_timer0_isr()
{
  timer_spinlock_take(TIMER_GROUP_0);

  /* switch LED level */
  level=!level;
  gpio_set_level(BLINK_GPIO, level);
  if (slowdown < 20)
    slowdown+=1;
  else
    slowdown=1;

  /* ISR print timer counter (DEBUG purpose)*/
  uint64_t timer_counter_value =
    timer_group_get_counter_value_in_isr(TIMER_GROUP_0, 0);

  /* Warning: cannot use printf in ISR */
  ets_printf("Timer 0 from Group 0, slowdown=%d, counter= 0x%08x%08x\n",
	     slowdown,
	     (uint32_t) (timer_counter_value >> 32),
	     (uint32_t) (timer_counter_value));
  
  /* Retrieve the interrupt status and the counter value
     from the timer that reported the interrupt */
  uint32_t timer_intr = timer_group_get_intr_status_in_isr(TIMER_GROUP_0);

  /* Clear the interrupt
     and update the alarm time for the timer with without reload */
  if (timer_intr & TIMER_INTR_T0) {
    timer_group_clr_intr_status_in_isr(TIMER_GROUP_0, 0);
    timer_counter_value +=
      (uint64_t) (slowdown * TIMER_INTERVAL_SEC * TIMER_SCALE);
    timer_group_set_alarm_value_in_isr(TIMER_GROUP_0, 0, timer_counter_value);
  } 

  /* we need enable it again, so it is triggered the next time */
  timer_group_enable_alarm_in_isr(TIMER_GROUP_0, 0);

  timer_spinlock_give(TIMER_GROUP_0);
}

/**********************************************************************/
/*  timer0 init function usint IDF API                                */
/**********************************************************************/
void timer_init_g0_t0(double timer_interval_sec)
{
      /* Use IDF API to initialize a timer: 
	 https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/timer.html#functional-overview
      */
    timer_config_t config = {
      //Hardware timer clock divider (see above)
      .divider = TIMER_DIVIDER, 
      //defined in esp-idf/components/soc/include/hal/timer_types.h
      .counter_dir = TIMER_COUNT_UP,
      //defined in esp-idf/components/soc/include/hal/timer_types.h
      .counter_en = TIMER_PAUSE,
      //defined in esp-idf/components/soc/include/hal/timer_types.h
      .alarm_en = TIMER_ALARM_EN,
      // Ca j'ai pas encore trop compris, mais on active pas l'auto_reload
      .auto_reload = 0,
    }; // default clock source is APB
    timer_init(TIMER_GROUP_0, 0, &config);
    timer_set_counter_value(TIMER_GROUP_0, 0, 0x00000000ULL);
    timer_set_alarm_value(TIMER_GROUP_0, 0, timer_interval_sec * TIMER_SCALE);
    timer_enable_intr(TIMER_GROUP_0, 0);
    timer_isr_register(TIMER_GROUP_0, 0, timer_group0_timer0_isr,
                       (void *) NULL, ESP_INTR_FLAG_IRAM, NULL);

}
void app_main(void)
{
  /* simply Configure timer to blink LED    */
  
  gpio_pad_select_gpio(BLINK_GPIO);
  /* Set the GPIO as a push/pull output */
  gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
  /* initialize timer */
  timer_init_g0_t0(TIMER_INTERVAL_SEC);
  print_timer_registers();
  timer_start(TIMER_GROUP_0, 0);
  
  /* set initial LED level */
  gpio_set_level(BLINK_GPIO, level);
  while(1) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
