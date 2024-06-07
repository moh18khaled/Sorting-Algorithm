

#ifndef KEYPAD_H
#define KEYPAD_H

#define ROW_DDR DDRC
#define COL_DDR DDRD

#define ROW_PORT PORTC
#define COL_PORT PORTD

#define COL_PIN PIND


#define  inva 0xff

void keypad_init();
unsigned char keypad_get_value();

#endif //KEYPAD_H
