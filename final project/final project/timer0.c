/*
 * timer0.c
 *
 * Created: 5/9/2024 2:09:01 PM
 *  Author: mohamed khaled
 */ 


#include "timer0.h"
#include "register.h"



void timer0_init(){
	TCNT0=0;
	SET_BIT(TIMSK,TOIE0);
	
	TCCR0= (1<<FOC0)|(1<<CS02)|(1<<CS00);
	
	SET_BIT(SREG,I_BIT);

}
