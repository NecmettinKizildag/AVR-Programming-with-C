#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <util/delay.h>


#define ON				0xFF
#define OFF				0x00
#define TRUE			1

uint8_t* arr[2] = {(uint8_t*) 0x2A, (uint8_t*) 0x2B};
uint8_t** ptrArr = arr;	
//uint8_t** ptrArr = arr[0];	// same

int main(){
	
	*ptrArr[0] = ON;
	//**ptrArr = ON; // same
	
	uint8_t** portd = arr+1;
	while (TRUE)
	{
		/*
		*ptrArr[1] = ON;
		_delay_ms(200);
		*ptrArr[1] = OFF;
		_delay_ms(200);
		*/
		
		**portd = ON;
		_delay_ms(800);
		**portd = OFF;
		_delay_ms(800); // same
	}
}


