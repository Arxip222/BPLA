#include "NVIC.h"

	void SysTick_Handler(void)
	{
		SysTick_CNT++;
	}
	
/*
	void ADC1_2_IRQHandler(void) 
	{
	Counter_ADC++;
	if (READ_BIT(ADC1->SR, ADC_SR_EOC)) 
		{
		ADC1->DR;
		}
	}
*/
		