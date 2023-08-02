#include "main.h"
	int main(void)
	{
		uint16_t x = 0;
		uint16_t y = 0;
		uint16_t speed = 0;
		PORTS_INIT();
		SysTick_INIT();
		ADC_DMA_INIT();
		/*SPI_INIT();
		TIMERS_PWM_INIT();
		LCD_INIT();
		setPos(0,0);
		delay_ms(200);
		sendbyte(0x2A, 0);
		delay_ms(200);
		sendbyte(CLEAR_DISPLAY, 0);
		delay_ms(100);*/
		
		while(1)
		{	
			/*x = adc_buffer[0];//Стик OX
			y = adc_buffer[1];//Стик ОY
			speed = adc_buffer[2];//Значение скорости
			SPI_SEND(x);*/
			toggle();
		}
	}
