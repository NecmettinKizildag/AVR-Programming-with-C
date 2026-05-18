#ifndef _328P_TIMER0_H_
#define _328P_TIMER0_H_

#define REG_ADDR_TCCR0					0x44 // tccr0a and tccr0b are sequential, so we use them together like 16 bit register
#define _REG_TCCR0						(*(volatile uint16_t*)REG_ADDR_TCCR0) // if we use uint8_t there will be a overflow

#define REG_ADDR_TCNT0					0x46
#define _REG_TCNT0						(*(volatile uint16_t*)REG_ADDR_TCNT0)

#define REG_ADDR_TIMSK0					0x6E
#define _REG_TIMSK0						(*(volatile uint16_t*)REG_ADDR_TIMSK0)

#define REG_ADDR_TIFR0					0x35
#define _REG_TIFR0						(*(volatile uint16_t*)REG_ADDR_TIFR0)

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

typedef union{
	_tccr0_t bits;
	volatile uint16_t value;
}tccr0_t, *tccr0_ptr_t;

#define REG_TCCR0						(*(tccr0_ptr_t)REG_ADDR_TCCR0)
#define TIMER0_MODE_SELECT				(REG_TCCR0.bits.wgmA)
#define timer0_mode_NORMAL				0
#define timer0_mode_CTC					2 // look at data sheet for "Waveform Generation Mode Bit Description"

#define TIMER0_CLOCK_SELECT				REG_TCCR0.bits.clock_select
#define timer0_no_clock_source_STOP		0
#define timer0_no_prescaling_START		1
#define timer0_prescaling_8				2
#define timer0_prescaling_64			3
#define timer0_prescaling_256			4
#define timer0_prescaling_1024			5
#define timer0_ext_clock_FALLING_EDGE	6
#define timer0_ext_clock_RISING_EDGE	7 // look at data sheet for "Clock Select Bit Description"

//***************OPTIMISATION***************//
#define TIMER0_mode_NORMAL_no_presacling()		do{REG_TCCR0.value = 0x0100;} while (0); // 0000 0001 0000 0000
#define TIMER0_mode_CTCL_no_presacling()		do{REG_TCCR0.value = 0x0102;} while (0); // 0000 0001 0000 0010
#define TIMER0_mode_NORMAL_presacling_1024()	do{REG_TCCR0.value = 0x0500;} while (0); // 0000 0101 0000 0000
//******************************************//

typedef struct{
	uint8_t value : 8;
}tcnt0_t, *tcnt0_ptr_t;

#define REG_TCNT0				(*(tccr0_ptr_t)REG_ADDR_TCNT0)
#define TIMER0_counter			REG_TCNT0.value

// (0x6E) – – – – – OCIE0B OCIE0A TOIE0		TIMSK0

typedef struct{
	uint8_t toie0 : 1;
	uint8_t ocie0A : 1;
	uint8_t ocie0B : 1;
	uint8_t reserved : 5;
}_timsk0_t, *_timsk0_ptr_t;

typedef union{
	_timsk0_t bits;
	volatile uint8_t value;
}timsk0_t, *timsk0_ptr_t;

#define REG_TISMK0					(*(timsk0_ptr_t)REG_ADDR_TIMSK0)
#define TIMER0_interrupt_overflow	REG_TISMK0.bits.toie0
#define TIMER0_interrupt_comp_A		REG_TIFR0.bits.ocie0A
#define TIMER0_interrupt_comp_B		REG_TIFR0.bits.ocie0B
#define interrupt_ENABLE			1
#define interrupt_DISABLE			0


typedef struct{
	uint8_t tov0 : 1;
	uint8_t ocf0a : 1;
	uint8_t ocf0b : 1;
	uint8_t reserved : 5;
}tifr0_t, *tifr0_ptr_t;

#define REG_TIFR0				(*(tifr0_ptr_t)REG_ADDR_TIFR0)
#define TIMER0_flag_overflow	REG_TIFR0.tov0
#define TIMER0_flag_comp_A		REG_TIFR0.ocf0a
#define TIMER0_flag_comp_B		REG_TIFR0.ocf0b
#define reset_FLAG				1
#define set_FLAG				0 // for testing the ISR


#endif // _328P_TIMER0_H_