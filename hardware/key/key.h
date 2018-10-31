#ifndef __KEY_H__
#define __KEY_H__ 
////////////////////////////////////////////////////////////////////////////////// 
#include "stm32f4xx_hal.h"


//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#define    KEY_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOE_CLK_ENABLE()
#define    GPIOx_KEY_PORT      GPIOE                 // key1 �����������ڵĶ˿�

#define    KEY1_PIN            GPIO_PIN_0            // key1 ���ź�
#define    KEY2_PIN            GPIO_PIN_1            // key2 ���ź�
#define    KEY3_PIN            GPIO_PIN_2            // key3 ���ź�
#define    KEY4_PIN            GPIO_PIN_3            // key4 ���ź�

#define    READ_KEY1()         HAL_GPIO_ReadPin(GPIOx_KEY_PORT, KEY1_PIN)        // PE0
#define    READ_KEY2()         HAL_GPIO_ReadPin(GPIOx_KEY_PORT, KEY2_PIN)        // PE1
#define    READ_KEY3()         HAL_GPIO_ReadPin(GPIOx_KEY_PORT, KEY3_PIN)        // PE2
#define    READ_KEY4()         HAL_GPIO_ReadPin(GPIOx_KEY_PORT, KEY4_PIN)        // PE3

//#define    READ_KEY1()         READ_KEYx_PIN(pinKEY1)        // PE7
//#define    READ_KEY2()         READ_KEYx_PIN(pinKEY2)        // PE8
//#define    READ_KEY3()         READ_KEYx_PIN(pinKEY3)        // PE9
//#define    READ_KEY4()         READ_KEYx_PIN(pinKEY4)        // PE10

//////////////////////////////////////////////////////

typedef  enum
{
    KEY_NO_PRESSED      = 0,
    KEY_JUST_PRESSED       ,
    KEY_ALREADY_PRESSED    ,
    KEY_JUST_POPUP         ,
}KeyStatus;

typedef  struct
{
    KeyStatus  key1;        // ����KEY1��״̬
    KeyStatus  key2;        // ����KEY2��״̬
    KeyStatus  key3;        // ����KEY3��״̬
    KeyStatus  key4;        // ����KEY4��״̬
}struKeyStatus;            
//////////////////////////////////////////////////////

//////////////////////////////////////////////
void  Read_KeyStatus(struKeyStatus  *);
void  Key_GPIO_Init(void);
void  Init_KeyStatus(struKeyStatus *);
void  Key_Process(struKeyStatus *);
    
#endif
