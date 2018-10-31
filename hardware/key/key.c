#include  "key.h"
#include  "led.h"
#include  "usart.h"

/************************************************************************
// �� �� ��:      void  Key_Init(void)
// ������������:  ������������˿ڼ����ŵĳ�ʼ��                
// ��������:      ��
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     ��ɲ���
// ������Σ�     ���򰴼���·��--Ӳ���ӿڲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2014-12-14
// �� �� �ˣ�                                                                         
// �޸����ڣ�     201x-xx-xx
************************************************************************/ 
void  Key_GPIO_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    KEY_GPIO_CLK_ENABLE();
    
    // LED1�����ų�ʼ��
    GPIO_InitStruct.Pin  = KEY1_PIN | KEY2_PIN | KEY3_PIN | KEY4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOx_KEY_PORT, &GPIO_InitStruct);

}

/************************************************************************
// �� �� ��:      Init_KeyStatus(struKeyStatus *key)
// ������������:  ��ʼ��������״̬               
// ��������:      struKeysStatus  *key:  
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ��̬����:      key1_last,key2_last,key3_last,key4_last: 
// ����״̬��     ��ɲ���
// ������Σ�     ���򰴼���·��--���������

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2016-3-20
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/ 
void  Init_KeyStatus(struKeyStatus *key4)  
{ 
    key4->key1 = KEY_NO_PRESSED;
    key4->key2 = KEY_NO_PRESSED;
    key4->key3 = KEY_NO_PRESSED;
    key4->key4 = KEY_NO_PRESSED;
}

/************************************************************************
// �� �� ��:      void  Read_KeyStatus(struKeysStatus  *keynow)
// ������������:  ��ȡ������ǰ��״̬                
// ��������:      struKeysStatus  *keynow:  ����4��������ǰ��״̬ 
//                ������һ��4��������״̬��ͨ�������ڵİ���״̬�Ƚϣ���õ�ǰ����������״̬�ͼ���ֵ
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ����״̬��     ��ɲ���
// ������Σ�     ���򰴼���·��--Ӳ���ӿڲ�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2016-3-20
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/ 
void  Read_KeyStatus(struKeyStatus  *keynow)
{
    KeyStatus  key_last;
    
    /////////////////////////////////////////////////////////////
    // ���KEY1��״̬
    key_last = keynow->key1;     // �����ϴε�KEY1��״̬
    if( !READ_KEY1() )            // KEY1�ĵ�ƽ����Ϊ0, ����Ϊ1;
    {                             // KEY1��ǰ�ĵ�ƽΪ����
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key1 = KEY_ALREADY_PRESSED; 
        }
        else
        {
            keynow->key1 = KEY_JUST_PRESSED; 
        }
    }
    else                     // KEY1��ǰ�ĵ�ƽΪ����
    {
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key1 = KEY_JUST_POPUP;    
        }
        else
        {
            keynow->key1 = KEY_NO_PRESSED;
        }
    }
    /////////////////////////////////////////////////////////////
    // ���KEY2��״̬
    key_last = keynow->key2;      // �����ϴε�KEY1��״̬
    if( !READ_KEY2() )            // KEY2�ĵ�ƽ����Ϊ0, ����Ϊ1;
    {                             // KEY2��ǰ�ĵ�ƽΪ����
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key2 = KEY_ALREADY_PRESSED; 
        }
        else
        {
            keynow->key2 = KEY_JUST_PRESSED; 
        }
    }
    else                          // KEY2��ǰ�ĵ�ƽΪ����
    {
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key2 = KEY_JUST_POPUP;    
        }
        else
        {
            keynow->key2 = KEY_NO_PRESSED;
        }
    }    
    /////////////////////////////////////////////////////////////
    // ���KEY3��״̬
    key_last = keynow->key3;      // �����ϴε�KEY3��״̬
    if( !READ_KEY3() )            // KEY3�ĵ�ƽ����Ϊ0, ����Ϊ1;
    {                             // KEY3��ǰ�ĵ�ƽΪ����
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key3 = KEY_ALREADY_PRESSED; 
        }
        else
        {
            keynow->key3 = KEY_JUST_PRESSED; 
        }
    }
    else                          // KEY3��ǰ�ĵ�ƽΪ����
    {
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key3 = KEY_JUST_POPUP;    
        }
        else
        {
            keynow->key3 = KEY_NO_PRESSED;
        }
    }
    /////////////////////////////////////////////////////////////
    // ���KEY4��״̬
    key_last = keynow->key4;      // �����ϴε�KEY4��״̬
    if( !READ_KEY4() )            // KEY4�ĵ�ƽ����Ϊ0, ����Ϊ1;
    {                             // KEY4��ǰ�ĵ�ƽΪ����
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key4 = KEY_ALREADY_PRESSED; 
        }
        else
        {
            keynow->key4 = KEY_JUST_PRESSED; 
        }
    }
    else                          // KEY4��ǰ�ĵ�ƽΪ����
    {
        if( (key_last == KEY_JUST_PRESSED) || (key_last == KEY_ALREADY_PRESSED) ) 
        {
            keynow->key4 = KEY_JUST_POPUP;    
        }
        else
        {
            keynow->key4 = KEY_NO_PRESSED;
        }
    }    
}

/************************************************************************
// �� �� ��:      void  Key_Process(struKeyStatus *key)
// ������������:  �����Ĵ���                
// ��������:      struKeysStatus  *key:  4��������ǰ��״̬
// �� �� ֵ:      ��
// ����ֵ����:    ��
// ȫ�ֱ���:      ��
// ��̬����:      ��
// ����״̬��     ��ɲ���
// ������Σ�     Ӧ�ò�

// �� �� �ˣ�     zhaoweiliang
// ���ڣ�         2016-3-20
// �� �� �ˣ�                     
// �޸����ڣ�     201x-xx-xx
************************************************************************/
void  Key_Process(struKeyStatus *key)
{
    if(key->key1 == KEY_JUST_PRESSED)   { LED3_TOGGLE(); } // ����1 �հ���ʱ�Ķ���: LED3ȡ��
    

    if(key->key2 == KEY_JUST_PRESSED)   { LED4_ON();  }    // ����2 �հ���ʱ�Ķ���: LED4����
    else if(key->key2 == KEY_JUST_POPUP){ LED4_OFF(); }    // ����2 �յ���ʱ�Ķ���: LED4�ư�
    
    if(key->key3 == KEY_JUST_PRESSED)   { LED4_ON();  }    // ����3 
   
    if(key->key4 == KEY_JUST_PRESSED)   { U1_Test_SendString(); } // ����4 �հ���ʱ�Ķ���: ����1����һ���ַ���
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


