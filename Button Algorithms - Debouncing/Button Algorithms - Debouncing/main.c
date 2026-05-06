/*
 * Button Algorithms - Debouncing.c
 *
 * Created: 5/6/2026 2:33:11 PM
 * Author : nec
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define ON					0xff
#define OFF					0x00

#define BUTTON_B0_PRESSED	(PINB & 1 << 0) // if pin 8 on arduion (PB0) has HIGH input
#define STATE_ON			1
#define STATE_OFF			0
#define DELAY				500
#define LEDS_ON				(PORTD = 0xff)
#define LEDS_OFF			(PORTD = 0x00)

int main(void)
{
    DDRD = ON; // output
	DDRB = OFF; // input
	
	uint8_t _state = 0;
	
    while (1) 
    {
		if ((STATE_ON == _state) && (BUTTON_B0_PRESSED == STATE_ON))
		{
			_state = OFF;
			_delay_ms(DELAY);
		}
		
		if ((STATE_OFF == _state) && (BUTTON_B0_PRESSED == STATE_ON))
		{
			_state ^= (1 << 0); // set _state 1 if its 0 , 0 if its 1
			_delay_ms(DELAY);
		}
		
		if (_state & (1 << 0)) // is _state 1 or 0. same with (_state == 1)
		{
			LEDS_ON;
		}
		else
		{
			LEDS_OFF;
		}
    }
}



