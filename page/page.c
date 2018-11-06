#include "page.h"
#include "lcd_drive.h"
#include "GUI.h"
#include "delay.h"
#include "array.h"
#include "app.h"

#include "string.h"

extern uint8_t U1_Rec_Buffer[];
extern int8_t touchoffset;

extern uint16_t BACK_COLOR;
extern uint16_t POINT_COLOR;

extern Spec_RecData AppSpecRecData;

void showgraph(void)
{
  uint16_t i;
  for(i=0;i<128;i++)
  {
    //Gui_Draw_Line(stx+i*2.4*2,sty,stx+i*2.4*2,sty-0.8*(U1_Rec_Buffer[2*i]+U1_Rec_Buffer[2*i+1]*256)/256,WHITE_4_4);
  }
}
extern uint8_t  setminute;
void mainpage()
{
  Lcd_Clear_All(BLACK);
  Gui_Draw_Line(0,120+40, 853, 120+40, WHITE_4_4);
  Gui_Draw_Line(0,121+40, 853, 121+40, WHITE_4_4);
  Gui_Draw_Line(0,122+40, 853, 122+40, WHITE_4_4);
  Gui_Draw_Line(0,123+40, 853, 123+40, WHITE_4_4);
  Gui_Draw_Line(0,124+40, 853, 124+40, WHITE_4_4);
  Gui_Draw_Line(0,125+40, 853, 125+40, WHITE_4_4);
  showhz(150+14, 40, 0,80);/*能谱分析仪（标题）*/
  showhz(150+14+108*1, 40, 1,80);
  showhz(150+14+108*2, 40, 2,80);
  showhz(150+14+108*3, 40, 3,80);
  showhz(150+14+108*4, 40, 4,80);
  showhz(204+14+108*0, 380, 0,64);/*开始采样*/
  showhz(204+14+108*1, 380, 1,64);
  showhz(204+14+108*2, 380, 8,64);
  showhz(204+14+108*3, 380, 9,64);
  showhz(80, 220, 8,64);/*采样时间*/
  showhz(80+64*1, 220, 9,64);
  showhz(80+64*2, 220, 10,64);
  showhz(80+64*3, 220, 11,64);
  LCD_ShowChar(80+64*4, 220, ':',64);
  LCD_ShowChar(80+64*4+32, 220, '(',64);
  showhz(80+64*4+32*2, 220, 12,64);
  showhz(80+64*5+32*2, 220, 13,64);
  LCD_ShowChar(80+64*6+32*2, 220, ')',64);
  LCD_ShowChar(850-60, 220, '+',64);
  LCD_ShowChar(850-260, 220, '-',64);
  LCD_ShowChar(850-160, 220, setminute+0x30,64);
}

//void graphpage()
//{
//  delay_ms(500);
//  Lcd_Clear_All(BLACK);
//  showhz(185, 30, 5,80);
//  showhz(185+80*1, 30, 6,80);
//  showhz(185+80*2, 30, 7,80);
//  showhz(185+80*3, 30, 8,80);
//  showhz(185+80*4, 30, 11,80);
//  showhz(185+80*5, 30, 12,80);
//  Gui_Draw_Line(0,120+30, 853, 120+30, WHITE_4_4);
//  Gui_Draw_Line(0,121+30, 853, 121+30, WHITE_4_4);
//  Gui_Draw_Line(0,122+30, 853, 122+30, WHITE_4_4);
//  Gui_Draw_Line(0,123+30, 853, 123+30, WHITE_4_4);
//  Gui_Draw_Line(0,124+30, 853, 124+30, WHITE_4_4);
//  Gui_Draw_Line(0,125+30, 853, 125+30, WHITE_4_4);
//  showaxis();
//  showgraph();
//  rightarrow(854-64-20,240-32);
//}

void reportpage()
{
  uint8_t small,medium,big,i;
  small=0;
  medium=0;
  big=0;
  for(i=smallamp-amperr;i<smallamp+amperr;i++)
  {
    small+=U1_Rec_Buffer[i];
  }
  for(i=mediumamp-amperr;i<mediumamp+amperr;i++)
  {
    medium+=U1_Rec_Buffer[i];
  }
  for(i=bigamp-amperr;i<bigamp+amperr;i++)
  {
    big+=U1_Rec_Buffer[i];
	
  }
  Lcd_Clear_All(BLACK);
  leftarrow(20,240-32);
  rightarrow(854-64-20,240-32);
  showhz(305, 30, 13,80);  //报
  showhz(305+160, 30, 14,80); //告
}

