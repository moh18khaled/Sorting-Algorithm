

#ifndef KEYPAD_H
#define KEYPAD_H

#include "Math.h"
#include "register.h"

#define  inva 0xff

void keypad_init();
unsigned char keypad_get_value();

#endif //KEYPAD_H
