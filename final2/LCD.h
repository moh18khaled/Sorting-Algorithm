/*
 * LCD.h
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 


#ifndef LCD_H_
#define LCD_H_


#define LCD_data_DDR DDRB
#define LCD_command_DDR DDRA

#define LCD_data_PORT PORTB
#define LCD_command_PORT PORTA

#define RS 3
#define EN 2


void LCD_init(void);
void LCD_command(unsigned char cmd);
void LCD_WriteChar(unsigned char chr);
void LCD_string(unsigned char* str);
void LCD_clear(void);
void LCD_Number(int *arr ,int size);
int len_num(int num);



#endif /* LCD_H_ */