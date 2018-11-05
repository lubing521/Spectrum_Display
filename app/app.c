#include "app.h"
#include "delay.h"
#include "touch.h"
#include "page.h"
#include "gui.h"
#include "lcd_drive.h"

extern int8_t touchoffset;
extern function_select MainFuntionSelect;

void pageswitch(uint8_t *pagenum){
	if((*pagenum)==0){
		mainpage();
	}
	else if(*pagenum==1){
//		graphpage();
	}
	else if(*pagenum==2){
		reportpage();
	}
}

extern uint8_t  setminute;
extern uint8_t U1_Rec_Buffer[];
extern struTouch  ctpxy;  
extern UART_HandleTypeDef huart1;
//void appswitch(uint8_t *pagenum)
//{
//  uint32_t i;
//  uint32_t tmp;
//  uint8_t tx;
//  if((*pagenum)==0)
//  {
//    while((*pagenum)==0)
//    {
//      ReadCTP(&ctpxy);
//      if((ctpxy.ctpmainstatus == TOUCHED))
//      {
//      /* Plus the setminute */
//        if(ctpxy.ctpxy.ctp_x<plusxpos+errarea&&ctpxy.ctpxy.ctp_x>plusxpos-errarea)
//        {
//          if(ctpxy.ctpxy.ctp_y<plusypos+errarea&&ctpxy.ctpxy.ctp_y>plusypos-errarea)
//          {
//            if(setminute==5)
//              setminute=5;
//            else
//              setminute=setminute+1;
//            LCD_ShowChar(850-160, 220, setminute+0x30,64);
//          }
//        }
//        /* minus the setminute */
//        else if(ctpxy.ctpxy.ctp_x<minusxpos+errarea&&ctpxy.ctpxy.ctp_x>minusxpos-errarea)
//        {
//          if(ctpxy.ctpxy.ctp_y<minusypos+errarea&&ctpxy.ctpxy.ctp_y>minusypos-errarea)
//          {
//            if(setminute==1)
//              setminute=1;
//            else
//              setminute=setminute-1;
//          }
//          LCD_ShowChar(850-160, 220, setminute+0x30,64);
//         }
//          /* if touch begin sample */
//        else if(ctpxy.ctpxy.ctp_y>380&&ctpxy.ctpxy.ctp_y<480)
//        {
//        /* Display status and stop button */
//          Lcd_Clear_Some_Area(0,220,853,479,BLACK);
//          HAL_UART_Receive_DMA(&huart1, U1_Rec_Buffer, 256);
//          showhz(204+14+108*1, 380, 14,64);
//          showhz(204+14+108*2, 380, 15,64);
//          showhz(204+14+64*0, 220, 2,64);
//          showhz(204+14+64*1, 220, 3,64);
//          showhz(204+14+64*2, 220, 4,64);
//          showhz(204+14+64*3, 220, 5,64);
//          LCD_ShowChar(204+14+64*4, 220, ':',64);
//          LCD_ShowChar(204+14+108*3+60, 220, '%',64);
//          /* begin sample */
//          tx=0x80;
//          HAL_UART_Transmit_IT(&huart1,&tx,1);
//          touchwait();
//          for(i=0;i<60*setminute*100;i++)
//          {
//            if(i%5==0)
//            {
//              tmp=i;
//              LCD_ShowChar(204+14+108*3-100+60, 220, tmp/(60*setminute)/100+0x30,64);
//              LCD_ShowChar(204+14+108*3-100+32+60, 220, (tmp/(60*setminute)/10)%10+0x30,64);
//              LCD_ShowChar(204+14+108*3-100+32*2+60, 220, tmp/(60*setminute)%10+0x30,64);
//            }
//            delay_ms(1);
//            ReadCTP(&ctpxy);		
//            if(ctpxy.ctpxy.ctp_y>380&&ctpxy.ctpxy.ctp_y<479)
//            {
//              /* if touch stop */
//              touchwait();
//              tx=0x40;
//              HAL_UART_Transmit_IT(&huart1,&tx,1);
//              HAL_UART_Receive_DMA(&huart1, U1_Rec_Buffer, 256);
//              delay_ms(1000);
//              tx=0x20;
//              HAL_UART_Transmit_IT(&huart1,&tx,1);
//              *pagenum=1;
//              return;
//            }					
//            delay_ms(9);
//          }
//          /* sample finish */
//          tx=0x40;
//          HAL_UART_Transmit_IT(&huart1,&tx,1);
//          delay_ms(1000);			
//          tx=0x20;
//          HAL_UART_Transmit_IT(&huart1,&tx,1);
//          *pagenum=1;
//        }
//      }
//	touchwait();
//    }
//  }
//  else if((*pagenum)==1)
//  {
//  /* Display report page */
//    while((*pagenum)==1)
//    {
//      ReadCTP(&ctpxy);
//      if(ctpxy.ctpxy.ctp_x>754&&ctpxy.ctpxy.ctp_x<854&&ctpxy.ctpxy.ctp_y>210&&ctpxy.ctpxy.ctp_y<270)
//      {
//        *pagenum=2;
//	touchwait();
//      }
//    }
//  }
//  else if((*pagenum)==2)
//  {
//    while((*pagenum)==2)
//    {
//      ReadCTP(&ctpxy);
//      if(ctpxy.ctpxy.ctp_x>754&&ctpxy.ctpxy.ctp_x<854&&ctpxy.ctpxy.ctp_y>210&&ctpxy.ctpxy.ctp_y<270)
//      {
//        *pagenum=0;
//	touchwait();
//      }
//      else if(ctpxy.ctpxy.ctp_x>20&&ctpxy.ctpxy.ctp_x<100&&ctpxy.ctpxy.ctp_y>210&&ctpxy.ctpxy.ctp_y<270)
//      {
//	*pagenum=1;
//	touchwait();
//      }
//    }
//  }
//}

