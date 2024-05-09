

#ifndef KEYPAD_H
#define KEYPAD_H

#include "Math.h"
#include "register.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define  inva 0xff

void keypad_init();
unsigned char keypad_get_value();

#endif //KEYPAD_H
