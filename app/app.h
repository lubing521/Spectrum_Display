#ifndef  __APP_H
#define  __APP_H
#include "stm32f4xx_hal.h"
#include "touch.h"


void pageswitch(uint8_t *pagenum);//Ò³ÂëÇÐ»»
void appswitch(uint8_t *pagenum);//¹¦ÄÜÇÐ»»
void touchwait();
void App_y_axis_move(void);

#define plusxpos 850-60+8
#define plusypos 220+16
#define minusxpos 850-260+8
#define minusypos 220+16
#define errarea   50
#endif