/*
*@brief: function switch
*/
void AppSwitch(void)
{
  if(MainFuntionSelect == k_function_basewindow)
  {
    while(1)
    {
      ReadCTP(&ctpxy);
     
      /* if click the spectrum icon */
      if((ctpxy.ctpxy.ctp_x >= ICON_SPECTRUM_XS) && 
         (ctpxy.ctpxy.ctp_x <= (ICON_SPECTRUM_XS+ICON_WIDE_SIZE)) && 
         (ctpxy.ctpxy.ctp_y >= ICON_SPECTRUM_YS) && 
         (ctpxy.ctpxy.ctp_y <= (ICON_SPECTRUM_YS+ICON_HIGH_SIZE)))
      {
         
           touchwait();
           MainFuntionSelect = k_function_spectrum;
           //AppSpectrumDisplay();
      }
      if(MainFuntionSelect != k_function_basewindow)
        break;
     }
  }
  if(MainFuntionSelect == k_function_spectrum)
  {
    AppSpectrumDisplay();
    while(MainFuntionSelect == k_function_spectrum)
    {
      App_y_axis_move();
      PageMoveNumBelow_y_axis();
      PageMoveSpectrum(BLUE_3_4);
    }
  }
}

/*
*@brief: spectrum display function
*/
void AppSpectrumDisplay(void)
{
  Lcd_Clear_All(BLACK);
  PageSpectrumInit(BLUE_3_4);
  App_y_axis_move();
  PageMoveNumBelow_y_axis();
  PageMoveSpectrum(BLUE_3_4);
}

/* 
*@brief: move the y-axis with touchlcd 
*/
void App_y_axis_move(void)
{
  while(1)
  {  
    ReadCTP(&ctpxy);
    if(ctpxy.ctpmainstatus == TOUCHED)
    {
      if(ctpxy.xmove == LEFT_MOVING)
      {
        if(ctpxy.dx <= (int16_t)(-200))
        {
          touchoffset += 1;
          break;
        }
      }
      else if(ctpxy.xmove == RIGHT_MOVING)
      {
        if(ctpxy.dy >= (int16_t)(200))
        {
          touchoffset -= 1;
          break;
        }
      }
    }
  }
  
  if((touchoffset < 0) || (touchoffset > 5))
  {
    touchoffset = 0;
  }
  touchwait();
}

void touchwait()
{
  ReadCTP(&ctpxy);
  while(ctpxy.ctpmainstatus!=NO_TOUCH)
  {
    ReadCTP(&ctpxy);
    delay_ms(10);	
  }
}