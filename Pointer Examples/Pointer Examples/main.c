#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <util/delay.h>

#define REGISTER_ZERO	0x29 // PIND
#define MY_DDRD			*myDDRD
#define MY_PORTD		*(myDDRD + 1)
#define ON				0xFF
#define OFF				0x00
#define LEDS(led_state, duration)	do{MY_PORTD = led_state; _delay_ms(duration);}while(0)			

uint8_t* myDDRD = (uint8_t*) (REGISTER_ZERO + 1); // DDRD (0x2A)

int main(){
	
	MY_DDRD = ON;
	MY_PORTD = OFF;
	
	while (1)
	{
		/*
		MY_PORTD = ON;
		_delay_ms(500);
		MY_PORTD = OFF;
		_delay_ms(500);
		*/
		
		LEDS(ON,1000);
		LEDS(OFF,200);
	}
}

