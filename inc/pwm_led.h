#ifndef PWM_LED_H
#define PWM_LED_H

#include <drivers/gpio.h>
#include <drivers/pwm.h>
#include <sys/printk.h>

#define PWM_LED0_NODE	DT_ALIAS(pwm_led0)

#if DT_NODE_HAS_STATUS(PWM_LED0_NODE, okay)
#define PWM_LABEL	DT_PWMS_LABEL(PWM_LED0_NODE)
#define PWM_CHANNEL	DT_PWMS_CHANNEL(PWM_LED0_NODE)
#define PWM_FLAGS	DT_PWMS_FLAGS(PWM_LED0_NODE)
#else
#error "Unsupported board: pwm-led0 devicetree alias is not defined"
#define PWM_LABEL	""
#define PWM_CHANNEL	0
#define PWM_FLAGS	0
#endif

#define MIN_PERIOD_USEC	(USEC_PER_SEC / 64U)
#define MAX_PERIOD_USEC	USEC_PER_SEC

extern const struct device *pwm;
int pwm_led_setup(void);
int pwm_led_exec(void);


#endif