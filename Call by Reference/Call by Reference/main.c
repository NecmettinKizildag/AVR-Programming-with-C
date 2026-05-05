/*
 * Call by Reference.c
 *
 * Created: 5/5/2026 1:01:55 PM
 * Author : nec
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

/*
#define PIND	*((uint8_t*) 0x29)
#define DDRD	*((uint8_t*) 0x2A)
#define PORTD	*((uint8_t*) 0x2B)
*/

uint8_t on = 0xFF;
uint8_t off = 0x00;

void change(uint8_t*x, uint8_t* y);

void change(uint8_t*x, uint8_t* y){
	uint8_t temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	DDRD = 0xFF;
	
	//set function as pointer
	void (*change_ptr)(uint8_t*,uint8_t*) = change;
	
	while (1)
	{
		PORTD = on;
		_delay_ms(500);
		//change(&on, &off);
		change_ptr(&on,&off);
	}
}