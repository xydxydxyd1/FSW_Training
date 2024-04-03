#include "gpio_.h"

void gpio_low(GPIO_TypeDef *port, int pin) {
	/*
	 * Use bitwise operations on registers in the GPIO `port`
	 * to turn a pin's value low.
	 * Hint: BSRR
	 */

}

void gpio_high(GPIO_TypeDef *port, int pin) {
	/*
	 * same as gpio_low, but turns the value high
	 */

}

void gpio_set(GPIO_TypeDef *port, int pin, bool value) {
	/*
	 * A generalized function that uses gpio_high() or gpio_low()
	 * depending on whether `value` is HIGH or LOW
	 */

}

void gpio_configureMode(GPIO_TypeDef * port, int pin, int mode, int open_drain, int speed, int pull) {
	/*
	 * This will require setting a few registers
	 * See if you can identify which registers, and why.
	 * The process is the same though, bitwise operations on the registers
	 */

}

void gpio_alternateFunction(GPIO_TypeDef * port, uint8_t pin, uint8_t afn) {
	/*
	 * Use the gpio_configureMode to get GPIO to Alternate Function.
	 * Then set the Alternate Function registers to the right alternate function
	 */

}
