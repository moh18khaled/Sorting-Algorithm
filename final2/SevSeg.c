/*
 * SevSeg.c
 *
 * Created: 3/21/2024 1:24:42 AM
 *  Author: mohamed khaled
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "SevSeg.h"
#include "Math.h"
#include "register.h"
#include "pins.h"

void display_on_seven_seg(int num, int pin) {
	SET_BIT(SevSeg_en_DDR1, p2);
	SET_BIT(SevSeg_en_DDR1, p3);
	SET_BIT(SevSeg_en_DDR2, p5);
	SET_BIT(SevSeg_en_DDR2, p6);

	SET_BIT(SevSeg_en_PORT1, p2);
	SET_BIT(SevSeg_en_PORT1, p3);
	SET_BIT(SevSeg_en_PORT2, p5);
	SET_BIT(SevSeg_en_PORT2, p6);

	data_PORT &= ~0b00010111;
	const int arr[10] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x10, 0x11};
	data_PORT |= arr[num];
	

	/*
	port_pin --> 7-seg num from the right
	2 --> 2
	3 --> 1 (1 first 7-seg from the right)
	5 --> 3
	6 --> 4
	*/
	if (pin < 3) {
		if (pin == 1)
		   pin += 2;
		CLR_BIT(SevSeg_en_PORT1, pin);
		_delay_ms(1);
		SET_BIT(SevSeg_en_PORT1, pin);
		}
		else {
		pin += 2;
		CLR_BIT(SevSeg_en_PORT2, pin);
		_delay_ms(1);
		SET_BIT(SevSeg_en_PORT2, pin);
	}
}
