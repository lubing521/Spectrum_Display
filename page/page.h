#ifndef __PAGE_H
#define __PAGE_H
#include "stm32f4xx_hal.h"
#include "typeselfdef.h"
/* ${macro:start} */
#define stx 23
#define sty 420
#define endx 853
#define endy 0
#define smallamp 40
#define mediumamp 70
#define bigamp 110
#define amperr 5
/* ${macro:end} */

void mainpage();
void graphpage();
void reportpage();
void rightarrow(uint16_t x,uint16_t y);
void leftarrow(uint16_t x,uint16_t y);

void PageShowAxis(void);
void PageSpectrumInit(uint16_t color);
void PageDisplayNumBelow_y_axis(num_display_below_y_axis t_index, char* t_shownum);
void PageMoveNumBelow_y_axis(void);
void PageClearAreaBelow_y_axis(void);
void PageDisplaySpectrum(uint16_t t_index, uint32_t t_value, uint16_t t_color);
void PageMoveSpectrum(uint16_t t_color);
void PageClearSpectrumArea(void);

#endif  /* _PAGE_H_ */