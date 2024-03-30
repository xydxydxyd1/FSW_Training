/*
 * timers.h
 */

#ifndef REALOP1_TIMERS_H_
#define REALOP1_TIMERS_H_

#include "stm32l476xx.h"
#include <globals.h>

//-----------------------------------------------------------------------------

/**
 * Initializes the Heartbeat LED Timer (the Systck). 
 * Configures it to tick every ms.
*/
void systick_init();


#endif	// REALOP1_TIMERS_H_
