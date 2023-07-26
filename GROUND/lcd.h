#ifndef LCD_H
#define LCD_H
#include "serv.h"
void sendStr(char *str);
void LCD_INIT(void);
void sendbyte(int8_t c, int8_t mode);
void setPos(int8_t row, int8_t col);
void sendhalfbyte(int8_t hb);

#endif
