#include "app.h"
#include "delay.h"
#include "touch.h"
#include "page.h"
#include "GUI.h"
#include "lcd_drive.h"

uint8_t AppStartSampleArray[4] = {0xee, 0x00,0x00,0x0D};
Spec_RecData AppSpecRecData;
uint8_t AppReceiveDmaFinish = 0;

extern int8_t touchoffset;
extern function_select MainFuntionSelect;

extern uint16_t BACK_COLOR;
extern uint16_t POINT_COLOR;

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
extern UART_HandleTypeDef huart2;
extern display_background MainDispalyBackground;

/*
*@brief: function switch
*/
void AppSwitch(void)
{
  uint8_t Sample_loop_times = 0;
  /* switch to the baas background */
  if(MainFuntionSelect == k_function_basewindow)
  {
    if(MainDispalyBackground == t_display)
    {
      LcdDisplayBackground();
      LcdDisplayWindows();
      MainDispalyBackground = t_nodisplay;
    }
    while(1)
    {
      ReadCTP(&ctpxy);
     
      /* if click the spectrum icon then switch to spectrum */
      if((ctpxy.ctpxy.ctp_x >= ICON_SPECTRUM_XS) && 
         (ctpxy.ctpxy.ctp_x <= (ICON_SPECTRUM_XS+ICON_WIDE_SIZE)) && 
         (ctpxy.ctpxy.ctp_y >= ICON_SPECTRUM_YS) && 
         (ctpxy.ctpxy.ctp_y <= (ICON_SPECTRUM_YS+ICON_HIGH_SIZE)))
      {
         
           touchwait();
           MainFuntionSelect = k_function_spectrum;
      }
      if(MainFuntionSelect != k_function_basewindow)
        break;
     }
  }
  
  /* Switch to the spectrum display */
  if(MainFuntionSelect == k_function_spectrum)
  {
    PageDisplayBeforeSample();
    while(1)
    {
      ReadCTP(&ctpxy);
      if(ctpxy.ctpmainstatus == TOUCHED)
        break;
    }
    touchwait();
    if(AppStartSample() == HAL_OK)
    {
      /* Receive base of DMA */
      AppEnableRecDMA(&huart2, AppSpecRecData.datafield, 1030);
      /* Display is sampling */
      PageDisplayIsSample();
      while(AppReceiveDmaFinish != 1)
      {
          BACK_COLOR = BLACK;
          POINT_COLOR = PINGKISH_4_4;
          LCD_ShowChar(150+Sample_loop_times*100,250, '.', 64);
          delay_ms(50);
          Sample_loop_times++;
          if(Sample_loop_times == 6)
          {
            Lcd_Clear_Some_Area(150, 250, endx, 400,BACK_COLOR);
            Sample_loop_times = 0;
            delay_ms(50);
          }
      }
      if(AppReceiveDmaFinish == 1)
      {
        if(AppSpecRecData.datafield != NULL)
        {
          AppSpectrumDisplay(AppSpecRecData.Realdatafiled.Body);
          while(MainFuntionSelect == k_function_spectrum)
          {
            App_y_axis_move();
            PageMoveNumBelow_y_axis();
            PageMoveSpectrum(BLUE_3_4, AppSpecRecData.Realdatafiled.Body);
          }
          AppReceiveDmaFinish = 0;
        }
      }
    }
  }
}

/*
*@brief: spectrum initial display function
*/
void AppSpectrumDisplay(uint8_t *t_data)
{
  BACK_COLOR = BLACK;
  POINT_COLOR = WHITE_4_4;
  Lcd_Clear_All(BLACK);
  PageSpectrumInit(BLUE_3_4, t_data);
  App_y_axis_move();
  PageMoveNumBelow_y_axis();
  PageMoveSpectrum(BLUE_3_4, t_data);
}

/* 
*@brief: move the y-axis in touchlcd 
*/
void App_y_axis_move(void)
{
  while(1)
  {  
    ReadCTP(&ctpxy);
    if(ctpxy.ctpmainstatus == TOUCHED)
    {
      /* if left moving */
      if(ctpxy.xmove == LEFT_MOVING)
      {
        if(ctpxy.dx <= (int16_t)(-200))
        {
          touchoffset += 1;
          break;
        }
      }
      
      /* if right moving */
      else if(ctpxy.xmove == RIGHT_MOVING)
      {
        if(ctpxy.dy >= (int16_t)(200))
        {
          touchoffset -= 1;
          break;
        }
      }
      
      /* if click blank space */
      if(ctpxy.ctpxy.ctp_x < stx)
      {
        MainFuntionSelect = k_function_basewindow;
        MainDispalyBackground = t_display;
      }
    }
  }
  
  if((touchoffset < 0) || (touchoffset > 5))
  {
    touchoffset = 0;
  }
  touchwait();
}

/* 
*@brief:start sample
*/
HAL_StatusTypeDef AppStartSample(void)
{
  HAL_StatusTypeDef ret;
  ret = HAL_UART_Transmit(&huart2, AppStartSampleArray, 4, 50);
  if(ret == HAL_TIMEOUT)
  {
    /* request timeout */
    Lcd_Clear_All(BLACK);
    POINT_COLOR = RED_3_4;
    PageDisplayString(200, 300, 64, "Request timeout!");
  }
  else if(ret == HAL_ERROR)
  {
    /* something error */
    Lcd_Clear_All(BLACK);
    POINT_COLOR = RED_3_4;
    PageDisplayString(200, 300, 64, "Request error!");
  }
  else if(ret == HAL_BUSY)
  {
    /* the device is busy*/
    Lcd_Clear_All(BLACK);
    POINT_COLOR = RED_3_4;
    PageDisplayString(200, 300, 64, "The device is busy!");
  }
  return ret;
}

HAL_StatusTypeDef AppEnableRecDMA(UART_HandleTypeDef *t_huart, uint8_t *t_pData, uint16_t t_Size)
{
  HAL_StatusTypeDef ret ;
  if(t_pData != NULL)
  {
    ret = HAL_UART_Receive_DMA(t_huart, t_pData, t_Size);
    if(ret == HAL_ERROR)
    {
      Lcd_Clear_All(BLACK);
      POINT_COLOR = RED_3_4;
      PageDisplayString(200, 300, 64, "ERROR BUFFER!");
    }
    else if(ret == HAL_BUSY)
    {
      Lcd_Clear_All(BLACK);
      POINT_COLOR = RED_3_4;
      PageDisplayString(200, 300, 64, "THE DMA is USing,please wait!");
    }
  }
  return ret;
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