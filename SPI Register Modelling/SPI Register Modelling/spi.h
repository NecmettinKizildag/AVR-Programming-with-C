/*
 * spi.h
 *
 * Created: 6/6/2026 4:19:42 PM
 *  Author: nec
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

/*
SPCR – SPI Control Register
0x2C (0x4C) SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0
- Bit 7 – SPIE: SPI Interrupt Enable
- Bit 6 – SPE: SPI Enable
- Bit 5 – DORD: Data Order
- Bit 4 – MSTR: Master/Slave Select
- Bit 3 – CPOL: Clock Polarity
- Bit 2 – CPHA: Clock Phase
- Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0

SPSR – SPI Status Register
0x2D (0x4D) SPIF WCOL – – – – – SPI2X
- Bit 7 – SPIF: SPI Interrupt Flag
- Bit 6 – WCOL: Write COLlision Flag
- Bit 5..1 – Res: Reserved Bits
- Bit 0 – SPI2X: Double SPI Speed Bit

SPDR – SPI Data Register
0x2E (0x4E) MSB LSB

*/

#define BASE_ADDR_SPI				0x4C

typedef struct{
	uint8_t clockRate : 2;
	uint8_t clockMode : 2;
	uint8_t master : 1;
	uint8_t dataOrder : 1;
	uint8_t spiEnable : 1;
	uint8_t spiInterruptEnable : 1;
	
	uint8_t spiDoubleSpeed : 1;
	uint8_t reserved : 5;
	uint8_t writeCollisionFlag : 1;
	uint8_t spiInterruptFlag : 1;
	
	uint8_t data : 8;
}s_spi_t, *s_spi_ptr_t;

typedef struct{
	volatile s_spi_ptr_t bits;
	}s_spi_dev, *s_spi_ptr_dev;

const s_spi_dev spi = {.bits = (volatile s_spi_ptr_t)(BASE_ADDR_SPI)};

/*
SPI Mode		Conditions			Leading Edge			Trailing eDge
0				CPOL=0, CPHA=0		Sample (Rising)			Setup (Falling)
1				CPOL=0, CPHA=1		Setup (Rising)			Sample (Falling)
2				CPOL=1, CPHA=0		Sample (Falling)		Setup (Rising)
3				CPOL=1, CPHA=1		Setup (Falling)			Sample (Rising)
*/

#define _SPI_MODE_SAMPLE_RISING_SETUP_FALLING	0
#define _SPI_MODE_SETUP_RISING_SAMPLE_FALLING	1
#define _SPI_MODE_SAMPLE_FALLING_SETUP_RISING	2
#define _SPI_MODE_SETUP_FALLING_SAMPLE_RISING	3

/*
SPI2X	SPR1	SPR0	SCK Frequency
0		0		0		fosc/4
0		0		1		fosc/16
0		1		0		fosc/64
0		1		1		fosc/128
1		0		0		fosc/2
1		0		1		fosc/8
1		1		0		fosc/32
1		1		1		fosc/64
*/

#define _SPI_PRESCLAE_4__2X_2					0
#define	_SPI_PRESCLAE_16__2X_8					1
#define	_SPI_PRESCLAE_64__2X_32					2
#define	_SPI_PRESCLAE_128__2X_64				3


#define _SPI_SLAVE								0
#define	_SPI_MASTER								1


#define	_SPI_MSB_FIRST							0
#define _SPI_LSB_FIRST							1

#define SPI										*((volatile s_spi_ptr_t)BASE_ADDR_SPI)
#define _ENABLE									1
#define _DISABLE								0	

#endif /* SPI_H_ */