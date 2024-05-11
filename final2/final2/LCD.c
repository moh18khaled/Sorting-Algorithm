/*
 * LCD.c
 *
 * Created: 3/21/2024 1:25:02 AM
 *  Author: mohamed khaled
 */ 


#include "LCD.h"
#include "Math.h"
#include "pins.h"



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
	
	SET_BIT(DDRA,p3);
	SET_BIT(DDRA,p2);
	
	SET_BIT(DDRB,p0);
	SET_BIT(DDRB,p1);
	SET_BIT(DDRB,p2);
	SET_BIT(DDRB,p4);
	
	_delay_ms(15);
	
	LCD_command(0x06);
	LCD_command(0x02);
	LCD_command(0x28);
	LCD_command(0x0c);
	LCD_command(0x01);
	LCD_command(0x80);
	
}

void LCD_command(unsigned char cmd){
	
	CLR_BIT(PORTA,p3);
	PORTB&=0b11101000;
	unsigned char high=((cmd&0xf0)>>4);
	unsigned char temp=(((high&0b00001000)<<1) | (high&0b00000111));
	PORTB|=temp;
	
	CLR_BIT(PORTA,p2);
	SET_BIT(PORTA,p2);
	_delay_ms(1);
	CLR_BIT(PORTA,p2);
	
	PORTB&=0b11101000;
	unsigned char low=((cmd&0x0f));
	unsigned char temp2=(((low&0b00001000)<<1) | (low&0b00000111));
	PORTB|=temp2;
	
	CLR_BIT(PORTA,p2);
	SET_BIT(PORTA,p2);
	_delay_ms(1);
	CLR_BIT(PORTA,p2);
	
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
		
		// Display each digit of the number, ensuring all four digits are shown
		if (arr[i] < 1000) {
			LCD_WriteChar(' '); // Display a space as a placeholder for thousands digit
			cursor_position++;
		}
		if (arr[i] < 100) {
			LCD_WriteChar(' '); // Display a space as a placeholder for hundreds digit
			cursor_position++;
		}
		if (arr[i] < 10) {
			LCD_WriteChar(' '); // Display a space as a placeholder for tens digit
			cursor_position++;
		}
		if (arr[i] >= 1000) {
			LCD_WriteChar(arr[i] / 1000 % 10 + '0'); // Display thousands digit
			cursor_position++;
		}
		if (arr[i] >= 100) {
			LCD_WriteChar(arr[i] / 100 % 10 + '0'); // Display hundreds digit
			cursor_position++;
		}
		if (arr[i] >= 10) {
			LCD_WriteChar(arr[i] / 10 % 10 + '0'); // Display tens digit
			cursor_position++;
		}
		LCD_WriteChar(arr[i] % 10 + '0'); // Display units digit
		cursor_position++;
		
		LCD_WriteChar(' ');
		_delay_ms(1000);
	}
	
}
void LCD_clear(void){
	LCD_command(0x01);
}
