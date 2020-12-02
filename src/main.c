/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "main.h"
#include "heartbeat.h"
#include "pwm_led.h"
#include "fat_fs.h"

LOG_MODULE_REGISTER(main);

void main(void)
{
	printk("Nucleo Project\n");
	
	heartbeat_setup();
	pwm_led_setup();
	sd_card_init();
	
	while (1)
	{
		heartbeat_exec();
		//pwm_led_exec();
	}
}
