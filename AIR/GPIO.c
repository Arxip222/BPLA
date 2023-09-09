#include "GPIO.h"

void PORTS_INIT(void) 
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
		RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		
		/*
		PA0, PA1, PA2 -- PWM output
		
		PA0 - Servo1
		PA1 - Servo2
		PA2 - MOTOR
		
		Pin settings SPI1 SCK (PA5) Master - Alternate function push-pull */
    GPIOA->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);
    GPIOA->CRL |= GPIO_CRL_MODE5 | GPIO_CRL_CNF5_1;

    /* Pin settings SPI1 MISO (PA6)  Full duplex / master - Input floating / Input pull-up */
    GPIOA->CRL &= ~(GPIO_CRL_MODE6 | GPIO_CRL_CNF6);
    GPIOA->CRL |= GPIO_CRL_CNF6_0;

    /* Pin settings SPI1 MOSI (PA7) Full duplex / master - Alternate function push-pull */
    GPIOA->CRL &= ~(GPIO_CRL_MODE7 | GPIO_CRL_CNF7);
    GPIOA->CRL |= GPIO_CRL_MODE7 | GPIO_CRL_CNF7_1;

    /* Pin settings NSS (PA4) Hardware master / slave - General purpose output - Push-pull */
    GPIOA->CRL &= ~(GPIO_CRL_MODE4 | GPIO_CRL_CNF4);
    GPIOA->CRL |= GPIO_CRL_MODE4;
    GPIOA->BSRR = GPIO_BSRR_BS4;
	
		/* DIO0 (PA1) - Floating input */
		GPIOA->CRL &= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1);
		GPIOA->CRL |= GPIO_CRL_CNF1_0;

		/* Pin settings RST (PA2) - General GPIO */
		GPIOA->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);
		GPIOA->CRL |= GPIO_CRL_MODE2;
		GPIOA->BSRR = GPIO_BSRR_BS2;
		
		/*
		RST
		0 - reset
		1 - working
		
		DIO0 - READ
		*/
		GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13);
    GPIOC->CRH |= GPIO_CRH_MODE13;
	}
