#ifndef _328P_GPIO_H
#define _328P_GPIO_H

#ifndef _STDINT_H_
#include <stdint.h>
#endif
// Register Addresses of GPIO Ports
#define REG_ADDR_GPIO_B				0x23
#define REG_ADDR_GPIO_C				0x26
#define REG_ADDR_GPIO_D				0x29

typedef struct{
	uint8_t pin0 : 1;
	uint8_t pin1 : 1;
	uint8_t pin2 : 1;
	uint8_t pin3 : 1;
	uint8_t pin4 : 1;
	uint8_t pin5 : 1;
	uint8_t pin6 : 1;
	uint8_t pin7 : 1;
} pin_t, *pin_ptr_t;

typedef union{
	pin_t pins;
	uint8_t value; 
}_gpio_t, *_gpio_ptr_t;

/*
typedef struct{
	port_t pinb;
	port_t ddrb;
	port_t portb;
	
	port_t pinc;
	port_t ddrc;
	port_t portc;
	
	port_t pind;
	port_t ddrd;
	port_t portd;	
}gpio_t, *gpio_ptr_t;
*/
typedef struct{
	_gpio_t pin;
	_gpio_t ddr;
	_gpio_t port; 
}gpio_t, *gpio_ptr_t;

#define GPIO_B					(*(volatile gpio_ptr_t)REG_ADDR_GPIO_B)
#define GPIO_C					(*(volatile gpio_ptr_t)REG_ADDR_GPIO_C)
#define GPIO_D					(*(volatile gpio_ptr_t)REG_ADDR_GPIO_D)

//GPIO_B.ddr.value = port_ALL_OUTPUT
//GPIO_B.port.pins.pin0 = pin_HIGH sample usage

#define pin_INPUT				1
#define pin_OUTPUT				0
#define	port_ALL_INPUT			0x00
#define	port_ALL_OUTPUT			0xFF
#define pin_LOW					0
#define pin_HIGH				1
#define port_ALL_LOW			0x00
#define port_ALL_HIGH			0xFF
#define pin_PULLUP_OFF			0
#define pin_PULLUP_ON			1
#define port_ALL_PULLUP_OFF		0x00
#define port_ALL_PULLUP_ON		0xFF

#endif // _328P_GPIO_H