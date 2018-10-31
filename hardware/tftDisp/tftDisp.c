/*************************************************
// 文件说明:      此文件为针对用户层面的函数集
//                建立在在底层驱动文件和基本显示函数之上，用户可以增加相应的显示功能
//                因为这里的文件是针对用户层面的，所以软件有很强的移植性
// 创 建 人：     ZHAOWL
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
*************************************************/

/* --------------------------Includes ---------------------------------------------*/
#include "tftDisp.h"
#include <string.h>
/* ----------------------End of Includes ---------------------------------------------*/
/************************************************************************
// 函 数 名:      LCD_Digital_U16_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
// 函数功能描述:  显示十进制5位数字, 24*24点阵
// 参数描述:      x,y 坐标; u16 digital:0-65535; forcolor:前景; bkcolor:背景  
// 返 回 值:      无
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_U16_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[7];
    
    memset(dig,'\0',6);
    dig[0] = (char)(digital / 10000) + 0x30;           // 取出万位数
    dig[1] = (char)( (digital % 10000) / 1000) + 0x30; // 取出千位数
    dig[2] = (char)( (digital % 1000 ) / 100 ) + 0x30; // 取出百位数
    dig[3] = (char)( (digital % 100  ) / 10  ) + 0x30; // 取出十位数
    dig[4] = (char)(  digital % 10   )         + 0x30; // 取出个位数
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}


/************************************************************************
// 函 数 名:      void LCD_Digital_U16_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  显示十进制5位数字, 16*16点阵
// 参数描述:      x,y 坐标; u16 digital:0-65535; forcolor:前景; bkcolor:背景  
// 返 回 值:      无
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_U16_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[7];
    
    memset(dig,'\0',6);
    dig[0] = (char)(digital / 10000) + 0x30;           // 取出万位数
    dig[1] = (char)( (digital % 10000) / 1000) + 0x30; // 取出千位数
    dig[2] = (char)( (digital % 1000 ) / 100 ) + 0x30; // 取出百位数
    dig[3] = (char)( (digital % 100  ) / 10  ) + 0x30; // 取出十位数
    dig[4] = (char)(  digital % 10   )         + 0x30; // 取出个位数
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}


/************************************************************************
// 函 数 名:      LCD_Digital_U8_Asc24(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  显示十进制3位数字, 24*24点阵
// 参数描述:      x,y 坐标; u8 digital:0-255; forcolor:前景; bkcolor:背景  
// 返 回 值:      无
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_U8_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[5];
    
    memset(dig,'\0',4);
    dig[0] = (char)( digital / 100)       + 0x30; // 取出百位数
    dig[1] = (char)((digital % 100) / 10) + 0x30; // 取出十位数
    dig[2] = (char)( digital % 10 )       + 0x30; // 取出个位数
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      LCD_Digital_U8_Asc16(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  显示十进制3位数字, 16*16点阵
// 参数描述:      x,y 坐标; u8 digital:0-255; forcolor:前景; bkcolor:背景  
// 返 回 值:      无
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_U8_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[5];
    
    memset(dig,'\0',4);
    dig[0] = (char)( digital / 100)       + 0x30; // 取出百位数
    dig[1] = (char)((digital % 100) / 10) + 0x30; // 取出十位数
    dig[2] = (char)( digital % 10 )       + 0x30; // 取出个位数
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      char  Get_HextoASC_Disp(char hexdig)
// 函数功能描述:  将1个十六进制数转换为按十六进制的方式显示出来
// 参数描述:      char hexdig:十六进制数据   
// 返 回 值:      char:       
// 返回值描述:    十六进制文字
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
char  Get_HextoASC_Disp(char hexdig)
{
    char   tmp;
    
    tmp  = hexdig;
    tmp &= 0x0f;    
    if(tmp < 0x0a)       {  tmp += 0x30; } 
    else if(tmp == 0x0a) {  tmp  = 'a';  }
    else if(tmp == 0x0b) {  tmp  = 'b';  }
    else if(tmp == 0x0c) {  tmp  = 'c';  }
    else if(tmp == 0x0d) {  tmp  = 'd';  }
    else if(tmp == 0x0e) {  tmp  = 'e';  }
    else                 {  tmp  = 'f';  }
    
    return  tmp;
}

/************************************************************************
// 函 数 名:      void LCD_DigHex_U8_Asc24(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将1个字节的十六进制数按十六进制的方式显示出来 , 24*24点阵
// 参数描述:      x,y 坐标; u8 digital:0-ff; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_DigHex_U8_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[4];
    uint8_t    tmp;
    
    memset(dig,'\0',3);
    tmp = digital;
    tmp >>= 4; 
    dig[0] = Get_HextoASC_Disp(tmp);  // 取出高四位数, 转换为显示ASCII
    
    tmp = digital;
    tmp  &= 0x0f; 
    dig[1] = Get_HextoASC_Disp(tmp);  // 取出高四位数, 转换为显示ASCII 

    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      void LCD_DigHex_U8_Asc16(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将1个字节的十六进制数按十六进制的方式显示出来 , 16*16点阵
// 参数描述:      x,y 坐标; u8 digital:0-ff; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_DigHex_U8_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[4];
    uint8_t    tmp;
    
    memset(dig,'\0',3);
    tmp = digital;
    tmp >>= 4; 
    dig[0] = Get_HextoASC_Disp(tmp);  // 取出高四位数, 转换为显示ASCII
    
    tmp = digital;
    tmp  &= 0x0f; 
    dig[1] = Get_HextoASC_Disp(tmp);  // 取出高四位数, 转换为显示ASCII 

    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      void LCD_DigHex_U16_Asc24(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将2个字节的十六进制数按十六进制的方式显示出来 , 24*24点阵
// 参数描述:      x,y 坐标; u16 digital:0-ffff; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_DigHex_U16_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t     dig[6];
    uint16_t    tmp;
    uint8_t     tmp8;
    
    memset(dig,'\0',6);
    tmp = digital;
    tmp8 = (char)(tmp >>= 12); 
    dig[0] = Get_HextoASC_Disp(tmp8);  // 取出b15,b14,b13,b12位数, 转换为显示ASCII

    tmp = digital;
    tmp8 = (char)( (tmp >>= 8) & 0x000f);   
    dig[1] = Get_HextoASC_Disp(tmp8);  // 取出b11,b10,b9,b8位数, 转换为显示ASCII
    
    tmp = digital;
    tmp8 = (char)( (tmp >>= 4) & 0x000f);   
    dig[2] = Get_HextoASC_Disp(tmp8);  // 取出b7,b6,b5,b4 位数, 转换为显示ASCII

    tmp8 = (char)( digital  & 0x000f);  
    dig[3] = Get_HextoASC_Disp(tmp8);  // 取出b3,b2,b1,b0 位数, 转换为显示ASCII
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      void LCD_DigHex_U16_Asc16(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将2个字节的十六进制数按十六进制的方式显示出来 , 16*16点阵
// 参数描述:      x,y 坐标; u16 digital:0-ffff; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_DigHex_U16_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t     dig[6];
    uint16_t    tmp;
    uint8_t     tmp8;
    
    memset(dig,'\0',6);
    tmp = digital;
    tmp8 = (char)(tmp >>= 12); 
    dig[0] = Get_HextoASC_Disp(tmp8);  // 取出b15,b14,b13,b12位数, 转换为显示ASCII

    tmp = digital;
    tmp8 = (char)( (tmp >>= 8) & 0x000f);   
    dig[1] = Get_HextoASC_Disp(tmp8);  // 取出b11,b10,b9,b8位数, 转换为显示ASCII
    
    tmp = digital;
    tmp8 = (char)( (tmp >>= 4) & 0x000f);   
    dig[2] = Get_HextoASC_Disp(tmp8);  // 取出b7,b6,b5,b4 位数, 转换为显示ASCII

    tmp8 = (char)( digital  & 0x000f);  
    dig[3] = Get_HextoASC_Disp(tmp8);  // 取出b3,b2,b1,b0 位数, 转换为显示ASCII
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      void LCD_Digital_4_Asc24(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将2个字节的十六进制数按十进制的方式显示出来低四位 , 24*24点阵
// 参数描述:      x,y 坐标; u16 digital:0-65535; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_4_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[6];
    
    memset(dig,'\0',5);
    dig[0] = (char)( (digital % 10000) / 1000) + 0x30; // 取出千位数
    dig[1] = (char)( (digital % 1000 ) / 100 ) + 0x30; // 取出百位数
    dig[2] = (char)( (digital % 100  ) / 10  ) + 0x30; // 取出十位数
    dig[3] = (char)(  digital % 10   )         + 0x30; // 取出个位数
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      void LCD_Digital_4_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将2个字节的十六进制数按十进制的方式显示出来低四位 , 16*16点阵
// 参数描述:      x,y 坐标; u16 digital:0-65535; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_4_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[6];
    
    memset(dig,'\0',5);
    dig[0] = (char)( (digital % 10000) / 1000) + 0x30; // 取出千位数
    dig[1] = (char)( (digital % 1000 ) / 100 ) + 0x30; // 取出百位数
    dig[2] = (char)( (digital % 100  ) / 10  ) + 0x30; // 取出十位数
    dig[3] = (char)(  digital % 10   )         + 0x30; // 取出个位数
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      void LCD_Digital_2_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将2个字节的十六进制数按十进制的方式显示出来低2位 , 24*24点阵
// 参数描述:      x,y 坐标; u16 digital:0-65535; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_2_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[4];
    
    memset(dig,'\0',3);
    dig[0] = (char)( (digital % 100  ) / 10  ) + 0x30; // 取出十位数
    dig[1] = (char)(  digital % 10   )         + 0x30; // 取出个位数
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      void LCD_Digital_2_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// 函数功能描述:  将2个字节的十六进制数按十进制的方式显示出来低2位 , 16*16点阵
// 参数描述:      x,y 坐标; u16 digital:0-65535; forcolor:前景; bkcolor:背景    
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void LCD_Digital_2_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[4];
    
    memset(dig,'\0',3);
    dig[0] = (char)( (digital % 100  ) / 10  ) + 0x30; // 取出十位数
    dig[1] = (char)(  digital % 10   )         + 0x30; // 取出个位数
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// 函 数 名:      tftDisp_Touch_XY(struCTPxy *cptxy, struCTPxy *lastxy)
// 函数功能描述:  显示XY的坐标值
// 参数描述:      x,y 坐标;  forcolor:前景; bkcolor:背景; char *string:显示的字符串   
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
static  struTouch  cptxylast={0,0,NO_TOUCH,X_NO_MOVING,Y_NO_MOVING,};
void  tftDisp_Touch_XY(struTouch *cptxynow)
{
    if(cptxynow->ctpxy.ctp_x != cptxylast.ctpxy.ctp_x) // 当数值变化后, 显示, 不变则不显示维持原状态
    {
        if(cptxynow->ctpxy.ctp_x == 0x0fff)   // 没有触摸到
        {
            Gui_Draw_Asc24_Hzk24(X_TOUCHX, X_Y0, TOUCH_DIG_FORCOLOR, TOUCH_DIG_BKCOLOR, (uint8_t*)"-----");
        }
        else
        {
            LCD_Digital_U16_Asc24(X_TOUCHX, X_Y0, TOUCH_DIG_FORCOLOR, TOUCH_DIG_BKCOLOR, cptxynow->ctpxy.ctp_x);
        }
    }
    
    if(cptxynow->ctpxy.ctp_y != cptxylast.ctpxy.ctp_y)  // 当数值变化后, 显示, 不变则不显示维持原状态
    {
        if(cptxynow->ctpxy.ctp_y == 0x0fff)   // 没有触摸到
        {
            Gui_Draw_Asc24_Hzk24(Y_TOUCHX, X_Y0, TOUCH_DIG_FORCOLOR, TOUCH_DIG_BKCOLOR, (uint8_t*)"-----");
        }
        else
        {
            LCD_Digital_U16_Asc24(Y_TOUCHX, X_Y0, TOUCH_DIG_FORCOLOR, TOUCH_DIG_BKCOLOR, cptxynow->ctpxy.ctp_y);
        }
    }
    
    cptxylast.ctpxy.ctp_x = cptxynow->ctpxy.ctp_x;
    cptxylast.ctpxy.ctp_y = cptxynow->ctpxy.ctp_y;
}



/************************************************************************
// 函 数 名:      tftDisp_Test_Val(uint16_t val_x, uint16_t val_y)
// 函数功能描述:  显示 valueX valueY 的值
// 参数描述:      x,y 坐标;  forcolor:前景; bkcolor:背景; char *string:显示的字符串   
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
static  uint8_t x_last=0,y_last=0;
void  tftDisp_Test_Val(uint16_t val_x, uint16_t val_y)
{
    if(val_x != x_last) // 当数值变化后, 显示, 不变则不显示维持原状态
    { 
        LCD_Digital_U16_Asc24(VALUE_X_X1, VALUE_X_Y0, VAL_X_FORCOLOR, VAL_X_BKCOLOR, val_x); 
        x_last = val_x;
    }
    
    if(val_y != y_last) // 当数值变化后, 显示, 不变则不显示维持原状态
    { 
        LCD_Digital_U16_Asc24(VALUE_Y_X1, VALUE_X_Y0, VAL_X_FORCOLOR, VAL_X_BKCOLOR, val_y); 
        y_last = val_y;
    }
}    



void  tftDisp_AllDataTime(struRTC  nowrtc)
{
    LCD_DigHex_U8_Asc24(YEAR_X0, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.yearH);
    LCD_DigHex_U8_Asc24(YEAR_X1, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.yearL);
    Gui_Draw_Asc24_Hzk24((YEAR_X1+12*2), DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, (uint8_t*)"/");
    
    LCD_DigHex_U8_Asc24(MONTH_X, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.month);
    Gui_Draw_Asc24_Hzk24((MONTH_X+12*2), DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, (uint8_t*)"/");
    
    LCD_DigHex_U8_Asc24(DATA_X, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.data);
    Gui_Draw_Asc24_Hzk24((DATA_X+12*2), DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, (uint8_t*)" ");
    
    LCD_DigHex_U8_Asc24(HOUR_X, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.hour);
    Gui_Draw_Asc24_Hzk24((HOUR_X+12*2), DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, (uint8_t*)":");
    
    LCD_DigHex_U8_Asc24(MINUTE_X, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.minute);
    Gui_Draw_Asc24_Hzk24((MINUTE_X+12*2), DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, (uint8_t*)":"); 

    LCD_DigHex_U8_Asc24(SECOND_X, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.second);
}
/************************************************************************
// 函 数 名:      tftDisp_DataTime(struRTC  nowrtc)
// 函数功能描述:  显示 现在的日期和时间 
// 参数描述:      struRTC  nowrtc: 日期和时间 
// 返 回 值:      无       
// 返回值描述:    无
// 全局变量:      无
// 函数状态：     已经完成测试
// 函数层次：     面向用户的--软件功能层

// 创 建 人：     zhaoweiliang
// 日期：         2017-5-10
// 修 改 人：                     
// 修改日期：     201x-xx-xx
************************************************************************/
void  tftDisp_DataTime(struRTC  nowrtc)
{
    if(nowrtc.second == 0x00)
    {
        tftDisp_AllDataTime(nowrtc);   // 仅显示秒
    }
    else
    {
        LCD_DigHex_U8_Asc24(SECOND_X, DATA_TIME_Y, DATA_TIME_FORCOLOR, DATA_TIME__BKCOLOR, nowrtc.second);
    }
}

