#ifndef GPTIM_H
#define GPTIM_H

#include "driver/timer.h"
#include "led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_clk_tree.h"

typedef struct 
{
	timer_src_clk_t clk_src;
	int timer_group;
	int timer_idx;
	uint64_t timing_time;
	uint64_t alarm_value;
	timer_autoreload_t auto_reload;
	uint64_t timer_count_value;
}timg_config_t;

void timg_init(timg_config_t *timg_config);


#endif // GPTIM_H
