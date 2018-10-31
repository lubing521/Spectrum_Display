#ifndef __GUI_H__
#define __GUI_H__

#include "stm32f4xx_hal.h"

void  Gui_Draw_aPixel(uint16_t ,uint16_t ,uint16_t );
void  Gui_Draw_Line(uint16_t , uint16_t , uint16_t , uint16_t , uint16_t );
void  Gui_Circle(uint16_t ,uint16_t ,uint16_t ,uint16_t ); 
void  Gui_Draw_Rect(uint16_t , uint16_t , uint16_t , uint16_t , uint16_t );
void 	LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num,uint8_t size);
void  showhz(uint16_t x, uint16_t y, uint8_t num,uint8_t size);

#endif

