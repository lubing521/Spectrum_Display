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
void PageSpectrumInit(uint16_t t_color, uint8_t *t_data);
void PageDisplayNumBelow_y_axis(num_display_below_y_axis t_index, char* t_shownum);
void PageMoveNumBelow_y_axis(void);
void PageClearAreaBelow_y_axis(void);
void PageDisplaySpectrum(uint16_t t_index, uint8_t t_value, uint16_t t_color);
void PageMoveSpectrum(uint16_t t_color, uint8_t *t_data);
void PageClearSpectrumArea(void);
void PageDisplayBeforeSample(void);
void PageDisplayIsSample(void);
void PageDisplayString(uint16_t t_x, uint16_t t_y, uint16_t t_size, char *t_string);

#endif  /* _PAGE_H_ */