#include "PWM.h"

void setMotorSpeed(int speed)
	{
				TIM2->CCR3 = 1000 + speed * 10;
	}
	
	void controllEleron(int grad, int pos)
	{
		int curGrad = 45 + grad;
		double res = 450 + curGrad * 23.3;
		switch(pos)
			{
			case 0:
				TIM2->CCR1 = res;
				break;
			
			case 1:
				TIM2->CCR2 = res;
				break;
			}
	}		
	
	void TIMERS_PWM_INIT(void)
	{
    TIM2->PSC = 71;
    TIM2->ARR = 19999;
		TIM2->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;
		TIM2->CCMR1 &= ~(TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC2M_0);
		TIM2->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E;
		TIM2->CR1 |= TIM_CR1_CEN;	
		delay_ms(100);
		TIM2->CCR1 = 1500;
		TIM2->CCR2 = 1500;
		TIM2->CCR3 = 1000;
		
	}