#ifndef _328P_TIMER1_H_
#define _328P_TIMER1_H_

//(0x80) COM1A1 COM1A0 COM1B1 COM1B0 – – WGM11 WGM10 TCCR1A						Timer/Counter1 Control Register A
#define REG_ADDR_TCCR1A					0x80
#define _REG_TCCR1A						(*(volatile uint8_t*)REG_ADDR_TCCR1A)
#define _REG_TCCR1AB					(*(volatile uint16_t*)REG_ADDR_TCCR1A)

//(0x81) ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 TCCR1B						Timer/Counter1 Control Register B
#define REG_ADDR_TCCR1B					0x81
#define _REG_TCCR1B						(*(volatile uint8_t*)REG_ADDR_TCCR1B)

//(0x82) FOC1A FOC1B – – – – – –		TCCR1C									Timer/Counter1 Control Register C
#define REG_ADDR_TCCR1C					0x82
#define _REG_TCCR1C 					(*(volatile uint8_t*)REG_ADDR_TCCR1C)

//(0x85) TCNT1[15:8] TCNT1H				Timer/Counter1
//(0x84) TCNT1[7:0] TCNT1L
#define REG_ADDR_TCNT1L					0x84
#define REG_ADDR_TCNT1H					0x85
#define _REG_TCNT1L 					(*(volatile uint8_t*)REG_ADDR_TCNT1L)
#define _REG_TCNT1H 					(*(volatile uint8_t*)REG_ADDR_TCNT1H)
#define _REG_TCNT1LH 					(*(volatile uint16_t*)REG_ADDR_TCNT1L)

//(0x89) OCR1A[15:8] OCR1AH				Output Compare Register 1 A
//(0x88) OCR1A[7:0] OCR1AL
#define REG_ADDR_OCR1AL					0x88
#define REG_ADDR_OCR1AH					0x89
#define _REG_OCR1AL 					(*(volatile uint8_t*)REG_ADDR_OCR1AL)
#define _REG_OCR1AH						(*(volatile uint8_t*)REG_ADDR_OCR1AH)
#define _REG_OCR1ALH 					(*(volatile uint16_t*)REG_ADDR_OCR1AL)

//(0x8B) OCR1B[15:8] OCR1BH				Output Compare Register 1 B
//(0x8A) OCR1B[7:0] OCR1BL
#define REG_ADDR_OCR1BL					0x8A
#define REG_ADDR_OCR1BH					0x8B
#define _REG_OCR1BL 					(*(volatile uint8_t*)REG_ADDR_OCR1BL)
#define _REG_OCR1BH						(*(volatile uint8_t*)REG_ADDR_OCR1BH)
#define _REG_OCR1BLH 					(*(volatile uint16_t*)REG_ADDR_OCR1BL)

//(0x87) ICR1[15:8] ICR1H				 Input Capture Register 1
//(0x86) ICR1[7:0] ICR1L
#define REG_ADDR_ICR1L					0x86
#define REG_ADDR_ICR1H					0x87
#define _REG_ICR1L 						(*(volatile uint8_t*)REG_ADDR_ICR1L)
#define _REG_ICR1H						(*(volatile uint8_t*)REG_ADDR_ICR1H)
#define _REG_ICR1LH 					(*(volatile uint16_t*)REG_ADDR_ICR1L)

//(0x6F) – – ICIE1 – – OCIE1B OCIE1A TOIE1 TIMSK1								Timer/Counter1 Interrupt Mask Register
#define REG_ADDR_TIMSK1					0x6F
#define _REG_TIMSK1						(*(volatile uint8_t*)REG_ADDR_TIMSK1)

//0x16 (0x36) – – ICF1 – – OCF1B OCF1A TOV1 TIFR1								Timer/Counter1 Interrupt Flag Register
#define REG_ADDR_TIFR1					0x36
#define _REG_TIFR1						(*(volatile uint8_t*)REG_ADDR_TIFR1)

// PORT MODELLINGS
// TCCR1A & TCCR1B as TCCR1AB
typedef union{
	struct {
		uint8_t wgm10  : 1; // Waveform Generation Mode Bit 0
		uint8_t wgm11  : 1; // Waveform Generation Mode Bit 1
		uint8_t reservedA : 2; // Reserved
		uint8_t com1b0 : 1; // Compare Output Mode for Channel B Bit 0
		uint8_t com1b1 : 1; // Compare Output Mode for Channel B Bit 1
		uint8_t com1a0 : 1; // Compare Output Mode for Channel A Bit 0
		uint8_t com1a1 : 1; // Compare Output Mode for Channel A Bit 1
		uint8_t clock_select : 3; // Clock Select Bit 0, 1 and 2
		uint8_t wgm12  : 1; // Waveform Generation Mode Bit 2
		uint8_t wgm13  : 1; // Waveform Generation Mode Bit 3
		uint8_t reservedB : 1; // Reserved
		uint8_t ices1  : 1; // Input Capture Edge Select
		uint8_t icnc1  : 1; // Input Capture Noise Canceler
	};
	uint16_t value;
}tccr1ab_t, *tccr1ab_ptr_t;

