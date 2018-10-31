/*************************************************
// �ļ�˵��:      ���ļ�Ϊ����û�����ĺ�����
//                �������ڵײ������ļ��ͻ�����ʾ����֮�ϣ��û�����������Ӧ����ʾ����
//                ��Ϊ������ļ�������û�����ģ���������к�ǿ����ֲ��
// �� �� �ˣ�     ZHAOWL
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
*************************************************/

/* --------------------------Includes ---------------------------------------------*/
#include "tftDisp.h"
#include <string.h>
/* ----------------------End of Includes ---------------------------------------------*/
/************************************************************************
// �� �� ��:      LCD_Digital_U16_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
// ������������:  ��ʾʮ����5λ����, 24*24����
// ��������:      x,y ����; u16 digital:0-65535; forcolor:ǰ��; bkcolor:����  
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_U16_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[7];
    
    memset(dig,'\0',6);
    dig[0] = (char)(digital / 10000) + 0x30;           // ȡ����λ��
    dig[1] = (char)( (digital % 10000) / 1000) + 0x30; // ȡ��ǧλ��
    dig[2] = (char)( (digital % 1000 ) / 100 ) + 0x30; // ȡ����λ��
    dig[3] = (char)( (digital % 100  ) / 10  ) + 0x30; // ȡ��ʮλ��
    dig[4] = (char)(  digital % 10   )         + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}


/************************************************************************
// �� �� ��:      void LCD_Digital_U16_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��ʾʮ����5λ����, 16*16����
// ��������:      x,y ����; u16 digital:0-65535; forcolor:ǰ��; bkcolor:����  
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_U16_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[7];
    
    memset(dig,'\0',6);
    dig[0] = (char)(digital / 10000) + 0x30;           // ȡ����λ��
    dig[1] = (char)( (digital % 10000) / 1000) + 0x30; // ȡ��ǧλ��
    dig[2] = (char)( (digital % 1000 ) / 100 ) + 0x30; // ȡ����λ��
    dig[3] = (char)( (digital % 100  ) / 10  ) + 0x30; // ȡ��ʮλ��
    dig[4] = (char)(  digital % 10   )         + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}


/************************************************************************
// �� �� ��:      LCD_Digital_U8_Asc24(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��ʾʮ����3λ����, 24*24����
// ��������:      x,y ����; u8 digital:0-255; forcolor:ǰ��; bkcolor:����  
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_U8_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[5];
    
    memset(dig,'\0',4);
    dig[0] = (char)( digital / 100)       + 0x30; // ȡ����λ��
    dig[1] = (char)((digital % 100) / 10) + 0x30; // ȡ��ʮλ��
    dig[2] = (char)( digital % 10 )       + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      LCD_Digital_U8_Asc16(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��ʾʮ����3λ����, 16*16����
// ��������:      x,y ����; u8 digital:0-255; forcolor:ǰ��; bkcolor:����  
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_U8_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[5];
    
    memset(dig,'\0',4);
    dig[0] = (char)( digital / 100)       + 0x30; // ȡ����λ��
    dig[1] = (char)((digital % 100) / 10) + 0x30; // ȡ��ʮλ��
    dig[2] = (char)( digital % 10 )       + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      char  Get_HextoASC_Disp(char hexdig)
// ������������:  ��1��ʮ��������ת��Ϊ��ʮ�����Ƶķ�ʽ��ʾ����
// ��������:      char hexdig:ʮ����������   
// �� �� ֵ:      char:       
// ����ֵ����:    ʮ����������
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
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
// �� �� ��:      void LCD_DigHex_U8_Asc24(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��1���ֽڵ�ʮ����������ʮ�����Ƶķ�ʽ��ʾ���� , 24*24����
// ��������:      x,y ����; u8 digital:0-ff; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_DigHex_U8_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[4];
    uint8_t    tmp;
    
    memset(dig,'\0',3);
    tmp = digital;
    tmp >>= 4; 
    dig[0] = Get_HextoASC_Disp(tmp);  // ȡ������λ��, ת��Ϊ��ʾASCII
    
    tmp = digital;
    tmp  &= 0x0f; 
    dig[1] = Get_HextoASC_Disp(tmp);  // ȡ������λ��, ת��Ϊ��ʾASCII 

    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      void LCD_DigHex_U8_Asc16(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��1���ֽڵ�ʮ����������ʮ�����Ƶķ�ʽ��ʾ���� , 16*16����
// ��������:      x,y ����; u8 digital:0-ff; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_DigHex_U8_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint8_t digital)
{
    uint8_t  dig[4];
    uint8_t    tmp;
    
    memset(dig,'\0',3);
    tmp = digital;
    tmp >>= 4; 
    dig[0] = Get_HextoASC_Disp(tmp);  // ȡ������λ��, ת��Ϊ��ʾASCII
    
    tmp = digital;
    tmp  &= 0x0f; 
    dig[1] = Get_HextoASC_Disp(tmp);  // ȡ������λ��, ת��Ϊ��ʾASCII 

    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      void LCD_DigHex_U16_Asc24(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��2���ֽڵ�ʮ����������ʮ�����Ƶķ�ʽ��ʾ���� , 24*24����
// ��������:      x,y ����; u16 digital:0-ffff; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_DigHex_U16_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t     dig[6];
    uint16_t    tmp;
    uint8_t     tmp8;
    
    memset(dig,'\0',6);
    tmp = digital;
    tmp8 = (char)(tmp >>= 12); 
    dig[0] = Get_HextoASC_Disp(tmp8);  // ȡ��b15,b14,b13,b12λ��, ת��Ϊ��ʾASCII

    tmp = digital;
    tmp8 = (char)( (tmp >>= 8) & 0x000f);   
    dig[1] = Get_HextoASC_Disp(tmp8);  // ȡ��b11,b10,b9,b8λ��, ת��Ϊ��ʾASCII
    
    tmp = digital;
    tmp8 = (char)( (tmp >>= 4) & 0x000f);   
    dig[2] = Get_HextoASC_Disp(tmp8);  // ȡ��b7,b6,b5,b4 λ��, ת��Ϊ��ʾASCII

    tmp8 = (char)( digital  & 0x000f);  
    dig[3] = Get_HextoASC_Disp(tmp8);  // ȡ��b3,b2,b1,b0 λ��, ת��Ϊ��ʾASCII
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      void LCD_DigHex_U16_Asc16(u16 x, u16 y, u8 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��2���ֽڵ�ʮ����������ʮ�����Ƶķ�ʽ��ʾ���� , 16*16����
// ��������:      x,y ����; u16 digital:0-ffff; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_DigHex_U16_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t     dig[6];
    uint16_t    tmp;
    uint8_t     tmp8;
    
    memset(dig,'\0',6);
    tmp = digital;
    tmp8 = (char)(tmp >>= 12); 
    dig[0] = Get_HextoASC_Disp(tmp8);  // ȡ��b15,b14,b13,b12λ��, ת��Ϊ��ʾASCII

    tmp = digital;
    tmp8 = (char)( (tmp >>= 8) & 0x000f);   
    dig[1] = Get_HextoASC_Disp(tmp8);  // ȡ��b11,b10,b9,b8λ��, ת��Ϊ��ʾASCII
    
    tmp = digital;
    tmp8 = (char)( (tmp >>= 4) & 0x000f);   
    dig[2] = Get_HextoASC_Disp(tmp8);  // ȡ��b7,b6,b5,b4 λ��, ת��Ϊ��ʾASCII

    tmp8 = (char)( digital  & 0x000f);  
    dig[3] = Get_HextoASC_Disp(tmp8);  // ȡ��b3,b2,b1,b0 λ��, ת��Ϊ��ʾASCII
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      void LCD_Digital_4_Asc24(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��2���ֽڵ�ʮ����������ʮ���Ƶķ�ʽ��ʾ��������λ , 24*24����
// ��������:      x,y ����; u16 digital:0-65535; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_4_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[6];
    
    memset(dig,'\0',5);
    dig[0] = (char)( (digital % 10000) / 1000) + 0x30; // ȡ��ǧλ��
    dig[1] = (char)( (digital % 1000 ) / 100 ) + 0x30; // ȡ����λ��
    dig[2] = (char)( (digital % 100  ) / 10  ) + 0x30; // ȡ��ʮλ��
    dig[3] = (char)(  digital % 10   )         + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      void LCD_Digital_4_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��2���ֽڵ�ʮ����������ʮ���Ƶķ�ʽ��ʾ��������λ , 16*16����
// ��������:      x,y ����; u16 digital:0-65535; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_4_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[6];
    
    memset(dig,'\0',5);
    dig[0] = (char)( (digital % 10000) / 1000) + 0x30; // ȡ��ǧλ��
    dig[1] = (char)( (digital % 1000 ) / 100 ) + 0x30; // ȡ����λ��
    dig[2] = (char)( (digital % 100  ) / 10  ) + 0x30; // ȡ��ʮλ��
    dig[3] = (char)(  digital % 10   )         + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      void LCD_Digital_2_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��2���ֽڵ�ʮ����������ʮ���Ƶķ�ʽ��ʾ������2λ , 24*24����
// ��������:      x,y ����; u16 digital:0-65535; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_2_Asc24(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[4];
    
    memset(dig,'\0',3);
    dig[0] = (char)( (digital % 100  ) / 10  ) + 0x30; // ȡ��ʮλ��
    dig[1] = (char)(  digital % 10   )         + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc24_Hzk24(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      void LCD_Digital_2_Asc16(u16 x, u16 y, u16 digital, u16 forcolor, u16 bkcolor)
// ������������:  ��2���ֽڵ�ʮ����������ʮ���Ƶķ�ʽ��ʾ������2λ , 16*16����
// ��������:      x,y ����; u16 digital:0-65535; forcolor:ǰ��; bkcolor:����    
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void LCD_Digital_2_Asc16(uint16_t x, uint16_t y, uint16_t forcolor, uint16_t bkcolor, uint16_t digital)
{
    uint8_t  dig[4];
    
    memset(dig,'\0',3);
    dig[0] = (char)( (digital % 100  ) / 10  ) + 0x30; // ȡ��ʮλ��
    dig[1] = (char)(  digital % 10   )         + 0x30; // ȡ����λ��
    
    Gui_Draw_Asc16_Hzk16(x, y, forcolor, bkcolor, dig);
}

/************************************************************************
// �� �� ��:      tftDisp_Touch_XY(struCTPxy *cptxy, struCTPxy *lastxy)
// ������������:  ��ʾXY������ֵ
// ��������:      x,y ����;  forcolor:ǰ��; bkcolor:����; char *string:��ʾ���ַ���   
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
static  struTouch  cptxylast={0,0,NO_TOUCH,X_NO_MOVING,Y_NO_MOVING,};
void  tftDisp_Touch_XY(struTouch *cptxynow)
{
    if(cptxynow->ctpxy.ctp_x != cptxylast.ctpxy.ctp_x) // ����ֵ�仯��, ��ʾ, ��������ʾά��ԭ״̬
    {
        if(cptxynow->ctpxy.ctp_x == 0x0fff)   // û�д�����
        {
            Gui_Draw_Asc24_Hzk24(X_TOUCHX, X_Y0, TOUCH_DIG_FORCOLOR, TOUCH_DIG_BKCOLOR, (uint8_t*)"-----");
        }
        else
        {
            LCD_Digital_U16_Asc24(X_TOUCHX, X_Y0, TOUCH_DIG_FORCOLOR, TOUCH_DIG_BKCOLOR, cptxynow->ctpxy.ctp_x);
        }
    }
    
    if(cptxynow->ctpxy.ctp_y != cptxylast.ctpxy.ctp_y)  // ����ֵ�仯��, ��ʾ, ��������ʾά��ԭ״̬
    {
        if(cptxynow->ctpxy.ctp_y == 0x0fff)   // û�д�����
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
// �� �� ��:      tftDisp_Test_Val(uint16_t val_x, uint16_t val_y)
// ������������:  ��ʾ valueX valueY ��ֵ
// ��������:      x,y ����;  forcolor:ǰ��; bkcolor:����; char *string:��ʾ���ַ���   
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
static  uint8_t x_last=0,y_last=0;
void  tftDisp_Test_Val(uint16_t val_x, uint16_t val_y)
{
    if(val_x != x_last) // ����ֵ�仯��, ��ʾ, ��������ʾά��ԭ״̬
    { 
        LCD_Digital_U16_Asc24(VALUE_X_X1, VALUE_X_Y0, VAL_X_FORCOLOR, VAL_X_BKCOLOR, val_x); 
        x_last = val_x;
    }
    
    if(val_y != y_last) // ����ֵ�仯��, ��ʾ, ��������ʾά��ԭ״̬
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
// �� �� ��:      tftDisp_DataTime(struRTC  nowrtc)
// ������������:  ��ʾ ���ڵ����ں�ʱ�� 
// ��������:      struRTC  nowrtc: ���ں�ʱ�� 
// �� �� ֵ:      ��       
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     �Ѿ���ɲ���
// ������Σ�     �����û���--������ܲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2017-5-10
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void  tftDisp_DataTime(struRTC  nowrtc)
{
    if(nowrtc.second == 0x00)
    {
        tftDisp_AllDataTime(nowrtc);   // ����ʾ��
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
//        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN10_VAL, Y_ADC1_IN10, ADC1_FORCOLOR, ADC1_BKCOLOR, ad10); // ��ʾ"ADC1_IN10" ��ʮ������ֵ
        Gui_Draw_24_Dig_U16_Decimal(X_ADC1_IN10_VAL, Y_ADC1_IN10, ADC1_FORCOLOR, ADC1_BKCOLOR, ad10); // ��ʾ"ADC1_IN10" ��ʮ����ֵ
    }
    
    if(ad11 != ad11_last)
    {
        ad11_last = ad11;
//        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN11_VAL, Y_ADC1_IN11, ADC1_FORCOLOR, ADC1_BKCOLOR, ad11); // ��ʾ"ADC1_IN11" ��ʮ������ֵ
        Gui_Draw_24_Dig_U16_Decimal(X_ADC1_IN11_VAL, Y_ADC1_IN11, ADC1_FORCOLOR, ADC1_BKCOLOR, ad11); // ��ʾ"ADC1_IN11" ��ʮ����ֵ        
    }
    
    if(ad12 != ad12_last)
    {
        ad12_last = ad12;
        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN12_VAL, Y_ADC1_IN12, ADC1_FORCOLOR, ADC1_BKCOLOR, ad12); // ��ʾ"ADC1_IN12" ��ʮ������ֵ
    }
    
    if(ad13 != ad13_last)
    {
        ad13_last = ad13; 
        Gui_Draw_24_Dig_U16_Hex(X_ADC1_IN13_VAL, Y_ADC1_IN13, ADC1_FORCOLOR, ADC1_BKCOLOR, ad13); // ��ʾ"ADC1_IN13" ��ʮ������ֵ
    }
    
}
