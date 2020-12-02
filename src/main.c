/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "main.h"
#include "heartbeat.h"
#include "pwm_led.h"


void main(void)
{
	heartbeat_setup();
	pwm_led_setup();

	printk("Nucleo Project\n");
	
	

	while (1)
	{
		heartbeat_exec();
		pwm_led_exec();
	}
}
