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
	set_bit(DDRC,2);
	set_bit(DDRC,3);
	set_bit(DDRC,4);
	set_bit(DDRC,5);
	
	clr_bit(DDRD,7);
	clr_bit(DDRD,6);
	clr_bit(DDRD,5);
	clr_bit(DDRD,3);
	
	set_bit(PORTD,7);
	set_bit(PORTD,6);
	set_bit(PORTD,5);
	set_bit(PORTD,3);
}

unsigned char keypad_get_value(){
	unsigned char ans=inva;
	for(int row=5;row>=2;row--){
		PORTC|=0b00111100;
		clr_bit(PORTC,row);
		for(int col=7;col>=3;col--){
		if(col==4)col--;
		if(get_bit(PIND,col)==0){
			_delay_ms(100);
			if(get_bit(PIND,col)==0){
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