#include "NVIC.h"

	void SysTick_Handler(void)
	{
		SysTick_CNT++;
	}
