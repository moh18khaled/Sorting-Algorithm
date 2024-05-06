/*
 * SevSeg.h
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 

#include "SevSeg.h"

void seven_seg_init(){
	DDRA=0xff;
	DDRB=0xff;
}
void display(int num){
	int i=0;
	while (num>0)
	{
		if(num&1)
		SET_BIT(PORTB,i);
		else
		CLR_BIT(PORTB,i);
		num>>=1;
		if(i==2)
		i=4;
		else
		i++;
	}
}
void display_on_seven_seg(int num){
	const arr[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
	PORTA=arr[num%10];
}