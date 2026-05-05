#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <util/delay.h>


#define ON				0xFF
#define OFF				0x00
#define PIND			*((uint8_t*) 0x29) // value of uint8_t varible
#define DDRD			*((uint8_t*) 0x2A)
#define PORTD			*((uint8_t*) 0x2B)

int main(){
	DDRD = ON;
	
	while (1)
	{
		PORTD = ON;
		_delay_ms(1000);
		PORTD = OFF;
		_delay_ms(1000);
	}
}


