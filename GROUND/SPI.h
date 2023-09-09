#ifndef SPI_H
#define SPI_H

#include "serv.h"

void SPI_INIT(void);
void SPI_TransmitReceiveData(uint8_t* tx_data, uint8_t* rx_data, uint16_t size);
void SPI_Transmit(uint8_t data);
#endif
