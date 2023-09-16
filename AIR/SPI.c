#include "SPI.h"

void SPI_INIT(void) 
	{
		SPI1->CR1 = 0;
		SPI1->CR1 &= ~(SPI_CR1_CPOL | SPI_CR1_CPHA); //Clock and phase tuning (from Laura's datasheet)
		SPI1->CR1 |= SPI_CR1_MSTR; //Master Mode
		SPI1->CR1 |= SPI_CR1_BR_0; //Baud rate control Fpclk/4
		SPI1->CR1 &= ~SPI_CR1_LSBFIRST; //MSB first
		SPI1->CR1 &= ~SPI_CR1_DFF; //8-bit fprmat transmitter
		SPI1->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI; // SSM = 1 - software contol NSS, SSI = 1 - SSI to high
		SPI1->CR1 &= ~SPI_CR1_CRCNEXT; //CRC transfer next disable
		SPI1->CR1 &= ~SPI_CR1_CRCEN; //Hardware CRC calculation disable
		SPI1->CR1 &= ~SPI_CR1_RXONLY; //Receive only
		SPI1->CR1 &= ~SPI_CR1_BIDIMODE; //1-line data mode
		SPI1->CR1 |= SPI_CR1_SPE; //ON SPI
		
		SPI1->CR2 &= ~SPI_CR2_RXDMAEN; //Rx DMA disable
		SPI1->CR2 &= ~SPI_CR2_TXDMAEN; //Tx DMA disable
		SPI1->CR2 &= ~SPI_CR2_SSOE; //SS output disable
		SPI1->CR2 &= ~SPI_CR2_ERRIE; //Err interrupt disable
		SPI1->CR2 |= SPI_CR2_RXNEIE; //Rx not empty interrupt enable
		SPI1->CR2 &= ~SPI_CR2_TXEIE; //Tx interrupt disable
	}

void SPI_TransmitReceive(uint8_t *pTxData, uint8_t *pRxData, uint16_t Size) {
	uint16_t i;
    for (i = 0; i < Size; i++) {
        while (!(SPI1->SR & SPI_SR_TXE));

        SPI1->DR = pTxData[i];

        while (!(SPI1->SR & SPI_SR_RXNE));

        pRxData[i] = SPI1->DR;
    }

    while (SPI1->SR & SPI_SR_BSY);
}

void SPI_Transmit(uint8_t data) {

	while ((SPI1->SR & SPI_SR_TXE) == 0);

	SPI1->DR = data;

  while ((SPI1->SR & SPI_SR_BSY) != 0);
}
