#ifndef NVIC_H
#define NVIC_H

#include "serv.h"
static volatile int32_t Counter_ADC = 0;
void SysTick_Handler(void);
void ADC1_2_IRQHandler(void);
#endif
