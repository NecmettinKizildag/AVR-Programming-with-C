/*
 * Timer1 Sample.c
 *
 * Created: 5/18/2026 1:40:26 PM
 * Author : nec
 */ 

/*
F_CPU 16 MHz
Required Delay : 1000 ms
Calculation : 1/256 prescaling - 62499 compare value

Required Delay : 20 ms
Calculation : 1/8 prescaling - 39999 compare value

1. Select Timer1 Mode - CTC on OCRA
2. Select Timer1 Clock - 1/256 prescaling
3. Enable Timer1 compare match a Inetrrupt
4. Set ORC1A Value
5. Enable Global Interrupt

1.set D port as OUTPUT
2.set all pins as LOW 
*/

#include "328p_config.h"
#include <avr/interrupt.h>

volatile uint16_t ocr_v; 

static void gpio_init(){
	DDRD_UNION.port = PORT_ALL_OUTPUT;
	PORTD_UNION.port = PORT_ALL_HIGH;
}

static void timer1_init(){
	TIMER1_MODE = timer1_mode_04_CTC_on_OCR1A;
	TIMER1_clock = timer1_prescaling_8;
	TIMER1_interrupt_OUTPUT_COMP_A = interrupt_ENABLE;
	TIMER1_OCRA_value =ocr_v;
	sei();
}

ISR(TIMER1_COMPA_vect)
{
	PORTD_UNION.port ^= PORT_ALL_HIGH;
	ocr_v = (ocr_v >= 0) ? ocr_v-1000 : ocr_v;
	TIMER1_OCRA_value = ocr_v;
}

int main(void)
{
    gpio_init();
	timer1_init();
	sei();
	ocr_v = 39999;
	
    while (1) 
    {
    }
}