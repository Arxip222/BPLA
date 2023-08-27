#include "GPIO.h"

void PORTS_INIT(void) 
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		
		/*
		PA0, PA1, PA2 -- PWM output
		
		PA0 - Servo1
		PA1 - Servo2
		PA2 - MOTOR
		
		SPIx_SCK - Master PA5 (Alternate fucntion push-pull)
		SPIx_MOSI - Full duplex PA7 (Alternate function push-pull
		SPIx_MISO - Full duplex PA6 (Input floating / Input pull-up) 
		SPIx_NSS - Software PA4 (General output push-pull) 
		DIO0 - PB0 (General output push-pull) 
		RST - PB1 (General output push-pull) 
		*/
		GPIOA->CRL |= GPIO_CRL_MODE5;
		GPIOA->CRL &= ~GPIO_CRL_CNF5;
		GPIOA->CRL |= GPIO_CRL_CNF5_1;
		
		GPIOA->CRL |= GPIO_CRL_MODE7;
		GPIOA->CRL &= ~GPIO_CRL_CNF7;
		GPIOA->CRL |= GPIO_CRL_CNF7_1;
		
		GPIOA->CRL &= ~GPIO_CRL_MODE6;
		GPIOA->CRL &= ~GPIO_CRL_CNF6;
		GPIOA->CRL |= GPIO_CRL_CNF6_0;
		
		GPIOA->CRL |= GPIO_CRL_MODE4;
		GPIOA->CRL &= ~GPIO_CRL_CNF4;
		
		GPIOB->CRL |= GPIO_CRL_MODE0;
		GPIOB->CRL &= ~GPIO_CRL_CNF0;
		GPIOB->CRL |= GPIO_CRL_MODE1;
		GPIOB->CRL &= ~GPIO_CRL_CNF1;

		GPIOC->CRH &= ~GPIO_CRH_CNF13;
    GPIOC->CRH |= GPIO_CRH_MODE13;
	}
