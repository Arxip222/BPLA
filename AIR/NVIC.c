#include "NVIC.h"

	void SysTick_Handler(void)
	{
		if (SysTick_CNT > 0) {
        SysTick_CNT--;
    }
	}
