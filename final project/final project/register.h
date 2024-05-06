/*
 * port.h
 *
 * Created: 3/14/2024 10:52:21 AM
 *  Author: mohamed khaled
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

#define PORTA  *(volatile unsigned char*)(0x3B)
#define DDRA  *(volatile unsigned char*)(0x3A)
#define PINA  *(volatile unsigned char*)(0x39)


#define PORTB  *(volatile unsigned char*)(0x38)
#define DDRB  *(volatile unsigned char*)(0x37)
#define PINB  *(volatile unsigned char*)(0x36)

#define PORTC  *(volatile unsigned char*)(0x35)
#define DDRC  *(volatile unsigned char*)(0x34)
#define PINC  *(volatile unsigned char*)(0x33)

#define PORTD  *(volatile unsigned char*)(0x32)
#define DDRD  *(volatile unsigned char*)(0x31)
#define PIND  *(volatile unsigned char*)(0x30)


#define SREG  *(volatile unsigned char*)(0x5F)

#define MCUCR   _SFR_IO8(0x35)
#define GICR   _SFR_IO8(0x3B)


#endif /* PORT_H_ */