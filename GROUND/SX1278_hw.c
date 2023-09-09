#include "SX1278_hw.h"

void SX1278_hw_init(void) 
	{
		SX1278_hw_SetNSS(1);
		GPIOB->BSRR = GPIO_BSRR_BS7;
	}
	
void SX1278_hw_SetNSS(int value) 
	{
		 GPIOA->BSRR = (value == 1) ? GPIO_BSRR_BS15 : GPIO_BSRR_BR15; 
		/* if (value == 1) {
			SPI1->CR1 |= SPI_CR1_SSI;
		}else{
			SPI1->CR1 &= ~SPI_CR1_SSI;
		} */
	}

void SX1278_hw_Reset(void) {
	SX1278_hw_SetNSS(1);
	GPIOB->BSRR = GPIO_BSRR_BR7;

	delay_ms(1);

	GPIOB->BSRR = GPIO_BSRR_BS7;

	delay_ms(100);
}

void SX1278_hw_SPICommand(uint8_t cmd) {
	SX1278_hw_SetNSS(0);
	SPI_Transmit(cmd);
}

uint8_t SX1278_hw_SPIReadByte(void) {
		uint8_t txByte = 0x00;
		uint8_t rxByte = 0x00;

		SX1278_hw_SetNSS(0);
		SPI_TransmitReceiveData(&txByte, &rxByte, 1);
		return rxByte;
}

		int SX1278_hw_GetDIO0(void) {
	return (GPIOB->IDR >> 6) & 0x01;
}
