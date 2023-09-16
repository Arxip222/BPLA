#ifndef SPI_H
#define SPI_H

#include "serv.h"
void SPI_INIT(void);
void SPI_TransmitReceive(uint8_t *pTxData, uint8_t *pRxData, uint16_t Size);
void SPI_Transmit(uint8_t data);
#endif
