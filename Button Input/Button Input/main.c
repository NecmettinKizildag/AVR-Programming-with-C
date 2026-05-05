/*
 * Button Input.c
 *
 * Created: 5/5/2026 6:12:09 PM
 * Author : nec
 */ 
#ifndef F_CPU
#define  F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define PIN_HIGH	PINB & (1 << 0)
#define PIN_LOW		!(PINB & (1 << 0))

int main(void)
{
	// MCUCR = 1 << PUD //micro control unit control register - pull up disabled
	DDRD = 0xff; // sets DDRD as output
	DDRB = 0x00; // sets DDRB as input
	
	PORTD =  0x00;
	
	PORTD = 0xff; // this is pull up but if you write  MCUCR = 1 << PUD , this row is not gonna used 
	
    while (1) 
    {
		if (PIN_HIGH) // control of PINB0 has HIGH INPUT (PINB0 is 8th pin on arduino)
		{
			PORTD = 0x03; //(0011)
		}
		else if (PIN_LOW)
		{
			PORTD = 0x0C; //(1100)
		}
    }
}

