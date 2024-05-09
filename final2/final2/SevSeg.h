


#ifndef SEVSEG_H
#define SEVSEG_H

#include "Math.h"
#include "register.h"
#include "pins.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void seven_seg_init();
void display_on_seven_seg(int num,int pin);

#endif //SEVSEG_H
