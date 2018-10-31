#ifndef __TFTDISP_H__
#define __TFTDISP_H__ 

#include  "stm32f4xx_hal.h"
#include  "touch.h"
#include  "Lcd_Drive.h"
#include  "GUI.h"
#include  "common.h"
#include  "rtc.h"

// 显示触摸坐标的参数
#define    LINE_Y0              (Y_MAX_PIXEL - 41) // 横线分割触摸坐标的显示
#define    X_X0                  660
#define    X_Y0                 (Y_MAX_PIXEL - 32)
#define    X_TOUCHX             (X_X0 + 24)

#define    Y_X0                 (X_X0 + 100 )
#define    Y_Y0                  X_Y0
#define    Y_TOUCHX             (Y_X0 + 24)

#define    TOUCH_DIG_FORCOLOR    YELLOW_4_4
#define    TOUCH_DIG_BKCOLOR     BLUE_4_4

// 显示测试数值的参数
#define    VALUE_X_Y0           (Y_MAX_PIXEL - 32)
#define    VALUE_X_X0            400
#define    VALUE_X_X1           (VALUE_X_X0 + 12*5)
#define    VAL_X_FORCOLOR        WHITE_3_4
#define    VAL_X_BKCOLOR         GREEN_2_4

#define    VALUE_Y_X0           (VALUE_X_X1 + 12*6)
#define    VALUE_Y_X1           (VALUE_Y_X0 + 12*5)

// 显示时间的参数  
#define    DATA_TIME_Y          (Y_MAX_PIXEL - 32)
#define    YEAR_X0               10
#define    YEAR_X1              (YEAR_X0 + 12*2)
#define    MONTH_X              (YEAR_X1 + 12*3)
#define    DATA_X               (MONTH_X + 12*3)
#define    HOUR_X               (DATA_X + 12*3)
#define    MINUTE_X             (HOUR_X + 12*3)
#define    SECOND_X             (MINUTE_X + 12*3)

#define    DATA_TIME_FORCOLOR    CYAN_4_4
#define    DATA_TIME__BKCOLOR    RED_2_4

// 显示ADC1 四个AD值的参数  
#define    X_ADC1_IN10_STR       650
#define    X_ADC1_IN11_STR       X_ADC1_IN10_STR
#define    X_ADC1_IN12_STR       X_ADC1_IN10_STR
#define    X_ADC1_IN13_STR       X_ADC1_IN10_STR

#define    Y_ADC1_IN10           40
#define    Y_ADC1_IN11          (Y_ADC1_IN10 + 32)
#define    Y_ADC1_IN12          (Y_ADC1_IN11 + 32)
#define    Y_ADC1_IN13          (Y_ADC1_IN12 + 32)

#define    X_ADC1_IN10_VAL      (X_ADC1_IN10_STR + 12*11)
#define    X_ADC1_IN11_VAL       X_ADC1_IN10_VAL
#define    X_ADC1_IN12_VAL       X_ADC1_IN10_VAL
#define    X_ADC1_IN13_VAL       X_ADC1_IN10_VAL
#define    ADC1_FORCOLOR         WHITE_4_4
#define    ADC1_BKCOLOR          GREEN_2_4


////////////////////////////////////////////////////////
void  LCD_Digital_U16_Asc16(uint16_t , uint16_t , uint16_t , uint16_t , uint16_t );
void  LCD_Digital_U8_Asc16( uint16_t , uint16_t , uint16_t , uint16_t , uint8_t  );
char  Get_HextoASC_Disp(char );
void  LCD_DigHex_U8_Asc16( uint16_t , uint16_t , uint16_t , uint16_t , uint8_t  );
void  LCD_DigHex_U16_Asc16(uint16_t , uint16_t , uint16_t , uint16_t , uint16_t );

void  LCD_Digital_4_Asc16(uint16_t, uint16_t, uint16_t , uint16_t , uint16_t );
void  LCD_Digital_2_Asc16(uint16_t, uint16_t, uint16_t , uint16_t , uint16_t );

void  LCD_Digital_U16_Asc24(uint16_t,uint16_t,uint16_t , uint16_t , uint16_t );

void  tftDisp_Touch_XY(struTouch *);
void  tftDisp_Test_Val(uint16_t, uint16_t);     // 显示 valuetest 的值
void  tftDisp_DataTime(struRTC );
void  tftDisp_AllDataTime(struRTC );
void  Disp_ADC1_Val(uint16_t , uint16_t , uint16_t , uint16_t );
#endif
