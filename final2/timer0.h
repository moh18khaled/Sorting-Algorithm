/*
 * timer0.h
 *
 * Created: 5/9/2024 1:59:48 PM
 *  Author: mohamed khaled
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

//#define NUMBER_OF_OVERFLOWS 30  // F_CPU = 8000000   

#define NUMBER_OF_OVERFLOWS 61  // F_CPU = 16000000


/*

tick = (1024/16000000)*256

tick = 0.016384 sec 

NUMBER_OF_OVERFLOWS = 1/tick

*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Math.h"
#define CS00 0
#define CS02 2
#define FOC0 7
#define I_BIT 7


void timer0_init();


#endif /* TIMER0_H_ */