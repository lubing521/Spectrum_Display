#include  "gui.h"
#include  "lcd_drive.h"
#include  "w25q64.h" 
#include  <string.h>
#include "font.h"
#include  "lcd_drive.h"


void Gui_Draw_aPixel(uint16_t x,uint16_t y,uint16_t color)
{
    Lcd_Set_XY(x,y);
    *(__IO uint16_t *) (Bank1_LCD_D) = color;
}  

void Gui_Circle(uint16_t X0,uint16_t Y0,uint16_t R,uint16_t fc) 
{ 
    int  x, y, d; 

    x = 0; 
    y = R; 
    d = 3-2*R;     // ���߳�ʼֵ
    while (x < y) 
    { 
        Gui_Draw_aPixel(X0+x,Y0+y,fc);     //        7 �Գƻ���8����
        Gui_Draw_aPixel(X0-x,Y0+y,fc);     //        6 
        Gui_Draw_aPixel(X0+x,Y0-y,fc);     //        2 
        Gui_Draw_aPixel(X0-x,Y0-y,fc);     //        3 
        Gui_Draw_aPixel(X0+y,Y0+x,fc);     //        8 
        Gui_Draw_aPixel(X0-y,Y0+x,fc);     //        5 
        Gui_Draw_aPixel(X0+y,Y0-x,fc);     //        1 
        Gui_Draw_aPixel(X0-y,Y0-x,fc);     //        4 

        if(d < 0) 
        {
            d = d + 4*x + 6; 
        }
        else 
        { 
            d = d + 4*(x-y) + 10; 
            y--; 
        } 
        x++; 
    } 
    
    if (x == y) 
    { 
        Gui_Draw_aPixel(X0+x,Y0+y,fc);     //  �Գƻ���8����
        Gui_Draw_aPixel(X0-x,Y0+y,fc); 
        Gui_Draw_aPixel(X0+x,Y0-y,fc); 
        Gui_Draw_aPixel(X0-x,Y0-y,fc); 
        Gui_Draw_aPixel(X0+y,Y0+x,fc); 
        Gui_Draw_aPixel(X0-y,Y0+x,fc); 
        Gui_Draw_aPixel(X0+y,Y0-x,fc); 
        Gui_Draw_aPixel(X0-y,Y0-x,fc); 
    } 
} 


void Gui_Draw_Line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t Color)   
{
    int  dx, dy, dx2, dy2, x_inc, y_inc, error, index, xx0, yy0;
                 
    xx0 = x0;
    yy0 = y0;   
    
    Lcd_Set_XY(x0,y0);
    dx = x1 - x0;        //����x����
    dy = y1 - y0;        //����y����

    if (dx >= 0)
    {
        x_inc = 1;
    }
    else
    {
        x_inc = -1;
        dx    = -dx;  
    } 
    
    if (dy >= 0)
    {
        y_inc = 1;
    } 
    else
    {
        y_inc = -1;
        dy    = -dy; 
    } 

    dx2 = dx << 1;
    dy2 = dy << 1;

    if(dx > dy) //x�������y���룬��ôÿ��x����ֻ��һ���㣬ÿ��y���������ɸ��� //���ߵĵ�������x���룬��x���������
    { 
        error = dy2 - dx; 
        for (index=0; index <= dx; index++)//Ҫ���ĵ������ᳬ��x����
        {
            Gui_Draw_aPixel(xx0,yy0,Color);  //����
            if(error >= 0)                 //�Ƿ���Ҫ����y����ֵ
            {
                error -= dx2;
                yy0   += y_inc;            //����y����ֵ
            } 
            error += dy2;                  // adjust the error term
            xx0   += x_inc;                //x����ֵÿ�λ���󶼵���1 // move to the next pixel
        }  
    } 
    else  //y�����x�ᣬ��ÿ��y����ֻ��һ���㣬x�����ɸ���  //��y��Ϊ��������
    { 
        error = dx2 - dy; // initialize error term
        for (index=0; index <= dy; index++)  // draw the line
        {   
            Gui_Draw_aPixel(xx0,yy0,Color);    // set the pixel
            if (error >= 0)                  // test if error overflowed
            {
                error -= dy2;
                xx0   += x_inc;              // move to next line
            }               
            error += dx2;     
            yy0   += y_inc;     
        } 
    }  
}



void Gui_Draw_Rect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t linecolor)
{
    Gui_Draw_Line(x0, y0, x1, y0, linecolor);
    Gui_Draw_Line(x0, y0, x0, y1, linecolor);
    Gui_Draw_Line(x0, y1, x1, y1, linecolor);
    Gui_Draw_Line(x1, y0, x1, y1, linecolor);
}



extern uint16_t POINT_COLOR;
extern uint16_t BACK_COLOR;
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num,uint8_t size)
{  							  
  uint16_t temp,t1,t;
	uint16_t y0=y;
	uint16_t colortemp=POINT_COLOR;   
	uint16_t csize=size/8*size/2;	
	//���ô���		   
	num=num-' ';//�õ�ƫ�ƺ��ֵ
	
	    for(t=0;t<csize;t++)
	    { 
				if(size==32)
				temp=asc32[num][t];  //����1206����   
				else if(size==64)
				temp=asc64[num][t];
				for(t1=0;t1<8;t1++)
				{			    
					if(temp&0x80)POINT_COLOR=colortemp;
					else POINT_COLOR=BACK_COLOR;
					Gui_Draw_aPixel(x,y, POINT_COLOR);	
					temp<<=1;
					y++;
					if((y-y0)==size)
					{
						y=y0;
						x++;
						break;
					}			
				} 
				
	    }    
		POINT_COLOR=colortemp;	 	  
}   

void showhz(uint16_t x, uint16_t y, uint8_t num,uint8_t size){
	uint16_t temp,t1,t;
	uint16_t y0=y;
	uint16_t colortemp=POINT_COLOR;     
	uint16_t csize=size/8*size;
	//���ô���		   
	
	    for(t=0;t<csize;t++)
	    {   
				if(size==80) temp=hz80[num][t]; 
				else if(size==64) temp=hz64[num][t]; 
				for(t1=0;t1<8;t1++)
				{			    
					if(temp&0x80)POINT_COLOR=colortemp;
					else POINT_COLOR=BACK_COLOR;
					Gui_Draw_aPixel(x,y, POINT_COLOR);	
					temp<<=1;
					y++;
					if((y-y0)==size)
					{
						y=y0;
						x++;
						break;
					}			
				} 
				
	    }    
		POINT_COLOR=colortemp;	 	  
}