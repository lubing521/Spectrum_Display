#include "showpicture.h"
#include "GUI.h"
#include "string.h"

/*
*@brief:show the picture on lcd
*@param: t_x--picture start x
*        t_y--picture start y
*        t_wide--picture width 
*        t_height--picture height
*        t_pic-- picture array              
*/
void LcdShowPicture(uint16_t t_x, uint16_t t_y, uint16_t t_wide, uint16_t t_high, uint8_t *t_pic)
{
  uint16_t temp = 0;
  long tmp = 0;
  long num = 0;
  num = (t_wide*t_high)*2;
  
  Lcd_Set_Region(t_x, t_y, t_x+t_wide-1, t_y+t_high-1);
  
  do
  {
    temp = t_pic[tmp+1];
    temp = temp << 8;
    temp |= t_pic[tmp];
    *(__IO uint16_t *)Bank1_LCD_D = temp;
    tmp+=2;
  }while(tmp < num);  
}

/*
*@brief: display the icon name below the icon
*@param:  t_x: icon name's start x
          t_y: icon name's start y
          t_string: icon name's string
*/
void LcdShowIconName(uint16_t t_x, uint16_t t_y, uint8_t *t_string)
{
  uint8_t len = 0;
  uint8_t i = 0;
  uint16_t x;
  uint16_t y;
  uint8_t *string;
  
  x = t_x;
  y = t_y;
  if(t_string != NULL )
  {
    string = t_string;
    len = strlen((char *)string);
  
    for(i=0; i<len; i++)
    {
      LCD_ShowChar((x+i*32), y, *string, 32);
      string++;
    }
  }
}
