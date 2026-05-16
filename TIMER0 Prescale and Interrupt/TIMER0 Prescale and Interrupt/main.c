/*
 * TIMER0 Prescale and Interrupt.c
 *
 * Created: 5/16/2026 6:48:25 PM
 * Author : nec
 */ 

#include "328p_config.h"
#include <avr/interrupt.h>

static void gpio_init();
static void timer0_init();

volatile uint16_t overflow;
volatile uint8_t led_no;



int main(void)
{
    gpio_init();
	timer0_init();
	
	overflow = 0;
	led_no = 0;
	
    while (1) 
    {
    }
}

static void gpio_init(){
	DDRD_UNION.port = PORT_ALL_OUTPUT;
	PORTD_UNION.port = PORT_ALL_LOW;
}

#define reset_TIMER0_COUNTER	6
 
static void timer0_init(){
	//TIMER0_MODE_SELECT = timer0_mode_NORMAL;
	//TIMER0_CLOCK_SELECT = timer0_no_prescaling_START;
	//TIMER0_CLOCK_SELECT = timer0_prescaling_1024;
	TIMER0_counter = reset_TIMER0_COUNTER; // timer counter = 249, reset value 6, overflow is 3200, delay is 50 ms  
	//TIMER0_mode_NORMAL_no_presacling();
	TIMER0_mode_NORMAL_presacling_1024();
	TIMER0_interrupt_overflow = interrupt_ENABLE;
	sei();
}

ISR(TIMER0_OVF_vect){ // without using overflow
	
	PORTD_UNION.port ^= (1 << led_no);
	led_no++;
	
	led_no = (led_no > 7) ? 0 : led_no;
	
	TIMER0_counter = reset_TIMER0_COUNTER;
}

/*
ISR(TIMER0_OVF_vect){
	overflow++;
	
	if (overflow >= 3200)
	{
		overflow = 0;
		PORTD_UNION.port ^= (1 << led_no);
		led_no++;
	}
	
	led_no = (led_no > 7) ? 0 : led_no;
	
	TIMER0_counter = reset_TIMER0_COUNTER;
}
*/