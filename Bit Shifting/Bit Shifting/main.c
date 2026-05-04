/*
 * Bit Shifting.c
 *
 * Created: 5/4/2026 4:22:05 PM
 * Author : nec
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL // frequency of chip
#endif

#include <avr/io.h>
#include <util/delay.h>




int main(void)
{
	// 0000 0000 = 0000 0000 | 0000 0110;
	// a = a + b;
	// a += b;
	// 0000 0000 |= 0000 0110;
	// PORTD |= (1 << PORTD1); // shift 1 bit of pin 1 which it means we assign pin 1 to HIGH (0000 0000 -> 0000 0010)
	
	// PORTD = 0x02;
	// PORTD = PORTD | (1 << PORTD2);
	// PORTD |= (1 << PORTD2);
	// PORTD |= (1 << 2);   ALL 4 OPERATIONS ARE SAME;	
	
	// PORTD &= ~(1 << PORTD2);
	// PORTD &= ~(1 << 2); // we assign pin 2 to LOW (0000 0010 -> 0000 0000)
	
	//		0000 0000
	//	  &~0000 0010
	//	  -----------
	
	//		0000 0000
	//	   &1111 1101
	//	  ----------- 
	//		0000 0000
	
    DDRD = 0x0F; // set pins 0, 1, 2 and 3 as output
	PORTD = 0x00; // all pins are LOW
	
	// PORTD |= (1 << 0); // set pin 0 as HIGH
	// PORTD |= (1 << 1); // set pin 1 as HIGH
	// PORTD |= (1 << 0) | (1 << 1);
	
	uint8_t num;
    while (1) 
    {
		/*
		for (num = 0; num < 4; num++)
		{
			PORTD |= (1 << num); 
			_delay_ms(500);
		}
		for (num = 0; num < 4; num++)
		{
			PORTD &= ~(1 << num);
			_delay_ms(500);
		}
		*/
		
		for (num = 0; num < 4; num++) // same effect with above
		{
			PORTD ^= (1 << num);
			_delay_ms(500);
		}
	
    }
}

