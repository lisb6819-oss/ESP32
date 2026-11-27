#ifndef LEDC_H
#define LEDC_H

#include "driver/ledc.h"
#include "driver/gpio.h"

#define LEDC_PWN_TIMER   LEDC_TIMER_0
#define LEDC_PWN_CH0_GPIO	 GPIO_NUM_1
#define LEDC_PWN_CH0_CHANNEL	 LEDC_CHANNEL_0

typedef struct
{
	ledc_clk_cfg_t clk_cfg;
	ledc_timer_t timer_num;
	uint32_t freq_hz;
	ledc_timer_bit_t duty_resolution;
	ledc_channel_t channel;
	uint32_t duty;
	int gpio_num;
} ledc_config_t;

void ledc_init(ledc_config_t *ledc_config);
void ledc_pwm_set_duty(ledc_config_t *ledc_config, uint32_t duty);
uint32_t ledc_duty_pow(uint32_t duty,uint8_t m,uint8_t n);



#endif // LEDC_H