/* 
*@brief: display the x-axis and y-axis on lcd
*/
void PageShowAxis(void)
{
  uint16_t i;
  /* draw x-axis */
  for(i=0;i<5;i++) 
     Gui_Draw_Line(stx,sty+i, endx, sty+i, WHITE_4_4);
  
  /* draw y-axis */
  for(i=0;i<5;i++) 
    Gui_Draw_Line(stx-i,sty+4, stx-i, endy, WHITE_4_4);
  
  /* draw the arrow on y-axis */
  for(i=0;i<8;i++) 
    Gui_Draw_Line(stx-3,endy+i, stx-10-i, endy+8+i, WHITE_4_4);
  for(i=0;i<8;i++) 
    Gui_Draw_Line(stx-3,endy+i, stx+10+i, endy+8+i, WHITE_4_4);
  
  /* draw the arrow on x-axis */
  for(i=0;i<12;i++) 
    Gui_Draw_Line(endx-i,sty+2, endx-12-10+i, sty+12-i+2, WHITE_4_4);
  for(i=0;i<12;i++) 
    Gui_Draw_Line(endx-i,sty+2, endx-12-10+i, sty-12+i+2, WHITE_4_4);
  

   /* draw the scale on x-axis */
  for(i=1;i<=4;i++)
  {
    Gui_Draw_Line(stx+200*i-3,sty+4, stx+200*i-3, sty+10+4, WHITE_4_4);
    Gui_Draw_Line(stx+200*i-2,sty+4, stx+200*i-2, sty+10+4, WHITE_4_4);
    Gui_Draw_Line(stx+200*i-1,sty+4, stx+200*i-1, sty+10+4, WHITE_4_4);
    Gui_Draw_Line(stx+200*i,sty+4, stx+200*i, sty+10+4, WHITE_4_4);
  }
  
  /* draw the scale on y-axis */
  for(i=1;i<=5;i++)
  {
    Gui_Draw_Line(stx-4, sty-80*i-3, stx-5-4, sty-80*i-3, WHITE_4_4);
    Gui_Draw_Line(stx-4, sty-80*i-2, stx-5-4, sty-80*i-2, WHITE_4_4);
    Gui_Draw_Line(stx-4, sty-80*i-1, stx-5-4, sty-80*i-1, WHITE_4_4);
    Gui_Draw_Line(stx-4, sty-80*i, stx-5-4, sty-80*i, WHITE_4_4);
  }
  
  /* draw the num below y-axis */
  PageDisplayNumBelow_y_axis(kfirstindex, DisplayNumArray[0+touchoffset*4]);
  PageDisplayNumBelow_y_axis(ksecondindex, DisplayNumArray[1+touchoffset*4]);
  PageDisplayNumBelow_y_axis(kthirdindex, DisplayNumArray[2+touchoffset*4]);
  PageDisplayNumBelow_y_axis(kfourthindex, DisplayNumArray[3+touchoffset*4]);
 	
}

/*
*@brief: display the num below y-axis
*@param: t_index -- the value between 0-3
         t_shownum -- the string to be displayed
*/

void PageDisplayNumBelow_y_axis(num_display_below_y_axis t_index, char* t_shownum)
{
  char* shownum = NULL;
  uint8_t i = 0;
  num_display_below_y_axis index = kfirstindex;
  if(t_shownum != NULL)
  {
    shownum = t_shownum;
    index = t_index;
    while((*shownum) != '\0')
    {
      LCD_ShowChar(stx+4*50*index-16*(2-i),sty+10,*shownum ,32);
      shownum++;
      i++;
    }
  }
}

