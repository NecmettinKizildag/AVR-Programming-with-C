#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <util/delay.h>


#define PIND			*((uint8_t*) 0x29) 
#define DDRD			*((uint8_t*) 0x2A)
#define PORTD			*((uint8_t*) 0x2B)

// i have only 4 LED so there will be only 2 loop
#define LOOP_NUMBER			2
#define LOOP_DELAY	100

void loop1(), loop2();

void loop1(){
	PORTD = 0x06; //(0110)
	_delay_ms(LOOP_DELAY);
}

void loop2(){
	PORTD = 0x09; //(1001)
	_delay_ms(LOOP_DELAY);
}

int main(){
	DDRD = 0xFF;
	
	void(*func_ptr_arr[])() = {loop1,loop2};
	
	while (1)
	{
		uint8_t i;
		
		for(i = 0; i<LOOP_NUMBER; i++){
			func_ptr_arr[i]();
			_delay_ms(LOOP_DELAY);
		}
	}
}


