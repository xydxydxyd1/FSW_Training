/*
 * platform_init.h

 * 	- May 22, 2023
 * 		Author			: Darsh
 * 		Contributors	: Parteek
 * 		Log				: Backup Power, RTC Init
 *
 * 	- May 11, 2023
 * 		Author	: Darsh
 * 		Log		: Created the platform_init() function
 */

#ifndef REALOP1_PLATFORM_INIT_H
#define REALOP1_PLATFORM_INIT_H

#include <globals.h>

#include <core_config.h>
#include <Timers/timers.h>
#include <Buttons/buttons.h>
#include <SPI/spi.h>
#include <LED/led.h>
#include <UART/uart.h>
#include <print_scan.h>

/**
 * Configures the system's various features,
 * such as clocks, protocol hardware, and more.
 *
 * @param   None
 * @returns None
 */
void init_platform() {
	init_coreClocks();
	PWR->CR2 |= PWR_CR2_IOSV;

	led_init();
	buttons_init();

	printer_init();
	systick_init();
}

#endif // REALOP1_PLATFORM_INIT_H