/*
*@brief: change the num below the y-axis if move y-axis with touchlcd
*/
void PageMoveNumBelow_y_axis(void)
{
  BACK_COLOR = BLACK;
  POINT_COLOR = WHITE_4_4;
  PageClearAreaBelow_y_axis();
  if(touchoffset <= 4)
  {
    PageDisplayNumBelow_y_axis(kfirstindex, DisplayNumArray[0+touchoffset*4]);
    PageDisplayNumBelow_y_axis(ksecondindex, DisplayNumArray[1+touchoffset*4]);
    PageDisplayNumBelow_y_axis(kthirdindex, DisplayNumArray[2+touchoffset*4]);
    PageDisplayNumBelow_y_axis(kfourthindex, DisplayNumArray[3+touchoffset*4]);
  }
  else 
  {
    PageDisplayNumBelow_y_axis(kfirstindex, DisplayNumArray[20]);
  }
}

/* 
*@brief: clear the area below y-axis
*/
void PageClearAreaBelow_y_axis(void)
{
  Lcd_Clear_Some_Area(23,430,endx,480-1,BLACK);  
}

/*
*@brief: display Spectrum 
*@param: t_index -- the index in x-axis
         t_value -- the spectrum value
         t_color -- the color
*/
void PageDisplaySpectrum(uint16_t t_index, uint8_t t_value, uint16_t t_color)
{
  uint16_t index;
  uint8_t value;
  uint16_t color;
  uint8_t i = 0;
  
  index = t_index;
  value = t_value;
  color = t_color;
  
  for(i=0; i<4; i++)
  {
    Gui_Draw_Line(23+4*index+i, sty, 23+4*index+i, sty-value, color);
  }
}

/*
*@brief: change the spectrum display if touch lcd was lef_move or right_move
*@param: t_color -- the color of the line
*/
void PageMoveSpectrum(uint16_t t_color, uint8_t *t_data)
{
  uint8_t tempvalue;
  uint8_t i = 0;
  uint16_t color;
  
  PageClearSpectrumArea();
  
  color = t_color;
  
  if(touchoffset <= 4)
  {
    for(i=0; i<200; i++)
    {
      tempvalue = t_data[i+touchoffset*200];
      PageDisplaySpectrum(i, tempvalue, color);
    }
  }
  else 
  {
     PageDisplaySpectrum(0, test_data[1020], color);
     PageDisplaySpectrum(0, test_data[1021], color);
     PageDisplaySpectrum(0, test_data[1022], color);
     PageDisplaySpectrum(0, test_data[1023], color);
  }
}

/*
*@brief: clear the spectrum display area
*/
void PageClearSpectrumArea(void)
{
  Lcd_Clear_Some_Area(23, 20, 823, sty, BLACK);
}

/*
*@brief: when sample finish display the initial screen 
*/
void PageSpectrumInit(uint16_t t_color, uint8_t *t_data)
{
  uint16_t i = 0;
  PageShowAxis();
  for(i=0; i<200; i++)
    PageDisplaySpectrum(i, t_data[i], t_color);
}

/*
*@brief:the page before sample
*/
void PageDisplayBeforeSample(void)
{
    BACK_COLOR = BLACK;
    POINT_COLOR = WHITE_4_4;
    Lcd_Clear_All(BLACK);
    PageDisplayString(100, 240, 32, "Please click anywhere to start sample!");
}

/*
*@brief:Display is Sample on lcd screen
*/
void PageDisplayIsSample(void)
{
  BACK_COLOR = BLACK;
  POINT_COLOR = WHITE_4_4;
  Lcd_Clear_All(BLACK);
  PageDisplayString(300, 200, 32, "Sampling");
}

/*
*@brief:display the string on lcd
*@param:   t_x -- x
           t_y -- y
           t_size -- size of the char
           t_string -- the string to be display
*/
void PageDisplayString(uint16_t t_x, uint16_t t_y, uint16_t t_size, char *t_string)
{
  uint16_t x,y;
  char *string = NULL;
  uint8_t i,len;
  uint16_t size = 0;
  
  if(t_string != NULL)
  {
    string = t_string;
    x = t_x;
    y = t_y;
    size = t_size;
    len = strlen(string);
    
    for(i=0; i<len; i++)
    {
      LCD_ShowChar(x+(i*size/2), y, *string, size);
      string++;
    }
    
  }
}

void rightarrow(uint16_t x,uint16_t y)
{
  LCD_ShowChar(x, y,'-',64);
  LCD_ShowChar(x+32, y,'>',64);
}

void leftarrow(uint16_t x,uint16_t y)
{
  LCD_ShowChar(x, y,'<',64);
  LCD_ShowChar(x+32, y,'-',64);
}

