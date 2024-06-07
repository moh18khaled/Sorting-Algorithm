/*
 * numbers.c
 *
 * Created: 5/9/2024 12:06:59 AM
 *  Author: mohamed khaled
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "numbers.h"
#include "timer0.h"
#include "register.h"
#include "SevSeg.h"
#include "LCD.h"

extern uint8_t g_tick;

void build_num(int *num, unsigned char ans) {
    ans -= '0';
    if (*num == -1)
        *num = ans;
    else
        *num = *num * 10 + ans;
}

void separate_num(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        int count = 1, num = arr[i];
        timer0_init();

        while (g_tick != NUMBER_OF_OVERFLOWS) {
            if (!num)
                goto zero;

            while (num > 0) {
            zero:
                display_on_seven_seg(num % 10, count++);
                num /= 10;
            }
            num = arr[i];
            count = 1;
        }

        g_tick = 0;
    }
	
	//-- latch --
	
	CLR_BIT(LCD_command_PORT,EN);
	SET_BIT(LCD_command_PORT,EN);
	_delay_ms(1);
	CLR_BIT(LCD_command_PORT,EN);

}

void sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
