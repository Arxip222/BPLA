#include "serv.h"
void delay_ms(uint32_t ms)
{
		SysTick_CNT = ms;
		while (SysTick_CNT){}
}

void delay_us(uint32_t us)
{
	uint32_t startTick = SysTick->VAL;
  uint32_t endTick = startTick - (us * (SystemCoreClock / 1000000));
   if (endTick > startTick) 
	 {
			while (SysTick->VAL > endTick) {}
   }

   while (SysTick->VAL < endTick) {}
}

void toggle(void) 
	{
		GPIOC->BSRR = GPIO_BSRR_BS13;
		delay_ms(500);
		GPIOC->BSRR = GPIO_BSRR_BR13;
		delay_ms(500);
	}
