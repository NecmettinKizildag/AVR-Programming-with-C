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
    DDRB = 0b11111111; // set as output
	// DDRB = 0xFF; hexadeimal
	
	DDRD = 0xFF; // 
	
	uint8_t num = 0;
	
    while (1) 
    {
		/* // register by binary
		PORTB = 0b00100000;
		_delay_ms(1000);
		PORTB = 0b00000000;
		_delay_ms(1000);
		*/
		
		// register by hexadecimal // built in LED
		PORTB = 0x20;
		_delay_ms(500);
		PORTB = 0x00;
		_delay_ms(500);
		
		for (num = 0; num <= 15; num++ ) // pin 0,1,2 and 3 // 0x0F
		{
			PORTD = num;
			_delay_ms(500);
			if (num == 15)
			{
				num = 0;
			}
		}
    }
}

