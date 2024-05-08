/*
 * Project.c
 *
 * Created: 5/6/2024 5:21:34 PM
 * Author : 20103
 */ 

#include <avr/io.h>
#include "LCD.h"

#define F_CPU 8000000UL
#include <util/delay.h>


int len_num(int x){
	int c=0;
	while(x>0){
		x=x/10;
		c++;
	}
    return c;
}


void sortNumbers(int arr[], int n) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


int main(void)
{
	int cursor_position = 0;

	LCD_init();

	int arr[] = {1000,2000,1189,1804,1183,8881,8401,1881,9829,5888,1880,2588,9999};
		
	int n = sizeof(arr)/sizeof(arr[0]);
	
	sortNumbers(arr, n);	
	
	for (int i = 0 ; i < n ;i++)
	{
		int l=len_num(arr[i]);
			
		if(cursor_position <= 18 && l > 18-cursor_position){
		LCD_WriteChar(' ');
		}
		if(l > 30-cursor_position ){
			LCD_clear();
			_delay_ms(2);
			cursor_position = 0; 
			LCD_command(0x80);
			}
			
			LCD_Number(arr[i], &cursor_position);
			LCD_WriteChar(' ');
			_delay_ms(2000);
		}
		
	while(1){
		
	}
}

