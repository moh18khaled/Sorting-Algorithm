/*
 * KeyPad.h
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 

#include "KeyPad.h"

unsigned char arr[4][4]=
{
{'7','8','9','/'},	
{'4','5','6','*'},
{'1','2','3','-'},
{'0','0','=','+'}	
};

void keypad_init(){
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	
	CLR_BIT(DDRD,7);
	CLR_BIT(DDRD,6);
	CLR_BIT(DDRD,5);
	CLR_BIT(DDRD,3);
	
	SET_BIT(PORTD,7);
	SET_BIT(PORTD,6);
	SET_BIT(PORTD,5);
	SET_BIT(PORTD,3);
}

unsigned char keypad_get_value(){
	unsigned char ans=inva;
	for(int row=5;row>=2;row--){
		PORTC|=0b00111100;
		CLR_BIT(PORTC,row);
		for(int col=7;col>=3;col--){
		if(col==4)col--;
		if(GET_BIT(PIND,col)==0){
			_delay_ms(100);
			if(GET_BIT(PIND,col)==0){
				if(col==3)
					ans=arr[5-row][7-col-1];
				else
					ans=arr[5-row][7-col];
				}
			}
		}
	}
	return ans;
}