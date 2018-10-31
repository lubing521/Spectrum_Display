#ifndef __PAGE_H
#define __PAGE_H
#include "stm32f4xx_hal.h"
void mainpage();
void graphpage();
void showaxis();
void reportpage();
void rightarrow(uint16_t x,uint16_t y);
void leftarrow(uint16_t x,uint16_t y);
#define stx 100
#define sty 420
#define endx 853-100
#define endy 180
#define smallamp 40
#define mediumamp 70
#define bigamp 110
#define amperr 5
#endif