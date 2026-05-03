/*
 * Ders01.c
 *
 * Created: 4/16/2026 6:01:01 PM
 * Author : nec
 */ 

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <util/delay.h>


int main(void)
{
	// arduino uno r3 built-in led on/off
    DDRB = 0b11111111; 
	// DDRB = 0xFF; hexadeimal
	
	
    while (1) 
    {
		/* // register by binary
		PORTB = 0b00100000;
		_delay_ms(1000);
		PORTB = 0b00000000;
		_delay_ms(1000);
		*/
		
		// register by hexadecimal
		PORTB = 0x20;
		_delay_ms(1000);
		PORTB = 0x00;
		_delay_ms(1000);
    }
}

