#include "page.h"
#include  "lcd_drive.h"
#include "gui.h"
#include "delay.h"
extern uint8_t U1_Rec_Buffer[];
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

void graphpage()
{
  delay_ms(500);
  Lcd_Clear_All(BLACK);
  showhz(185, 30, 5,80);
  showhz(185+80*1, 30, 6,80);
  showhz(185+80*2, 30, 7,80);
  showhz(185+80*3, 30, 8,80);
  showhz(185+80*4, 30, 11,80);
  showhz(185+80*5, 30, 12,80);
  Gui_Draw_Line(0,120+30, 853, 120+30, WHITE_4_4);
  Gui_Draw_Line(0,121+30, 853, 121+30, WHITE_4_4);
  Gui_Draw_Line(0,122+30, 853, 122+30, WHITE_4_4);
  Gui_Draw_Line(0,123+30, 853, 123+30, WHITE_4_4);
  Gui_Draw_Line(0,124+30, 853, 124+30, WHITE_4_4);
  Gui_Draw_Line(0,125+30, 853, 125+30, WHITE_4_4);
  showaxis();
  showgraph();
  rightarrow(854-64-20,240-32);
}

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
void showaxis()
{
  uint16_t i;
  for(i=0;i<6;i++) 
     Gui_Draw_Line(stx-50,sty+i, endx+1, sty+i, WHITE_4_4);
  for(i=0;i<6;i++) 
    Gui_Draw_Line(stx+i,sty+50, stx+i, endy+1, WHITE_4_4);
  for(i=0;i<12;i++) 
    Gui_Draw_Line(stx+3,endy-10+i, stx+3-5-i, endy-10+20+i, WHITE_4_4);
  for(i=0;i<12;i++) 
    Gui_Draw_Line(stx+3,endy-10+i, stx+3+5+i, endy+20+i-10, WHITE_4_4);
  for(i=0;i<12;i++) 
    Gui_Draw_Line(endx+10-i,sty+3, endx-20-i+10, sty+3-5-i, WHITE_4_4);
  for(i=0;i<12;i++) 
    Gui_Draw_Line(endx+10-i,sty+3, endx-20-i+10, sty+3+5+i, WHITE_4_4);
  LCD_ShowChar(stx-8-16, sty+14,'O',32);
  for(i=1;i<=5;i++)
  {
    Gui_Draw_Line(stx+120*i,sty, stx+120*i, sty-10, WHITE_4_4);
    Gui_Draw_Line(stx+120*i+1,sty, stx+120*i+1, sty-10, WHITE_4_4);
    Gui_Draw_Line(stx+120*i+2,sty, stx+120*i+2, sty-10, WHITE_4_4);
  }
  for(i=1;i<=5;i++)
  {
    Gui_Draw_Line(stx+6,sty-40*i, stx+5+6, sty-40*i, WHITE_4_4);
    Gui_Draw_Line(stx+6,sty-40*i+1, stx+5+6, sty-40*i+1, WHITE_4_4);
    Gui_Draw_Line(stx+6,sty-40*i+2, stx+5+6, sty-40*i+2, WHITE_4_4);
  }
  for(i=1;i<=26;i++)
  {
    Gui_Draw_Line(stx+24*i,sty, stx+24*i, sty-6, WHITE_4_4);
    Gui_Draw_Line(stx+24*i+1,sty, stx+24*i+1, sty-6, WHITE_4_4);
    Gui_Draw_Line(stx+24*i+2,sty, stx+24*i+2, sty-6, WHITE_4_4);
  }
  for(i=1;i<=5;i++)
  {
    Gui_Draw_Line(stx+6,sty-40*i+20, stx+3+6, sty-40*i+20, WHITE_4_4);
    Gui_Draw_Line(stx+6,sty-40*i+20+1, stx+3+6, sty-40*i+20+1, WHITE_4_4);
    Gui_Draw_Line(stx+6,sty-40*i+20+2, stx+3+6, sty-40*i+20+2, WHITE_4_4);
  }
  for(i=25;i<=125;i=i+25)
  {
    if(i==50)
    {
      LCD_ShowChar(stx+120*i/25-16, sty+10,5+0x30,32);
      LCD_ShowChar(stx+120*i/25, sty+10,0x30,32);
    }
    else if(i==25)
    {
      LCD_ShowChar(stx+120*i/25-16, sty+10,2+0x30,32);
      LCD_ShowChar(stx+120*i/25, sty+10,5+0x30,32);
    }
    else if(i==75)
    {
      LCD_ShowChar(stx+120*i/25-16, sty+10,7+0x30,32);
      LCD_ShowChar(stx+120*i/25, sty+10,5+0x30,32);
    }
    else
    {
      LCD_ShowChar(stx+120*i/25-16-8, sty+10,i/100+0x30,32);
      LCD_ShowChar(stx+120*i/25-8, sty+10,i/10%10+0x30,32);
      LCD_ShowChar(stx+120*i/25+8, sty+10,i%10+0x30,32);
    }
  }
  LCD_ShowChar(stx-5-16*2.5, endy-3,'C',32);
  LCD_ShowChar(endx-5, sty+12,'A',32);	
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