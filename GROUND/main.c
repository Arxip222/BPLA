#include "main.h"
	int main(void)
	{
		int master;
		int ret;
		int message = 10;
		uint8_t message_length;
		char buffer[512];
		SX1278_t SX1278;
		uint16_t x = 0;
		uint16_t y = 0;
		uint16_t speed = 0;
		PORTS_INIT();
		SysTick_INIT();
		ADC_DMA_INIT();
		SPI_INIT();
		master = 1;
		/*LCD_INIT();
		setPos(0,0);
		delay_ms(200);
		sendbyte(0x2A, 0);
		delay_ms(200);
		sendbyte(CLEAR_DISPLAY, 0);
		delay_ms(100);*/
		
		SX1278_init(&SX1278, 434000000, SX1278_POWER_17DBM, SX1278_LORA_SF_7,
	SX1278_LORA_BW_125KHZ, SX1278_LORA_CR_4_5, SX1278_LORA_CRC_EN, 10);
	if (master == 1) {
		ret = SX1278_LoRaEntryTx(&SX1278, 16, 2000);
		GPIOC->BSRR = GPIO_BSRR_BR13;
	} else {
		ret = SX1278_LoRaEntryRx(&SX1278, 16, 2000);
		GPIOC->BSRR = GPIO_BSRR_BS13;
	}
	
		while(1)
		{	
			/*x = adc_buffer[0];//Стик OX
			y = adc_buffer[1];//Стик ОY
			speed = adc_buffer[2];//Значение скорости
			SPI_SEND(x);*/
			if (master == 1) {
			message_length = sprintf(buffer, "%d", message);
			ret = SX1278_LoRaEntryTx(&SX1278, message_length, 2000);
			
			ret = SX1278_LoRaTxPacket(&SX1278, (uint8_t*) buffer, message_length, 2000);
			
			message += 1;
		} else {
			delay_ms(800);
			ret = SX1278_LoRaRxPacket(&SX1278);
			if (ret > 0) {
				SX1278_read(&SX1278, (uint8_t*) buffer, ret);
			}
		}

		/* change mode 
		if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(MODE_GPIO_Port, MODE_Pin)) {
			printf("Changing mode\r\n");
			master = ~master & 0x01;
			if (master == 1) {
				ret = SX1278_LoRaEntryTx(&SX1278, 16, 2000);
				GPIOC->BSRR = GPIO_BSRR_BR13;
			} else {
				ret = SX1278_LoRaEntryRx(&SX1278, 16, 2000);
				GPIOC->BSRR = GPIO_BSRR_BS13;
			}
			delay_ms(1000);
			while (GPIO_PIN_RESET == HAL_GPIO_ReadPin(MODE_GPIO_Port, MODE_Pin))
				;
		}*/

	}
	}
