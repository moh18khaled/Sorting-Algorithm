


#ifndef SEVSEG_H
#define SEVSEG_H

#define SevSeg_en_DDR1 DDRA
#define SevSeg_en_DDR2 DDRB

#define SevSeg_en_PORT1 PORTA
#define SevSeg_en_PORT2 PORTB

#define data_PORT PORTB


void display_on_seven_seg(int num,int pin);

#endif //SEVSEG_H
