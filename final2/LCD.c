/*
 * LCD.c
 *
 * Created: 3/21/2024 1:25:02 AM
 *  Author: mohamed khaled
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD.h"
#include "Math.h"
#include "pins.h"
#include "register.h"


#define LCD_data_DDR DDRB
#define LCD_command_DDR DDRA

#define LCD_data_PORT PORTB
#define LCD_command_PORT PORTA

#define RS 3
#define EN 2



int len_num(int num){
	int counter=0;
	while(num>0){
		num/=10;
		counter++;
	}
	return counter;
}

int cursor_position = 0;



void LCD_init(void){
	
	SET_BIT(LCD_command_DDR,RS);
	SET_BIT(LCD_command_DDR,EN);
	
	SET_BIT(LCD_data_DDR,p0);
	SET_BIT(LCD_data_DDR,p1);
	SET_BIT(LCD_data_DDR,p2);
	SET_BIT(LCD_data_DDR,p4);

	
	_delay_ms(15);
	
	LCD_command(0x06);
	LCD_command(0x02);
	LCD_command(0x28);
	LCD_command(0x0c);
	LCD_command(0x01);
	LCD_command(0x80);
	
}

void LCD_command(unsigned char cmd){
	
	CLR_BIT(LCD_command_PORT,RS);
	LCD_data_PORT&=0b11101000;
	unsigned char high=((cmd&0xf0)>>4);
	unsigned char temp=(((high&0b00001000)<<1) | (high&0b00000111));
	LCD_data_PORT|=temp;
	
	CLR_BIT(LCD_command_PORT,EN);
	SET_BIT(LCD_command_PORT,EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT,EN);
	
	LCD_data_PORT&=0b11101000;
	unsigned char low=((cmd&0x0f));
	unsigned char temp2=(((low&0b00001000)<<1) | (low&0b00000111));
	LCD_data_PORT|=temp2;
	
	CLR_BIT(LCD_command_PORT,EN);
	SET_BIT(LCD_command_PORT,EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT,EN);
	
	_delay_ms(5);
}
void LCD_WriteChar(unsigned char chr) {
	
	SET_BIT(LCD_command_PORT, RS);
	LCD_data_PORT &= 0b11101000;
	unsigned char high = ((chr & 0xf0) >> 4);
	unsigned char temp = (((high & 0b00001000) << 1) | (high & 0b00000111));
	LCD_data_PORT |= temp;

	CLR_BIT(LCD_command_PORT, EN);
	SET_BIT(LCD_command_PORT, EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT, EN);

	LCD_data_PORT &= 0b11101000;
	unsigned char low = ((chr & 0x0f));
	unsigned char temp2 = (((low & 0b00001000) << 1) | (low & 0b00000111));
	LCD_data_PORT |= temp2;

	CLR_BIT(LCD_command_PORT, EN);
	SET_BIT(LCD_command_PORT, EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT, EN);
	_delay_ms(5);

	
}


void LCD_string(unsigned char* str){
	for(int i=0;str[i]!='\0';i++){
		LCD_WriteChar(str[i]);
	}
}

void LCD_Number(int *arr ,const int size) {
	
	
	for (int i = 0 ; i < size;i++)
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
		
		LCD_WriteChar(' ');
		cursor_position++;
		
		for (int divisor = 1000; divisor > 1; divisor /= 10) {
			if (divisor > arr[i]){
			LCD_WriteChar(' ');
			cursor_position++;
			}
			else {
				LCD_WriteChar(arr[i] / divisor % 10 + '0');
				cursor_position++;
			}
		}
		LCD_WriteChar(arr[i] % 10 + '0');
		cursor_position++;
		LCD_WriteChar(' ');
		_delay_ms(1000);
	}
	
}

void LCD_clear(void){
	//PORTB &= 0b11101000;
	LCD_command(0x01);
	LCD_data_PORT &=  0b11101000;
}