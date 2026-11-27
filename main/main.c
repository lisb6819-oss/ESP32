#include <stdio.h>
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esptim.h"

void app_main(void)
{
	led_init();
	esptim_init(1000000); // 500 ms

}
