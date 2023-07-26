#include "RCC.h"

	
uint32_t SysTick_CNT;

	void SysTick_INIT(void)
	{
		 SysTick->LOAD = SystemCoreClock / 1000 - 1; // Загрузка значения для 1 мс
    SysTick->VAL = 0; // Сброс текущего значения
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk; // Включение таймера с источником тактовой частоты CPU
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk; // Включение прерывания от таймера
		NVIC_EnableIRQ(SysTick_IRQn);
	}
	