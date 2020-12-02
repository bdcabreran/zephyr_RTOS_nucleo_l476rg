#include "pwm_led.h"

const struct device *pwm;
static uint32_t max_period;
static uint32_t period;
static uint8_t dir = 0U;

int pwm_led_setup(void)
{
	printk("PWM-based blinky Setup\n");

	pwm = device_get_binding(PWM_LABEL);
	if (!pwm) {
		printk("Error: didn't find %s device\n", PWM_LABEL);
		return 0;
	}

    /*
	 * In case the default MAX_PERIOD_USEC value cannot be set for
	 * some PWM hardware, decrease its value until it can.
	 *
	 * Keep its value at least MIN_PERIOD_USEC * 4 to make sure
	 * the sample changes frequency at least once.
	 */
	printk("Calibrating for device %s channel %d...\n", PWM_LABEL, PWM_CHANNEL);
	max_period = MAX_PERIOD_USEC;
	
    while (pwm_pin_set_usec(pwm, PWM_CHANNEL,
				max_period, max_period / 2U, PWM_FLAGS)) {
		max_period /= 2U;
		if (max_period < (4U * MIN_PERIOD_USEC)) {
			printk("Error: PWM device %s "
			       "does not support a period at least %u\n",
			       PWM_LABEL, 4U * MIN_PERIOD_USEC);
			return;
		}
	}

	printk("Done calibrating; maximum/minimum periods %u/%u usec\n",
	       max_period, MIN_PERIOD_USEC);

	period = max_period;
}

int pwm_led_exec(void)
{
    int ret;

    ret = pwm_pin_set_usec(pwm, PWM_CHANNEL, period, period / 2U, PWM_FLAGS);

    if (ret)
    {
        printk("Error %d: failed to set pulse width\n", ret);
        return 0;
    }

    period = dir ? (period * 2U) : (period / 2U);
    if (period > max_period)
    {
        period = max_period / 2U;
        dir = 0U;
    }
    else if (period < MIN_PERIOD_USEC)
    {
        period = MIN_PERIOD_USEC * 2U;
        dir = 1U;
    }

    k_sleep(K_SECONDS(4U));
}