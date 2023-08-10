#include "serv.h"
void delay_ms(uint32_t ms)
{
		uint32_t start = TIM2->CNT;  // Получаем текущее значение таймера

    while ((TIM2->CNT - start) < ms) {}
}

void delay_us(uint32_t us)
{
	uint32_t start = TIM2->CNT;  // Получаем текущее значение таймера

    // Вычисляем количество тактов для задержки в микросекундах
    uint32_t delayTicks = (SystemCoreClock / 1000000) * us;

    while ((TIM2->CNT - start) < delayTicks) {}
}

void toggle(void) 
	{
		GPIOC->BSRR = GPIO_BSRR_BS13;
		delay_ms(500);
		GPIOC->BSRR = GPIO_BSRR_BR13;
		delay_ms(500);
	}
