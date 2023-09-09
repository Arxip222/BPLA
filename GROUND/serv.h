#ifndef SERV_H
#define SERV_H

#include "stm32f10x.h"
#include "RCC.h"
#include "GPIO.h"
#include "SPI.h"
#include "adc.h"
#include "lcd.h"
#include "RCC.h"
#include "NVIC.h"
#include "SX1278.h"
#include "SX1278_hw.h"

#define SYSLOCK 72000000U
#define E1 GPIOB->BSRR = GPIO_BSRR_BS1
#define E0 GPIOB->BSRR = GPIO_BSRR_BR1
#define A1 GPIOB->BSRR = GPIO_BSRR_BS0
#define A0 GPIOB->BSRR = GPIO_BSRR_BR0
#define LCD_PINS0 GPIOA->BSRR = (GPIO_BSRR_BR4 | GPIO_BSRR_BR5 | GPIO_BSRR_BR6 | GPIO_BSRR_BR7)
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x2
#define ENTRY_MODE_SET 0x6 
#define DISPLAY_ON 0xC 
#define DISPLAY_OFF 0x8
#define CURSOR_SHIFT_LEFT 0x10
#define CURSOR_SHIFT_RIGHT 0x14
#define DISPLAY_SHIFT_LEFT 0x18
#define DISPLAY_SHIFT_RIGHT 0x1C
#define DATA_BUS_4BIT_PAGE0 0x28
#define DATA_BUS_4BIT_PAGE1 0x2A
#define DATA_BUS_8BIT_PAGE0 0x38
#define SET_CGRAM_ADDRESS 0x40
#define SET_DDRAM_ADDRESS 0x80

void delay_ms(uint32_t ms);
void delay_us(uint32_t us);
void toggle(void);
#endif
