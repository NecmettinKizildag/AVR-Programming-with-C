/*
 * Button Algorithms - Pointers.c
 *
 * Created: 5/6/2026 2:39:00 PM
 * Author : nec
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define ON					0xff
#define OFF					0x00

#define INIT_PORTS()		do{DDRD = ON; DDRB = OFF; PORTD = OFF;} while (0);

#define BUTTON_B0_PRESSED	(PINB & 1 << 0) // if pin 8 on arduion (PB0) has HIGH input
#define DEBOUNCE_TIME		50
#define STATE_ON			1
#define STATE_OFF			0
#define DELAY				100
#define LEDS_ON				(PORTD = 0xff)
#define LEDS_OFF			(PORTD = 0x00)

uint8_t state();
uint8_t state(){
	if (BUTTON_B0_PRESSED) // control bouncing with debouncing
	{
		_delay_ms(DEBOUNCE_TIME);
		if (BUTTON_B0_PRESSED)
		{
			return 1;
		}
	}
	return 0;
}

void loop1(), loop2();

void loop1(){
	uint8_t i;
	for(i = 0; i < 4; i++){
		PORTD ^= (1 << i);
		_delay_ms(DELAY);
	}
}

void loop2(){
	uint8_t i;
	for(i = 4; i > 0; i--){
		PORTD ^= (1 << (i - 1));
		_delay_ms(DELAY);
	}
}

int main(void)
{
    INIT_PORTS();
	
	//uint8_t led_no = 0;
	
	void (*loop_func_arr[])() = {loop1, loop2};
	uint8_t loop_index = 0;
	
    while (1) 
    {
		/*
		if (state())
		{
			switch (led_no){
				case 1 : PORTD ^= (1 << 0); PORTD ^= (1 << 3); break;
				case 2 : PORTD ^= (1 << 1); PORTD ^= (1 << 2); led_no = 0; break;
			}
			led_no++;
			_delay_ms(DELAY);
		}
		*/
		
		if (state())
		{
			switch (loop_index){
				case 0 : 
					loop_func_arr[0]();
					loop_index++;
					break;
				case 1 : 
					loop_func_arr[1](); 
					loop_index-- ; 
					break;
			}
			_delay_ms(DELAY);
		}
    }
}

