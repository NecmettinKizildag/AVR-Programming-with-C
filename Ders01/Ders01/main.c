/*
 * Ders01.c
 *
 * Created: 4/16/2026 6:01:01 PM
 * Author : nec
 */ 

#include <avr/io.h>


int main(void)
{
    DDRB = 0b11111111;
	PORTB = 0b00100000;
	
    while (1) 
    {
    }
}

