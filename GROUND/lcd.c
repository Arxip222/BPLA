#include "lcd.h"

	
	void LCD_INIT(void)
	{
		GPIOA->BSRR = (GPIO_BSRR_BR0 | GPIO_BSRR_BR1 | GPIO_BSRR_BR4 | GPIO_BSRR_BR5 | GPIO_BSRR_BR6 | GPIO_BSRR_BR7);
		delay_ms(20);
		sendhalfbyte(0x30);
		delay_us(40);
    sendhalfbyte(0x30);
    delay_us(40);
    sendhalfbyte(0x30);
    delay_us(5);
    sendbyte(0x20, 0);
		delay_ms(20);
    sendbyte(0x28, 0);
		delay_ms(20);
    sendbyte(0x0C, 0);
		delay_ms(20);
    sendbyte(0x06, 0);
		delay_ms(20);
		LCD_PINS0;
	}
	
	void sendStr(char *str)
	{
		while(*str != '\0'){
		sendbyte(*str, 1);
			delay_ms(1);
		str++;
		}
	}
	
	void sendhalfbyte(int8_t hb)
	{
		LCD_PINS0;
		delay_us(500);
		E1;
		delay_us(500);
		GPIOA->BSRR = hb & 0xF0;
		E0;
		delay_us(500);
	}
	
	void sendbyte(int8_t b, int8_t mode)
	{
		if (mode == 1) A1;
		else A0;
		delay_ms(1);
		sendhalfbyte(b);
		delay_ms(1);
		sendhalfbyte(b << 4);
		delay_ms(10);
		LCD_PINS0;
	}
	
	void setPos(int8_t row, int8_t col)
	{
		int8_t address = row*0x40;
		address |= col;
		sendbyte(0x80 | address, 0);
	}
	