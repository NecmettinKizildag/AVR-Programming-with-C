/*
 * Introduction to Pointer.c
 *
 * Created: 5/5/2026 12:36:53 PM
 * Author : nec
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF; // set pins 0, 1, 2, 3, 4, 5, 6 and 7 as output
	PORTD = 0x00; // all pins are LOW
	
	PORTD = (uint16_t)&PORTD; // we assign register of PORTD on PORTD. you can connect LEDs into pins 0, 1, 2, 3, 4, 5, 6 and 7 and can see which is 0x2B (0010 1011). Look at the Datasheet. 
	
    while (1) 
    {
    }
}