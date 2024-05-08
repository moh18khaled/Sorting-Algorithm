/*
 * LCD.c
 *
 * Created: 3/21/2024 1:25:02 AM
 *  Author: mohamed khaled
 */ 

#include <util/delay.h>
#include "LCD.h"
#include "Math.h"
#include "pins.h"



void LCD_init(void){
	
		SET_BIT(DDRA,3);
		SET_BIT(DDRA,2);
		
		SET_BIT(DDRB,0);
		SET_BIT(DDRB,1);
		SET_BIT(DDRB,2);
		SET_BIT(DDRB,4);
	
		_delay_ms(15);
	
		LCD_command(0x06);
		LCD_command(0x02);
		LCD_command(0x28);
		LCD_command(0x0c);
		LCD_command(0x01);
		LCD_command(0x80);
	
}
void LCD_command(unsigned char cmd){
	
	CLR_BIT(PORTA,3);
	PORTB&=0b11101000;
	unsigned char high=((cmd&0xf0)>>4);
	unsigned char temp=(((high&0b00001000)<<1) | (high&0b00000111));
	PORTB|=temp;
	
	CLR_BIT(PORTA,2);
	SET_BIT(PORTA,2);
	_delay_ms(1);
	CLR_BIT(PORTA,2);
	
	PORTB&=0b11101000;
	unsigned char low=((cmd&0x0f));
	unsigned char temp2=(((low&0b00001000)<<1) | (low&0b00000111));
	PORTB|=temp2;
	
	CLR_BIT(PORTA,2);
	SET_BIT(PORTA,2);
	_delay_ms(1);
	CLR_BIT(PORTA,2);
	
	_delay_ms(5);
	
}
void LCD_WriteChar(unsigned char chr) {
	
	SET_BIT(PORTA, p3);
	PORTB &= 0b11101000;
	unsigned char high = ((chr & 0xf0) >> 4);
	unsigned char temp = (((high & 0b00001000) << 1) | (high & 0b00000111));
	PORTB |= temp;

	CLR_BIT(PORTA, p2);
	SET_BIT(PORTA, p2);
	_delay_ms(1);
	CLR_BIT(PORTA, p2);

	PORTB &= 0b11101000;
	unsigned char low = ((chr & 0x0f));
	unsigned char temp2 = (((low & 0b00001000) << 1) | (low & 0b00000111));
	PORTB |= temp2;

	CLR_BIT(PORTA, p2);
	SET_BIT(PORTA, p2);
	_delay_ms(1);
	CLR_BIT(PORTA, p2);
	
	
}


void LCD_string(unsigned char* str){
	for(int i=0;str[i]!='\0';i++){
		LCD_WriteChar(str[i]);
	}
}

void LCD_Number(int number , int *c) {
		LCD_WriteChar(' ');
		(*c)++;
	// Display each digit of the number, ensuring all four digits are shown
	if (number < 1000) {
		LCD_WriteChar(' '); // Display a space as a placeholder for thousands digit
		(*c)++;
	}
	if (number < 100) {
		LCD_WriteChar(' '); // Display a space as a placeholder for hundreds digit
		(*c)++;
	}
	if (number < 10) {
		LCD_WriteChar(' '); // Display a space as a placeholder for tens digit
		(*c)++;
	}
	if (number >= 1000) {
		LCD_WriteChar(number / 1000 % 10 + '0'); // Display thousands digit
		(*c)++;
	}
	if (number >= 100) {
		LCD_WriteChar(number / 100 % 10 + '0'); // Display hundreds digit
		(*c)++;
	}
	if (number >= 10) {
		LCD_WriteChar(number / 10 % 10 + '0'); // Display tens digit
		(*c)++;
	}
	LCD_WriteChar(number % 10 + '0'); // Display units digit
	(*c)++;
	
}

void LCD_clear(void){
	LCD_command(0x01);
}


