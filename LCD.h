/*
 * LCD.h
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "Math.h"
#include "register.h"


#define LCD_data_DDR DDRB
#define LCD_command_DDR DDRB

#define LCD_data_PORT PORTB
#define LCD_command_PORT PORTA

#define RS 3
#define EN 2

void LCD_init(void);
void LCD_command(unsigned char cmd);
void LCD_WriteChar(unsigned char chr);
void LCD_string(unsigned char* str);
void LCD_clear(void);

#endif /* LCD_H_ */