#ifndef _328P_E_INTERRUPTS_H_
#define _328P_E_INTERRUPTS_H_

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

#endif //_328P_E_INTERRUPTS_H_