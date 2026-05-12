/*
 * Timer TCCR0A and TCCR0B.c
 *
 * Created: 5/12/2026 3:22:48 PM
 * Author : nec
 */ 

#include <stdint.h>
// 0x44		COM0A1 COM0A0 COM0B1 COM0B0 – – WGM01 WGM00			TCCR0A
// 0x45		FOC0A FOC0B – – WGM02 CS02 CS01 CS00				TCCR0B

#define REG_ADDR_TCCR0					0x44 // tccr0a and tccr0b are sequential, so we use them together like 16 bit register
#define _REG_TCCR0						(*(volatile uint16_t*)REG_ADDR_TCCR0) // if we use uint8_t there will be a overflow

typedef struct{
	uint8_t wgmA : 2;
	uint8_t reservedA : 2;
	uint8_t com0B2 : 2;
	uint8_t com0A : 2;
	uint8_t clock_select : 3;
	uint8_t wgmB : 1;
	uint8_t reservedB : 2;
	uint8_t foc0B : 1;
	uint8_t foc0A : 1;
	}_tccr0_t, *_tccr0_ptr_t;
	
//#define REG_TCCR0						((_tccr0_ptr_t)REG_ADDR_TCCR0)

typedef union{
	_tccr0_t bits; 
	volatile uint16_t value;
	}tccr0_t, *tccr0_ptr_t;

#define REG_TCCR0						(*(tccr0_ptr_t)REG_ADDR_TCCR0)

#define TIMER0_MODE_SELECTION			(REG_TCCR0.bits.wgmA)
#define TIMER0_MODE_NORMAL				0
#define TIMER0_MODE_CTC					2 // look at data sheet for "Waveform Generation Mode Bit Description"

#define TIMER0_CLOCK_SELECTION			REG_TCCR0.bits.clock_select
#define TIMER0_NO_CLOCK_SOURCE			0
#define TIMER0_NO_PRESCALING			1
#define TIMER0_PRESCALING_8				2
#define TIMER0_PRESCALING_64			3
#define TIMER0_PRESCALING_256			4
#define TIMER0_PRESCALING_1024			5
#define TIMER0_EXTERNAL_CLOCK_FALLING	6
#define TIMER0_EXTERNAL_CLOCK_RISING	7 // look at data sheet for "Clock Select Bit Description"


// (0x46) TCNT0[7:0]					TCNT0
// (0x35) – – – – – OCF0B OCF0A TOV0	TIFR0

#define REG_ADDR_TCNT0					0x46
#define _REG_TCNT0						(*(volatile uint16_t*)REG_ADDR_TCNT0)

#define REG_ADDR_TIFR0					0x35
#define _REG_TIFR0						(*(volatile uint16_t*)REG_ADDR_TIFR0)

typedef struct{
	uint8_t value : 8;
	}tcnt0_t, *tcnt0_ptr_t;

#define REG_TIMER0_COUNTER				((tcnt0_ptr_t)REG_ADDR_TCNT0)
#define TIMER0_COUNTER					REG_TIMER0_COUNTER.value

typedef struct{
	uint8_t toc0 : 1;
	uint8_t ocf0a : 1;
	uint8_t ocf0b : 1;
	uint8_t reserved : 5;
	}tifr0_t, *tifr0_ptr_t;

#define REG_TIFR0						((tifr0_ptr_t)REG_ADDR_TIFR0)
#define TIMER0_OVERFLOW					REG_TIFR0.tov0

// timer0_counter -> 0...1...2.........255 -> timer0_overflow ...1
// ISR -> timer0_overflow ...0
// timer0_overflow ...1
// uint8_t overflow = 0;
// after every overflow -> overflow++

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		_REG_TCCR0 = 0xFFFF;
		
		//REG_TCCR0 -> wgmA = 3;
		//REG_TCCR0 -> clock_select = 5;
		
		REG_TCCR0.bits.wgmA = 3;
		REG_TCCR0.bits.clock_select = 5;
		
		REG_TCCR0.value = 0xFFFF;
		
		TIMER0_MODE_SELECTION = TIMER0_MODE_NORMAL;
		
		TIMER0_CLOCK_SELECTION = TIMER0_NO_PRESCALING;
    }
}

