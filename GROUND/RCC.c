#include "RCC.h"

	void TIM2_INIT(void)
	{
    // Включение тактирования для TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Настройка предделителя и периода
    // Таймер будет считать миллисекунды и период будет равен 1 миллисекунде
    TIM2->PSC = (SystemCoreClock / 1000) - 1;
    TIM2->ARR = 1;

    // Включение таймера
    TIM2->CR1 |= TIM_CR1_CEN;
	}
	