/*
 * LCD.c
 *
 * Created: 3/21/2024 1:25:02 AM
 *  Author: mohamed khaled
 */ 

#include <util/delay.h>
#define F_CPU 16000000L
#include "LCD.h"
#include "Math.h"

void LCD_init(void){
	SET_BIT(DDRA,3);
	SET_BIT(DDRA,2);
	
	SET_BIT(DDRB,0);
	SET_BIT(DDRB,1);
	SET_BIT(DDRB,2);
	SET_BIT(DDRB,4);
	
	_delay_ms(15);
	
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
void LCD_WriteChar(unsigned char chr){
	
	SET_BIT(PORTA,3);
	PORTB&=0b11101000;
	unsigned char high=((chr&0xf0)>>4);
	unsigned char temp=(((high&0b00001000)<<1) | (high&0b00000111));
	PORTB|=temp;
	
	CLR_BIT(PORTA,2);
	SET_BIT(PORTA,2);
	_delay_ms(1);
	CLR_BIT(PORTA,2);
	
	PORTB&=0b11101000;
	unsigned char low=((chr&0x0f));
	unsigned char temp2=(((low&0b00001000)<<1) | (low&0b00000111));
	PORTB|=temp2;
	
	CLR_BIT(PORTA,2);
	SET_BIT(PORTA,2);
	_delay_ms(1);
	CLR_BIT(PORTA,2);
	
	_delay_ms(5);
	
}
void LCD_string(unsigned char* str){
	for(int i=0;str[i]!='\0';i++){
		LCD_WriteChar(str[i]);
	}
}
void LCD_clear(void){
	LCD_command(0X01);
	
}