static  uint16_t ad10_last=0, ad11_last=0, ad12_last=0, ad13_last=0;
void  Disp_ADC1_Val(uint16_t ad10, uint16_t ad11, uint16_t ad12, uint16_t ad13)
{
    if(ad10 != ad10_last)
    {
        ad10_last = ad10;
//        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN10_VAL, Y_ADC1_IN10, ADC1_FORCOLOR, ADC1_BKCOLOR, ad10); // 显示"ADC1_IN10" 的十六进制值
        Gui_Draw_24_Dig_U16_Decimal(X_ADC1_IN10_VAL, Y_ADC1_IN10, ADC1_FORCOLOR, ADC1_BKCOLOR, ad10); // 显示"ADC1_IN10" 的十进制值
    }
    
    if(ad11 != ad11_last)
    {
        ad11_last = ad11;
//        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN11_VAL, Y_ADC1_IN11, ADC1_FORCOLOR, ADC1_BKCOLOR, ad11); // 显示"ADC1_IN11" 的十六进制值
        Gui_Draw_24_Dig_U16_Decimal(X_ADC1_IN11_VAL, Y_ADC1_IN11, ADC1_FORCOLOR, ADC1_BKCOLOR, ad11); // 显示"ADC1_IN11" 的十进制值        
    }
    
    if(ad12 != ad12_last)
    {
        ad12_last = ad12;
        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN12_VAL, Y_ADC1_IN12, ADC1_FORCOLOR, ADC1_BKCOLOR, ad12); // 显示"ADC1_IN12" 的十六进制值
    }
    
    if(ad13 != ad13_last)
    {
        ad13_last = ad13; 
        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN13_VAL, Y_ADC1_IN13, ADC1_FORCOLOR, ADC1_BKCOLOR, ad13); // 显示"ADC1_IN13" 的十六进制值
    }
    
}
