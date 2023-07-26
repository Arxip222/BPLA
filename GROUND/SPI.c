#include "SPI.h"

void SPI_INIT(void) 
	{
		SPI1->CR1 &= ~(SPI_CR1_CPOL | SPI_CR1_CPHA); // CPOL = 0 & CPHA = 0
		SPI1->CR1 |= SPI_CR1_MSTR;  //Master mode
		SPI1->CR1 |= SPI_CR1_BR_0 | SPI_CR1_BR_1;// Prescaler 4
		SPI1->CR1 &= ~SPI_CR1_LSBFIRST; // MSB transmitted first
		SPI1->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI; // NSS software
		SPI1->CR1 &= ~SPI_CR1_RXONLY; // Full duplex
		SPI1->CR1 |= SPI_CR1_DFF; // 16-bit transmission
		SPI1->CR1 &= ~SPI_CR1_CRCNEXT; // no CRC phase
		SPI1->CR1 &= ~SPI_CR1_CRCEN; // CRC calculation disable
		SPI1->CR1 &= ~SPI_CR1_BIDIMODE; // no bidimode (одна линия в обе стороны)
		SPI1->CR1 |= SPI_CR1_SPE; // Enable SPI
		
		SPI1->CR2 &= ~SPI_CR2_RXDMAEN; // RX DMA disable
		SPI1->CR2 &= ~SPI_CR2_TXDMAEN; // TX DMA disable
		SPI1->CR2 &= ~SPI_CR2_SSOE;
		SPI1->CR2 &= ~SPI_CR2_ERRIE; // Error interrupt disable
		SPI1->CR2 &= ~SPI_CR2_RXNEIE; // Rx buf. not empty interrupt disable
		SPI1->CR2 &= ~SPI_CR2_TXEIE; // Tx buf. not empty interrupt dusable
	}

void SPI_SEND(uint16_t data) {
	
    while (!(SPI1->SR & SPI_SR_TXE));

    SPI1->DR = data;
}
