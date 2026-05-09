/*
 * PIN Change Interrupts.c
 *
 * Created: 5/9/2026 8:06:44 PM
 * Author : nec
 */ 

#include <stdint.h>
#include <avr/interrupt.h>

#define REG_ADDR_PCICR				0x68	// Pin Change Interrupt Control Register
#define _REG_PCICR					(*(volatile uint8_t*)REG_ADDR_PCICR)

#define REG_ADDR_PCMSK0				0x6B	// Pin Change Mask Register 0
#define _REG_PCMSK0					(*(volatile uint8_t*)REG_ADDR_PCMSK0)

#define REG_ADDR_PCMSK1				0x6C	// Pin Change Mask Register 1
#define _REG_PCMSK1					(*(volatile uint8_t*)REG_ADDR_PCMSK1)

#define REG_ADDR_PCMSK2				0x6D	// Pin Change Mask Register 2
#define _REG_PCMSK2					(*(volatile uint8_t*)REG_ADDR_PCMSK2)

#define PCINT_ENABLE				1		
#define PCINT_DISABLE				0

/*
typedef struct{
	uint8_t pcie0 : 1;
	uint8_t pcie1 : 1;
	uint8_t pcie2 : 1;
	uint8_t reserved : 5;
}pcicr_t, *pcicr_ptr_t;
#define REG_PCICR					((pcicr_ptr_t)REG_ADDR_PCICR)
*/

typedef struct{
	uint8_t portb : 1;
	uint8_t portc : 1;
	uint8_t portd : 1;
	uint8_t reserved : 5;
}pcicr_t, *pcicr_ptr_t;
#define REG_PCICR					((pcicr_ptr_t)REG_ADDR_PCICR)

/*
typedef struct{
	uint8_t pcint0 : 1;	
	uint8_t pcint1 : 1;	
	uint8_t pcint2 : 1;	
	uint8_t pcint3 : 1;	
	uint8_t pcint4 : 1;	
	uint8_t pcint5 : 1;	
	uint8_t pcint6 : 1;	
	uint8_t pcint7 : 1;	
}pcmsk0_t,*pcmsk0_ptr_t;
#define REG_PCMSK0					((pcmsk0_ptr_t)REG_ADDR_PCMSK0)

typedef struct{
	uint8_t pcint8 : 1;
	uint8_t pcint9 : 1;
	uint8_t pcint10 : 1;
	uint8_t pcint11 : 1;
	uint8_t pcint12 : 1;
	uint8_t pcint13 : 1;
	uint8_t pcint14 : 1;
	uint8_t reserved : 1;
}pcmsk1_t,*pcmsk1_ptr_t;

typedef struct{
	uint8_t pcint16 : 1;
	uint8_t pcint17 : 1;
	uint8_t pcint18 : 1;
	uint8_t pcint19 : 1;
	uint8_t pcint20 : 1;
	uint8_t pcint21 : 1;
	uint8_t pcint22 : 1;
	uint8_t pcint23 : 1;
}pcmsk2_t,*pcmsk2_ptr_t;
*/

typedef struct{
	uint8_t pcint_pb0 : 1;
	uint8_t pcint_pb1 : 1;
	uint8_t pcint_pb2 : 1;
	uint8_t pcint_pb3 : 1;
	uint8_t pcint_pb4 : 1;
	uint8_t pcint_pb5 : 1;
	uint8_t reserved1 : 2; // pcint6 and pcint7 doesnt exist on arduino board
	
	uint8_t pcint_pc0 : 1;
	uint8_t pcint_pc1 : 1;
	uint8_t pcint_pc2 : 1;
	uint8_t pcint_pc3 : 1;
	uint8_t pcint_pc4 : 1;
	uint8_t pcint_pc5 : 1;
	uint8_t pcint_pc6 : 1;
	uint8_t reserved2 : 1;
	
	uint8_t pcint_pd0 : 1;
	uint8_t pcint_pd1 : 1;
	uint8_t pcint_pd2 : 1;
	uint8_t pcint_pd3 : 1;
	uint8_t pcint_pd4 : 1;
	uint8_t pcint_pd5 : 1;
	uint8_t pcint_pd6 : 1;
	uint8_t pcint_pd7 : 1;
}pcmsk_t,*pcmsk_ptr_t;
#define REG_PCMSK					((pcmsk_ptr_t)REG_ADDR_PCMSK0)

ISR(PCINT0_vect){ // works , if our pin has any change 
	PORTD ^= 0xff;
}

int main(void)
{
	DDRD = 0xff; 
	PORTD = 0xff;
	
    //REG_PCICR -> pcie0 = PCINT_ENABLE; // PB
	//REG_PCMSK0 -> pcint0 = PCINT_ENABLE; // pin 8 on arduino 
	
	REG_PCICR -> portb = PCINT_ENABLE;
	REG_PCMSK -> pcint_pb0 = PCINT_ENABLE;
	sei();
	
    while (1) 
    {
    }
}

