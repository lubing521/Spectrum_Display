#ifndef _SHOWPICTURE_H_
#define _SHOWPICTURE_H_

#include "stm32f4xx_hal.h"

#include "lcd_drive.h"

void LcdShowPicture(uint16_t t_x, uint16_t t_y, uint16_t t_wide, uint16_t t_high, uint8_t *t_pic);
void LcdShowIconName(uint16_t t_x, uint16_t t_y, uint8_t * t_string);

#endif /* _SHOWPICTURE_H_ */
