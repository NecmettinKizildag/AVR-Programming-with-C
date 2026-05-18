/*
 * Introduction to PWM.c
 *
 * Created: 5/18/2026 5:08:56 PM
 * Author : nec
 */ 


#include "328p_config.h"
#include <avr/interrupt.h>

#define OCR_v					19999 // 10 ms on prescale 8

volatile uint16_t ocr_v;
volatile uint16_t on_time, off_time;
volatile uint8_t flag;

void swap(volatile uint16_t* on_time, volatile uint16_t* off_time);

static void gpio_init(){
	DDRD_UNION.port = PORT_ALL_OUTPUT;
	PORTD_UNION.port = PORT_ALL_HIGH;
}

static void timer1_init(){
	TIMER1_MODE = timer1_mode_04_CTC_on_OCR1A;
	TIMER1_clock = timer1_prescaling_8;
	TIMER1_interrupt_OUTPUT_COMP_A = interrupt_ENABLE;
	TIMER1_OCRA_value = OCR_v;
}

ISR(TIMER1_COMPA_vect)
{
	off_time = OCR_v - on_time;
	
	if (flag == 0)
	{
		PORTD_UNION.port = PORT_ALL_HIGH;
	}
	else
	{
		PORTD_UNION.port = PORT_ALL_LOW;
	}
	
	//TIMER1_OCRA_value = on_time;
	
	flag ^= (1 << 0);
	swap(&on_time, &off_time);
}

void swap(volatile uint16_t* on_time, volatile uint16_t* off_time){
	volatile uint16_t* temp = on_time;
	on_time = off_time;
	off_time = temp;
}

int main(void)
{
	gpio_init();
	timer1_init();
	sei();
	
	on_time = 1900;
	
	flag = 0;
	
	while (1)
	{
	}
}
