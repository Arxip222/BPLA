#include "main.h"

int main(void){
	
	int master;
	int ret;
	char buffer[512];
	SX1278_t SX1278;
	
	PORTS_INIT();
	SysTick_INIT();
	SPI_INIT();
	master = 0;
	
	SX1278_init(&SX1278, 434000000, SX1278_POWER_17DBM, SX1278_LORA_SF_6,
	SX1278_LORA_BW_125KHZ, SX1278_LORA_CR_4_5, SX1278_LORA_CRC_DIS, 10);
	if (master == 1) {
		ret = SX1278_LoRaEntryTx(&SX1278, 16, 2000);
		GPIOC->BSRR = GPIO_BSRR_BR13;
	} else {
		ret = SX1278_LoRaEntryRx(&SX1278, 16, 2000);
		GPIOC->BSRR = GPIO_BSRR_BS13;
	}
	
	while (1) {
		if (master == 1) {
			char message[] = "Hello";
      memcpy(buffer, message, sizeof(message));
			ret = SX1278_LoRaEntryTx(&SX1278, sizeof(message), 2000);
			
			ret = SX1278_LoRaTxPacket(&SX1278, (uint8_t*) buffer, sizeof(message), 2000);
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
