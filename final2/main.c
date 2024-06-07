/*
 * main.h
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD.h"
#include "SevSeg.h"
#include "KeyPad.h"
#include "numbers.h"
#include "register.h"
#include "Math.h"

int main(void)
{
	const int fixed_size = 20;
	int arr[fixed_size],num=-1,size=0;
	keypad_init();
	LCD_init();

    while (1){

		unsigned char ans=keypad_get_value();

		if(ans=='='){
			if(num!=-1){
				LCD_clear();
				arr[size++]=num,num=-1;
			}
		}
		else if(ans=='e'){
			if(num==-1){
			sort(arr,size);
			LCD_Number(arr,size);
			_delay_ms(1000);
			separate_num(arr,size);			
			LCD_init();
			num=-1,size=0;
			}
		}
		else if(ans!=inva){
			LCD_WriteChar(ans);
			build_num(&num,ans);
		}
	}
}

