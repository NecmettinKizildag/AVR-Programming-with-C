/*
 * GPIO Modelling - Ex-interrups.c
 *
 * Created: 5/10/2026 1:09:37 PM
 * Author : nec
 */ 

#ifndef F_CPU 
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "328p_e_interrupts.h"
#include "328p_gpio.h"

#define DELAY	100

static void init_gpio(){
	DDRB_UNION -> port = PORT_ALL_OUTPUT;
	PORTB_UNION -> port = PORT_ALL_LOW;
	DDRD_UNION -> pins.pin6 = PIN_OUTPUT;
	DDRD_UNION -> pins.pin7 = PIN_OUTPUT; 
}

static void init_external_interrupts(){
	REG_EIMSK -> int0 = INT_ENABLE;
	REG_EIMSK -> int1 = INT_ENABLE;
	
	REG_EICRA -> int0_mode = INT_MODE_FALLING_EDGE;
	REG_EICRA -> int1_mode = INT_MODE_RISING_EDGE;
	
	sei();
}

volatile uint8_t selection; 
uint8_t i = 0;

void loop1(){
	for(i = 0; i < 6; i++){
		PORTB_UNION -> port ^= (1 << i);
		_delay_ms(DELAY);
	}
}

void loop2(){
	for(i = 7; i > 0; i++){
		PORTB_UNION -> port ^= (1 << (i - 1));
		_delay_ms(DELAY);
	}
}



ISR(INT0_vect){ // Interrupt Service Routine // if int0 pin interrupted this code gonna work
	selection = 1;
	PORTB_UNION -> pins.pin6 ^= PIN_HIGH;
}

ISR(INT1_vect){ // if int1 pin interrupted this code gonna work
	selection = 2;
	PORTB_UNION -> pins.pin7 ^= PIN_HIGH;
}

int main(void)
{
	init_gpio();
    init_external_interrupts();
	
	selection = 0;
	
    while (1) 
    {
		switch (selection){
			case 1 :  loop1(); break;
			case 2 :  loop2(); break;
			default: break;
		}
    }
}

