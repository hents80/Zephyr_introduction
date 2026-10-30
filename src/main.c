#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h> // Add these per necessity 

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(exampleled), gpios); // LED definition

int main(void)
{
    if (!gpio_is_ready_dt(&led)) return 0; // Check if it initialized correctly

    gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE); // Configure the gpio and set the value to 0

    while (1) {
        gpio_pin_toggle_dt(&led); // Simple toggle command
        k_msleep(500); // sleep for 500 ms
    }
    return 0;
}


