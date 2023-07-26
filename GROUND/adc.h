#ifndef ADC_H
#define ADC_H
#include "serv.h"
#define ADC_BUFFER_SIZE 3
void ADC_DMA_INIT(void);
extern uint16_t adc_buffer[ADC_BUFFER_SIZE];
#endif
