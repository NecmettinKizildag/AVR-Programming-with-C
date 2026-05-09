/*
 * External Interrupts.c
 *
 * Created: 5/9/2026 2:30:53 PM
 * Author : nec
 */ 

#include <stdint.h>
#include <avr/interrupt.h>

//EIMSK (External Interrupt Mask Register) - 0x3D / INT0 (External Interrupt Request 0 (pin D2)) - INT1 (External Interrupt Request 1 (pin D3))
//EICRA (External Interrupt Control Register A) - 0x69 / ISC00 (The low level of INTn generates an interrupt request) - ISC01 (Any logical change on INTn generates and interrupt request) - ISC10 (The falling edge of INT0 generates an interrupt request) - ISC11 (The rising edge of INT0 generates an interrupt request)
//ISC00 and ISC01 are control for INT0 of EIMSK - ISC10 and ISC11 are control for INT1 of EIMSK
//EIFR (External Interrupt Flag Register) - 0x3C / INTF0 - INTF1

#define REG_ADDR_EIMSK					0x3D
#define _REG_EIMSK						(*(volatile uint8_t*)REG_ADDR_EIMSK)

#define REG_ADDR_EICRA					0x69
#define _REG_EICRA						(*(volatile uint8_t*)REG_ADDR_EICRA)

#define REG_ADDR_EIFR					0x3C
#define _REG_EIFR						(*(volatile uint8_t*)REG_ADDR_EIFR)

typedef struct{ // register modelling
	uint8_t int0 : 1; // int0 can hold 1 bit data
	uint8_t int1 : 1;
	uint8_t reserved : 6; // reserved can hold 6 bit data, we need this variable because struct can hold min value of 8 bit data
}eimsk_t, *eimsk_ptr_t; // eimsk_t -> name of struct, eimsk_ptr_t -> pointer of struct

#define REG_EIMSK						((eimsk_ptr_t)REG_ADDR_EIMSK) // we access our struct trough REG_EIMSK using pointer of struct
#define INT_ENABLE						1
#define INT_DISABLE						0

typedef struct{
	uint8_t int0_mode : 2;
	uint8_t int1_mode : 2;
	uint8_t reserved : 4;
}eicra_t, *eicra_ptr_t;

#define REG_EICRA						((eicra_ptr_t)REG_ADDR_EICRA)
#define INT_MODE_LOW_LEVEL				0
#define INT_MODE_ANY_LOGICAL_CHANGE		1
#define INT_MODE_FALLING_EDGE			2
#define INT_MODE_RISING_EDGE			3

static void init_external_interrupts(){
	REG_EIMSK -> int0 = INT_ENABLE;
	REG_EIMSK -> int1 = INT_ENABLE;
	
	REG_EICRA -> int0_mode = INT_MODE_LOW_LEVEL;
	REG_EICRA -> int1_mode = INT_MODE_ANY_LOGICAL_CHANGE;
	
	sei();
}

ISR(INT0_vect){ // Interrupt Service Routine // if int0 pin interrupted this code gonna work
	
}

ISR(INT1_vect){ // if int1 pin interrupted this code gonna work
	
}
int main(void)
{
    init_external_interrupts();
	
    while (1) 
    {
    }
}