#define REG_TCCR1AB_UNION					(*(volatile tccr1ab_ptr_t)REG_ADDR_TCCR1A)
#define TIMER1_MODE							REG_TCCR1AB_UNION.value
#define timer1_mode_00_NORMAL				REG_TCCR1AB_UNION.value | 0x0000
#define timer1_mode_01_PWM_8_BIT			REG_TCCR1AB_UNION.value | 0x0001
#define timer1_mode_02_PWM_9_BIT			REG_TCCR1AB_UNION.value | 0x0002
#define timer1_mode_03_PWM_10_BIT			REG_TCCR1AB_UNION.value | 0x0003
#define timer1_mode_04_CTC_on_OCR1A         REG_TCCR1AB_UNION.value | 0x0800 // 2^11 = 0x0800
#define timer1_mode_05_FAST_PWM_8_BIT       REG_TCCR1AB_UNION.value | 0x0801
#define timer1_mode_06_FAST_PWM_9_BIT       REG_TCCR1AB_UNION.value | 0x0802
#define timer1_mode_07_FAST_PWM_10_BIT      REG_TCCR1AB_UNION.value | 0x0803 
#define timer1_mode_08_PWM_PF_on_ICR1       REG_TCCR1AB_UNION.value | 0x1000 // 2^12 = 0x1000
#define timer1_mode_09_PWM_PF_on_OCR1A      REG_TCCR1AB_UNION.value | 0x1001
#define timer1_mode_10_PWM_PC_on_ICR1		REG_TCCR1AB_UNION.value | 0x1002
#define timer1_mode_11_PWM_PC_on_OCR1A      REG_TCCR1AB_UNION.value | 0x1003
#define timer1_mode_12_CTC_on_ICR1          REG_TCCR1AB_UNION.value | 0x1800
#define timer1_mode_13_CTC_on_ICR1          REG_TCCR1AB_UNION.value | 0x0000
#define timer1_mode_14_FAST_PWM_ICR1        REG_TCCR1AB_UNION.value | 0x1802
#define timer1_mode_15_FAST_PWM_OCR1A       REG_TCCR1AB_UNION.value | 0x1803


#define TIMER1_clock							REG_TCCR1AB_UNION.clock_select
#define timer1_no_clock_source_STOP				0
#define timer1_prescaling_1						1
#define timer1_prescaling_8						2
#define timer1_prescaling_64					3
#define timer1_prescaling_256					4
#define timer1_prescaling_1024					5
#define timer1_ext_clock_source_FALLING_EDGE	6
#define timer1_ext_clock_source_RISING_EDGE		7


typedef union {
	struct {
		uint8_t toie1  : 1; // Timer/Counter 1, Overflow Interrupt Enable
		uint8_t ocie1a : 1; // Timer/Counter 1, Output Compare A Match Interrupt Enable
		uint8_t ocie1b : 1; // Timer/Counter 1, Output Compare B Match Interrupt Enable
		uint8_t res1   : 2; // Reserved Bits
		uint8_t icie1  : 1; // Timer/Counter 1, Input Capture Interrupt Enable
		uint8_t res2   : 2; // Reserved Bits
	};
	uint8_t byte; 
} timsk1_t, *timsk1_ptr_t;

#define REG_TIMSK1_UNION					(*(volatile timsk1_ptr_t)REG_ADDR_TIMSK1)
#define TIMER1_interrupt_OVERFLOW           REG_TIMSK1_UNION.toei1 // Overflow Interrupt Enable
#define TIMER1_interrupt_OUTPUT_COMP_A      REG_TIMSK1_UNION.ocie1a // Output Compare A Match Interrupt Enable
#define TIMER1_interrupt_OUTPUT_COMP_B      REG_TIMSK1_UNION.ocie1b // Output Compare B Match Interrupt Enable
#define TIMER1_interrupt_INPUT_CAPUTURE		REG_TIMSK1_UNION.icie1 // Input Capture Interrupt Enable

typedef union {
    struct {
        uint8_t low;  // Low byte: OCR1AL (Address 0x88) [1]
        uint8_t high; // High byte: OCR1AH (Address 0x89) [1]
    };
    uint16_t value;   // 16-bit combined value for OCR1A
} ocr1a_t, *ocr1a_ptr_t;

#define REG_OCR1A_UNION					(*(volatile ocr1a_ptr_t)REG_ADDR_OCR1AL)
#define TIMER1_OCRA_value				REG_OCR1A_UNION.value
#endif