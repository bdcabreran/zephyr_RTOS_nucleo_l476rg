#include "heartbeat.h"
#include <logging/log.h>

LOG_MODULE_REGISTER(heartbeat);

const struct device *dev;

int heartbeat_setup(void)
{
	LOG_INF("Initializing Hearbeat...\r\n");

	int ret;
	dev = device_get_binding(LED0);
	if (dev == NULL) {
		return 0;
	}
	ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
	if (ret < 0) {
		return 0;
	}
}

int heartbeat_exec(void)
{
	static bool led_is_on = true;
	gpio_pin_set(dev, PIN, (int)led_is_on);
	led_is_on = !led_is_on;
	k_msleep(SLEEP_TIME_MS);
}