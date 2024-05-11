/*
 * SevSeg.h
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 

#include "SevSeg.h"

void seven_seg_init(){
	DDRB|=0x17;
}


void display_on_seven_seg(int num,int pin){
	SET_BIT(DDRA,p2);
	SET_BIT(DDRA,p3);
	SET_BIT(DDRB,p5);
	SET_BIT(DDRB,p6);
	
	
	
	SET_BIT(PORTA,p2);
	SET_BIT(PORTA,p3);
	SET_BIT(PORTB,p5);
	SET_BIT(PORTB,p6);

	PORTB&=~0b00010111;
	const arr[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x10,0x11};
	PORTB|=arr[num];
	
//	CLR_BIT(PORTA,2);//2
//	CLR_BIT(PORTA,3);//1 first 7-seg from the right
//	CLR_BIT(PORTB,5);//3
//	CLR_BIT(PORTB,6);//4

if(pin<3){
	if(pin == 1)
		pin+=2;
		CLR_BIT(PORTA,pin);
		_delay_ms(1);
		SET_BIT(PORTA,pin);
	
}
else{
	pin+=2;
	CLR_BIT(PORTB,pin);
		_delay_ms(1);
	SET_BIT(PORTB,pin);
}

}
