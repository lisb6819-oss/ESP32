#include <stdio.h>
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "exit.h"

void app_main(void)
{
	led_init();
	exit_init();

	while (1)
	{
		vTaskDelay(500);
	}

}
