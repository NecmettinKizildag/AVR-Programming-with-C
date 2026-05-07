/*
 * Seven Segment Display.c
 *
 * Created: 5/6/2026 3:28:41 PM
 * Author : nec
 */ 

#ifndef F_CPU
#define  F_CPU 16000000UL
#endif

// Look at "https://www.xlitx.com/datasheet/5161AS.pdf"
// pin no on arduino -> segment
// 0 -> E
// 1 -> D
// 2 -> G
// 3 -> F
// 4 -> C
// 5 -> DP
// 6 -> B
// 7 -> A

#include <util/delay.h>
#include "seven_segment.h"

#define REG_ADDR_DDRD		0x2a
#define REG_ADDR_PORTD		0x2b
#define REG_DDRD			(*(volatile uint8_t*)REG_ADDR_DDRD)
#define REG_PORTD			(*(volatile uint8_t*)REG_ADDR_PORTD)
#define PORT_OUTPUT			0xff
#define PORT_ALL_LOW		0x00

static void init(){
	REG_DDRD = PORT_OUTPUT;
	REG_PORTD = PORT_ALL_LOW;
}

int main(void)
{
	init();
	
	uint8_t i; 
	
    while (1) 
    {
		for(i = 0; i < NUMBER_SIZE; i++)
		{
			REG_PORTD = numbers[i];
			_delay_ms(500);
			if (i == 11)
			{
				i = 0;
			}
		}
    }
}

