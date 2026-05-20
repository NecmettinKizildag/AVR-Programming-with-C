/*
 * Timer1 and PWM Example.c
 *
 * Created: 5/19/2026 3:37:28 PM
 * Author : nec
 */ 
#ifndef F_CPU
#define F_CPU 16000000
#endif

#include "Source/328p_config.h"
#include <avr/interrupt.h>

#define OCRA_v						33999
#define LED_COUNT 8

static void gpio_init();
static void pcint_init();
static void timer1_init();

volatile uint16_t on_time = 0;
volatile uint16_t off_time = OCRA_v;
volatile uint8_t flag = 0;
volatile uint8_t led_no = 0;

int main(void)
{
    gpio_init();
    pcint_init();
    timer1_init();
	sei();
	
    while (1) 
    {
		
    }
}


static void gpio_init()
{
	GPIO_D.ddr.value = port_ALL_OUTPUT;
	GPIO_D.port.value = port_ALL_LOW;
	
	GPIO_B.ddr.pins.pin5 = pin_INPUT;
	GPIO_B.port.pins.pin5 = pin_HIGH; // Pull-up active
}

static void pcint_init()
{
	PCINT_port.portb = interrupt_ENABLE;
	PCINT_pin.pcint_pb5 = interrupt_ENABLE;
}

static void timer1_init()
{
	TIMER1_MODE = timer1_mode_04_CTC_on_OCR1A;
	TIMER1_clock = timer1_prescaling_8;
	TIMER1_interrupt_OUTPUT_COMP_A = interrupt_ENABLE;
	//TIMER1_OCRA_value = OCRA_v;
	TIMER1_OCRA_value = on_time;
	//ICR1 = OCRA_v; // Top value
}

ISR(PCINT0_vect) {
	
    if (GPIO_B.pin.pins.pin5 == 1) // 0 for pull-up
	{
        GPIO_D.port.value = port_ALL_LOW;
        on_time = 0;
        led_no = (led_no < LED_COUNT - 1) ? led_no + 1 : 0;
    }
	
}

ISR(TIMER1_COMPA_vect){ //PB5 -  pin 13 on arduino
	on_time = (on_time < OCRA_v) ? on_time + 50 : 0;
	off_time = OCRA_v - on_time;
	
	if (flag == 0)
	{
		GPIO_D.port.value |= (1 << led_no);
		TIMER1_OCRA_value = on_time;
	}
	else
	{
		GPIO_D.port.value &= ~(1 << led_no);
		TIMER1_OCRA_value = off_time;
	}
	
	flag ^= 1;
}