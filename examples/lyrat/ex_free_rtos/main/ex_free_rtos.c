/* Example Free RTOS, build from IDF GPIO Example

   Romain Michon, Tanguy Risset
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

/**
 * Brief:
 * This test code starts two free rtos Task, one is generating number 
 * each second, send via a FIFO these number to the other task which is 
 * printing them on uart 
 *
 */

#define DEBUG

static xQueueHandle int_queue = NULL;


static void print_number_task(void* arg)
{
  uint32_t num, cpt=0;
  for(;;) {
      if(xQueueReceive(int_queue, &num, portMAX_DELAY)) {
	cpt++;
	printf("number[%d] received: %d\n", cpt, num); 
	//use vTaskDelay(750 / portTICK_RATE_MS); to
    }
  }
}

static void generate_number_task(void* arg)
{
  uint32_t num,cpt=0;
  const int max = 100;

  for(;;) {
    cpt++;
    num = 1 + esp_random() % (max - 1);
    xQueueSendFromISR(int_queue, (void *) &num, NULL);
#ifdef DEBUG
    printf("number[%d] send (%d)\n", cpt, num);
#endif
    vTaskDelay(750 / portTICK_RATE_MS);
    // use vTaskDelay(75 / portTICK_RATE_MS); to saturat queue
  }
}

void app_main(void)
{

    //create a queue to send integer
    int_queue = xQueueCreate(10, sizeof(uint32_t));
    //start  tasks
    xTaskCreate(print_number_task, "print_number_task", 2048, NULL, 9, NULL);
    xTaskCreate(generate_number_task, "generate_number_task", 2048, NULL, 10, NULL);


    int cnt = 0;
    while(1) {
        printf("counting seconds: %d\n", cnt++);
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

