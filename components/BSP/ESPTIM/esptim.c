#include "esptim.h"

void esptim_init(uint64_t tps)
{
	// Initialize the ESP timer
	esp_timer_handle_t timer_handle;

	esp_timer_create_args_t timer_args = {
		.callback = esptim_callback,
		.arg = NULL,
	};

	esp_timer_create(&timer_args, &timer_handle);
	esp_timer_start_periodic(timer_handle, tps); 
}

void esptim_callback(void* arg)
{
	// Toggle the LED state
	LED_TOGGLE();
}