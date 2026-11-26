#include <stdio.h>
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
	led_init();

	while (1)
	{
		LED_TOGGLE();
		vTaskDelay(500);
	}

}
