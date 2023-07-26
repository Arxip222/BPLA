#include "serv.h"
void delay_ms(uint32_t ms)
{
		uint32_t start_time = ms;
		while ((SysTick_CNT - start_time) < ms){}
}

void delay_us(uint32_t us)
{
    uint32_t start_time = SysTick->VAL;
    uint32_t ticks = us * (SystemCoreClock / 1000000);
    while ((start_time - SysTick->VAL) < ticks){}
}

void toggle(void) 
	{
		 if ((GPIOC->ODR & GPIO_ODR_ODR13) == 0) 
			{
				GPIOC->BSRR = GPIO_BSRR_BS13;
			} 
		 else 
		  {
				GPIOC->BSRR = GPIO_BSRR_BR13;
			}
	}
