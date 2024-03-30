#ifndef GPIO_TESTER_H
#define GPIO_TESTER_H

#include "stm32l476xx.h"
#include <globals.h>

// ----- Macros for gpio configurations

// options for GPIO Value
#define GPIO_LOW    false
#define GPIO_HIGH   true

// options for GPIO Mode
#define GPIO_DIGITAL_IN		0
#define GPIO_DIGITAL_OUT	1
#define GPIO_AF 			2
#define GPIO_ANALOG_IN 		3

// options for GPIO Open Drain
#define GPIO_PUSH_PULL 		0
#define GPIO_OPEN_DRAIN		1

// options for GPIO Speed
#define GPIO_LOW_SPEED		0
#define GPIO_MED_SPEED		1
#define GPIO_HI_SPEED		2
#define GPIO_VERY_HI_SPEED	3

// options for GPIO Pull Mode
#define GPIO_NO_PULL		0
#define GPIO_PULL_UP		1
#define GPIO_PULL_DOWN		2

// ----- GPIO Configurations

void gpio_low(GPIO_TypeDef *port, int pin);
void gpio_high(GPIO_TypeDef *port, int pin);
void gpio_set(GPIO_TypeDef *port, int pin, bool value);
void gpio_configureMode(GPIO_TypeDef * port, int pin, int mode, int open_drain, int speed, int pull);
void gpio_alternateFunction(GPIO_TypeDef * port, uint8_t pin, uint8_t afn);

#endif // GPIO_TESTER_H
