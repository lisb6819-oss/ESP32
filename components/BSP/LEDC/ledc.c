#include "ledc.h"

uint32_t ledc_duty_pow(uint32_t duty,uint8_t m,uint8_t n)
{
	uint32_t result = 1;
	for (uint8_t i = 0; i < n; i++)
	{
		result *= m;
	}
	return (duty * (result-1))/100;
}

void ledc_init(ledc_config_t *ledc_config)
{
	ledc_config->duty = ledc_duty_pow(ledc_config->duty, 2, ledc_config->duty_resolution);

	ledc_timer_config_t ledc_timer = {
		.speed_mode = LEDC_LOW_SPEED_MODE,
		.timer_num = ledc_config->timer_num,
		.duty_resolution = ledc_config->duty_resolution,
		.freq_hz = ledc_config->freq_hz,
		.clk_cfg = ledc_config->clk_cfg
	};
	ledc_timer_config(&ledc_timer);

	ledc_channel_config_t ledc_channel = {
		.speed_mode = LEDC_LOW_SPEED_MODE,
		.channel = ledc_config->channel,
		.timer_sel = ledc_config->timer_num,
		.intr_type = LEDC_INTR_DISABLE,
		.gpio_num = ledc_config->gpio_num,
		.duty = ledc_config->duty,
		.hpoint = 0,
	};
	ledc_channel_config(&ledc_channel);
}

void ledc_pwm_set_duty(ledc_config_t *ledc_config, uint32_t duty)
{
	duty = ledc_duty_pow(duty, 2, ledc_config->duty_resolution);
	ledc_set_duty_with_hpoint(LEDC_LOW_SPEED_MODE, ledc_config->channel, duty, ledc_config->duty);
	ledc_update_duty(LEDC_LOW_SPEED_MODE, ledc_config->channel);
}