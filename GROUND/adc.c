#include "adc.h"

uint16_t adc_buffer[ADC_BUFFER_SIZE];

void ADC_DMA_INIT(void)
	{
		
		DMA1_Channel1->CPAR = (uint32_t)&(ADC1->DR);
		DMA1_Channel1->CMAR = (uint32_t)&adc_buffer;
		DMA1_Channel1->CNDTR = ADC_BUFFER_SIZE;
		DMA1_Channel1->CCR &= ~DMA_CCR1_PL; //LOW priority
		DMA1_Channel1->CCR &= ~DMA_CCR1_DIR;
		DMA1_Channel1->CCR |= DMA_CCR1_CIRC;
		DMA1_Channel1->CCR |= DMA_CCR1_PSIZE_0;
		DMA1_Channel1->CCR &= ~DMA_CCR1_PSIZE_1;
		DMA1_Channel1->CCR |= DMA_CCR1_MSIZE_0;
		DMA1_Channel1->CCR &= ~DMA_CCR1_MSIZE_1;
		DMA1_Channel1->CCR &= ~DMA_CCR1_TCIE;
		DMA1_Channel1->CCR &= ~DMA_CCR1_HTIE;
		DMA1_Channel1->CCR |= DMA_CCR1_TEIE;
		DMA1_Channel1->CCR |= DMA_CCR1_MINC;
		DMA1_Channel1->CCR |= DMA_CCR1_EN;
		NVIC_EnableIRQ(DMA1_Channel1_IRQn);
		
		
		ADC1->CR1 &= ~ADC_CR1_EOCIE; //Interrupt disable
		ADC1->CR1 &= ~ADC_CR1_AWDIE; //Watchdog interrupt disable
		ADC1->CR1 &= ~ADC_CR1_JEOCIE; //Injected channels interrupt disable
		ADC1->CR1 &= ~ADC_CR1_SCAN; //Scan mode disable
		ADC1->CR1 &= ~ADC_CR1_AWDSGL; //Analog watchgod disable
		ADC1->CR1 &= ~ADC_CR1_JAUTO; //Automatic injected group disable
		ADC1->CR1 &= ~ADC_CR1_DISCEN; //Discontinuous mode disable
		ADC1->CR1 &= ~ADC_CR1_JDISCEN; // Discontinuius mode for injected disable
		ADC1->CR1 |= ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_2;//Dual mode for regular
		ADC1->CR1 &= ~(ADC_CR1_DUALMOD_0 | ADC_CR1_DUALMOD_3);//Dual mode for regular
		ADC1->CR1 &= ~ADC_CR1_JAWDEN; //Disable analog watchdog for injected
		ADC1->CR1 &= ~ADC_CR1_AWDEN; //Disable analog watchdog for regular
		
		ADC1->CR2 |= ADC_CR2_ADON; //Enable ADC converter
		ADC1->CR2 |= ADC_CR2_CONT; //Continuous conversion mode
		
		ADC1->CR2 |= ADC_CR2_CAL; // ADC calibration
		
		while (ADC1->CR2 & ADC_CR2_CAL);
		delay_ms(1);
		
		ADC1->CR2 |= ADC_CR2_DMA; //DMA enable
		ADC1->CR2 &= ~ADC_CR2_ALIGN; //Right alignment
		ADC1->CR2 |= ADC_CR2_EXTSEL; //Software start mode
		ADC1->CR2 &= ~ADC_CR2_EXTTRIG; //Conversion on external event disabled
		ADC1->CR2 &= ~ADC_CR2_TSVREFE; //Temperature sensor disabled
		//NVIC_EnableIRQ(ADC1_2_IRQn);
		
		ADC1->SMPR2 |= ADC_SMPR2_SMP0; //Activate ADC1_0
		ADC1->SMPR2 |= ADC_SMPR2_SMP1; //Activate ADC1_1
		ADC1->SMPR2 |= ADC_SMPR2_SMP2; //Activate ADC1_2
		ADC1->SQR1 &= ~ADC_SQR1_L; //3 conversion
		ADC1->SQR1 |= ADC_SQR1_L_1;
		ADC1->SQR3 &= ~ADC_SQR3_SQ1;//First conversation - A0
		ADC1->SQR3 &= ~ADC_SQR3_SQ2;//Second conversation - A1
		ADC1->SQR3 &= ~ADC_SQR3_SQ3;//Third conversation - A2
		ADC1->SQR3 |= ADC_SQR3_SQ2_0;
		ADC1->SQR3 |= ADC_SQR3_SQ3_1;
		ADC1->CR2 |= ADC_CR2_SWSTART;
	}
