#include "gpio_.h"

void _gpio_low(GPIO_TypeDef *port, int pin) {
	/**
	 * Turning a bit low based on 8.5.7 of the STM32L4 Reference Manual
	 */

    if (pin > 15) {     // STM32L4 only has 16 pins per port
        return;
    }

    port->BSRR &= ~(1 << pin);      // Reset the SET bit
    port->BSRR |= 1 << (pin + 16);  // Set the RESET bit
}

void _gpio_high(GPIO_TypeDef *port, int pin) {
	/**
	 * same as gpio_low, but turns the value high
	 */

    if (pin > 15) {     // STM32L4 only has 16 pins per port
        return;
    }

    port->BSRR |= (1 << pin);   // Set the SET bit
}

void _gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value) {
    if (value == GPIO_HIGH) {
        _gpio_high(port, pin);
    } else if (value == GPIO_LOW) {
        _gpio_low(port, pin);
    }
}

void _gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_MODE mode, GPIO_OPEN_DRAIN open_drain, GPIO_SPEED speed, GPIO_PULL pull) {
    /*
	 * This will require setting a few registers
	 * See if you can identify which registers, and why.
	 * The process is the same though, bitwise operations on the registers
	 */



}