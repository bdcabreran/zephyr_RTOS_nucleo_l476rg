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
	heartbeat_setup();
	pwm_led_setup();
	printk("Nucleo Project\n");

	LOG_MODULE_DECLARE(main, LOG_LEVEL_DBG);
	LOG_DBG("This is a debug message from Logger API\r\n");
	LOG_ERR("This is a error message from Logger API\r\n");
	LOG_INF("This is a info  message from Logger API\r\n");

	while (1)
	{
		heartbeat_exec();
		//pwm_led_exec();
	}
}
