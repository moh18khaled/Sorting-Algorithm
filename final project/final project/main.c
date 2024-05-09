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
int arr[20],num=-1,size=0;

keypad_init();
LCD_init();

    while (1){

		unsigned char ans=keypad_get_value();

		if(ans=='='){
			if(num!=-1){
			//LCD code
			arr[size++]=num,num=-1;
			}
		}
		else if(ans=='e'){
			sort(arr,size);
			//LCD code
			separate_num(arr,size);
			break;
		}
		else if(ans!=inva){
			//LCD code
			build_num(&num,ans);
		}
	}
}

