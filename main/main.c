#include <stdio.h>
#include "ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void app_main(void)
{
	uint8_t dir = 1;
	uint16_t ledpwmval = 0;

	ledc_config_t *ledc_config = malloc(sizeof(ledc_config_t));

	ledc_config->clk_cfg = LEDC_AUTO_CLK;
	ledc_config->timer_num = LEDC_PWN_TIMER;
	ledc_config->freq_hz = 1000;
	ledc_config->duty_resolution = LEDC_TIMER_14_BIT;
	ledc_config->channel = LEDC_PWN_CH0_CHANNEL;
	ledc_config->duty = 0;
	ledc_config->gpio_num = LEDC_PWN_CH0_GPIO;


	ledc_init(ledc_config);

	while (1)
	{
		vTaskDelay(20);
		if(dir)
		{
			ledpwmval++;
			if(ledpwmval >= 100)
			{
				dir = 0;
			}
		}
		else
		{
			ledpwmval--;
			if(ledpwmval == 0)
			{
				dir = 1;
			}
		}
		ledc_pwm_set_duty(ledc_config, ledpwmval);

	}

}
