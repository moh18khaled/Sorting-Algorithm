/*
 * KeyPad.c
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 

#include "KeyPad.h"
#include "pins.h"


unsigned char arr[4][4]=
{
{'7','8','9','/'},	
{'4','5','6','*'},
{'1','2','3','-'},
{'e','0','=','+'}	
};

void keypad_init(){
	SET_BIT(DDRC,p2);
	SET_BIT(DDRC,p3);
	SET_BIT(DDRC,p4);
	SET_BIT(DDRC,p5);
	
	CLR_BIT(DDRD,p7);
	CLR_BIT(DDRD,p6);
	CLR_BIT(DDRD,p5);
	CLR_BIT(DDRD,p3);
	
	SET_BIT(PORTD,p7);
	SET_BIT(PORTD,p6);
	SET_BIT(PORTD,p5);
	SET_BIT(PORTD,p3);
}


unsigned char keypad_get_value(){
	
	unsigned char ans=inva;
	for(int row=5;row>=2;row--){
		PORTC|=0b00111100;
		CLR_BIT(PORTC,row);
		for(int col=7;col>=3;col--){
		if(col==4)col--;
		if(GET_BIT(PIND,col)==0){
			_delay_ms(120);
			if(GET_BIT(PIND,col)==0){
				if(col!=3)
					ans=arr[5-row][7-col];
				}
			}
		}
	}
	return ans;
}