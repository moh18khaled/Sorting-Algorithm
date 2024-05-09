/*
 * main.h
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 


#include "register.h"
#include "Math.h"
#include "LCD.h"
#include "SevSeg.h"
#include "KeyPad.h"
#include "pins.h"
#include "numbers.h"

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

			//LCD code
			arr[size++]=num,num=-1;
			}
		}
		else if(ans=='e'){
			if(num==-1){
			sort(arr,size);
			//LCD code
			LCD_Number(arr,size);
			
			_delay_ms(1000);
			seven_seg_init();
			separate_num(arr,size);
			num=-1,size=0,LCD_clear();
			}
		}
		else if(ans!=inva){
			//LCD code
			
			LCD_WriteChar(ans);
			
			build_num(&num,ans);
		}
	}
}

