#include "displaywindows.h"
#include "icon.h"


/*
*@brief: display the background
*/
void LcdDisplayBackground(void)
{
  //LcdShowPicture(0, 0, LCD_X_SIZE-1, LCD_Y_SIZE-1, (uint8_t *)(gImage_background));
  Lcd_Clear_All(YELLOW_2_4);
}

/*
*@brief: display the icon 
*/
void LcdDisplayWindows(void)
{
  
  LcdShowPicture(ICON_SPECTRUM_XS, ICON_SPECTRUM_YS, ICON_WIDE_SIZE, ICON_HIGH_SIZE, (uint8_t *)(gImage_Spectrum));
  LcdShowIconName(ICON_SPECTRUM_XS, (ICON_SPECTRUM_YS+ICON_HIGH_SIZE+ICON_Y_SPACE), "spectrum");
}