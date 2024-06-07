/*
 * KeyPad.c
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "KeyPad.h"
#include "pins.h"
#include "Math.h"
#include "register.h"

unsigned char arr[4][4]=
{
{'7','8','9','/'},	
{'4','5','6','*'},
{'1','2','3','-'},
{'e','0','=','+'}	
};

void keypad_init(){
	SET_BIT(ROW_DDR,p2);
	SET_BIT(ROW_DDR,p3);
	SET_BIT(ROW_DDR,p4);
	SET_BIT(ROW_DDR,p5);
	
	CLR_BIT(COL_DDR,p7);
	CLR_BIT(COL_DDR,p6);
	CLR_BIT(COL_DDR,p5);
	CLR_BIT(COL_DDR,p3);
	
	SET_BIT(COL_PORT,p7);
	SET_BIT(COL_PORT,p6);
	SET_BIT(COL_PORT,p5);
	SET_BIT(COL_PORT,p3);
}


unsigned char keypad_get_value(){
	
	unsigned char ans=inva;
	for(int row=5;row>=2;row--){
		ROW_PORT|=0b00111100;
		CLR_BIT(ROW_PORT,row);
		for(int col=7;col>=3;col--){
		if(col==4)col--;
		if(GET_BIT(COL_PIN,col)==0){
			_delay_ms(120);
			if(GET_BIT(COL_PIN,col)==0){
				if(col!=3)
					ans=arr[5-row][7-col];
				}
			}
		}
	}
	return ans;
}