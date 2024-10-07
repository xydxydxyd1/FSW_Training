#ifndef GPIO_TESTER_H
#define GPIO_TESTER_H

#include "stm32l476xx.h"
#include <globals.h>

// ----- Options for gpio configurations

// options for GPIO Value
enum GPIO_VALUE {
    GPIO_LOW  = 0,
    GPIO_HIGH = 1
};
typedef enum GPIO_VALUE GPIO_VALUE;

// options for GPIO Mode
enum GPIO_MODE {
    GPIO_MODE_INPUT  = 0,
    GPIO_MODE_OUTPUT = 1,
    GPIO_MODE_AF     = 2,
    GPIO_MODE_ANALOG = 3,

    GPIO_DEFAULT_MODE = GPIO_MODE_INPUT
};
typedef enum GPIO_MODE GPIO_MODE;

// options for GPIO Open Drain
typedef enum GPIO_OPEN_DRAIN {
    GPIO_PP  = 0,	// Push Pull
    GPIO_OD = 1,	// Open Drain

    GPIO_DEFAULT_OPEN_DRAIN = GPIO_PP
} GPIO_OPEN_DRAIN;

// options for GPIO Speed
enum GPIO_SPEED {
    GPIO_LOW_SPEED     = 0,
    GPIO_MED_SPEED     = 1,
    GPIO_HI_SPEED      = 2,
    GPIO_VERY_HI_SPEED = 3,

    GPIO_DEFAULT_SPEED = GPIO_MED_SPEED
};
typedef enum GPIO_SPEED GPIO_SPEED;

// options for GPIO Pull Mode
enum GPIO_PULL {
    GPIO_NO_PULL   = 0,
    GPIO_PULL_UP   = 1,
    GPIO_PULL_DOWN = 2,

    GPIO_DEFAULT_PULL = GPIO_NO_PULL
};
typedef enum GPIO_PULL GPIO_PULL;

// ----- GPIO Configurations

/**
 * Set the pin to low. 
 * Usage: _gpio_low(GPIOA, 1);  <-- That will set pin 1 of GPIOA to low
 * 
 * 
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
*/
void _gpio_low(GPIO_TypeDef *port, int pin);

/**
 * Set the pin to high. 
 * Usage: _gpio_high(GPIOA, 1);  <-- That will set pin 1 of GPIOA to high
 * 
 * 
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
*/
void _gpio_high(GPIO_TypeDef *port, int pin);

/**
 * Set the pin to a value. 
 * Usage: _gpio_set(GPIOA, 1, GPIO_HIGH);  <-- That will set pin 1 of GPIOA to high
 * 
 * 
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
 * @param value GPIO_HIGH or GPIO_LOW
*/
void _gpio_set(GPIO_TypeDef *port, int pin, GPIO_VALUE value);

/**
 * Configure the mode of the pin. 
 * Usage: _gpio_configureMode(GPIOA, 1, GPIO_MODE_OUTPUT, GPIO_PUSH_PULL, GPIO_MED_SPEED, GPIO_NO_PULL);  <-- That will set pin 1 of GPIOA to output mode, push-pull, medium speed, no pull
 * 
 * 
 * @param port GPIO port, ex. GPIOA
 * @param pin GPIO pin, ex. 1
 * @param mode GPIO_MODE_INPUT, GPIO_MODE_OUTPUT, GPIO_MODE_AF, GPIO_MODE_ANALOG
 * @param open_drain GPIO_PUSH_PULL, GPIO_OPEN_DRAIN
 * @param speed GPIO_LOW_SPEED, GPIO_MED_SPEED, GPIO_HI_SPEED, GPIO_VERY_HI_SPEED
 * @param pull GPIO_NO_PULL, GPIO_PULL_UP, GPIO_PULL_DOWN
*/
void _gpio_configureMode(GPIO_TypeDef *port, int pin, GPIO_MODE mode, GPIO_OPEN_DRAIN open_drain, GPIO_SPEED speed, GPIO_PULL pull);

#endif // GPIO_TESTER_H
