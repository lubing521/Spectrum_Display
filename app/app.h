#ifndef  __APP_H
#define  __APP_H
#include "stm32f4xx_hal.h"
#include "touch.h"

#include "displaywindows.h" 

typedef enum t_function_select
{
  k_function_basewindow = 0U,   /* change to base window */
  k_function_spectrum = 1,      /* change to spectrum function */        
}function_select;

typedef enum t_dispaly_background
{
  t_display = 0U,
  t_nodisplay = 1U,
}display_background;


void pageswitch(uint8_t *pagenum);//Ò³ÂëÇÐ»»
void touchwait();

void AppSwitch(void);
void AppSpectrumDisplay(void);
void App_y_axis_move(void);
void AppStartSample(void);

#define plusxpos 850-60+8
#define plusypos 220+16
#define minusxpos 850-260+8
#define minusypos 220+16
#define errarea   50
#endif