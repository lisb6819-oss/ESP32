#include <stdio.h>
#include <stdlib.h>
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gptim.h"
#include "esp_log.h"
#include "driver/timer.h"


void app_main(void)
{
	timg_config_t *timgr_config = malloc(sizeof(timg_config_t));
	led_init();

	timgr_config->timer_count_value = 0;
	timgr_config->clk_src = TIMER_SRC_CLK_APB;
	timgr_config->timer_group = TIMER_GROUP_0;
	timgr_config->timer_idx = TIMER_0;
	timgr_config->timing_time = 1000000; // 1 second
	timgr_config->alarm_value = timgr_config->timing_time;
	timgr_config->auto_reload = TIMER_AUTORELOAD_EN;
	timg_init(timgr_config);

	while (1)
	{
		if(timgr_config->timer_count_value != 0)
		{
			ESP_LOGI("TIMER", "Timer Count Value in ISR: %llu", timgr_config->timer_count_value);
			timgr_config->timer_count_value = 0;
		}	
		vTaskDelay(10);
	}

}
