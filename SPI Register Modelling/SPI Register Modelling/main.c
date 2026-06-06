/*
 * SPI Register Modelling.c
 *
 * Created: 6/6/2026 4:18:57 PM
 * Author : nec
 */ 

#include "spi.h"

#define SPI_BUSY		spi.bits->spiInterruptFlag == _DISABLE
void _spi_MasterInit(void);
void _spi_MasterTransmit(uint8_t u8Data);

int main(void)
{
    //SPI.clockRate = _SPI_PRESCLAE_4__2X_2;
    //SPI.mode = _SPI_MODE_SAMPLE_RISING_SETUP_FALLING;
	
	//spi.bits->clockRate = _SPI_PRESCLAE_64__2X_32; // 250kHz
	
	_spi_MasterInit();
	
    while (1) 
    {
		
    }
}

void _spi_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	//spi.bits->
	
	/* Enable SPI, Master, set clock rate fck/64 */
	spi.bits->clockRate = _SPI_PRESCLAE_64__2X_32;
	spi.bits->master = _SPI_MASTER;
	spi.bits->spiEnable = _ENABLE;
}
void _spi_MasterTransmit(uint8_t u8Data)
{
	/* Start transmission */
	spi.bits->data = u8Data;
	
	/* Wait for transmission complete */
	while(SPI_BUSY)
	{
		
	}
	
}