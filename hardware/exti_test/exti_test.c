#include  "exti_test.h"

void  Exti_Test_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    
    /*Configure GPIO pin : PG8 */
    EXTI_TEST_IN_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin   = EXTI_TEST_IN_PIN;
    GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING_FALLING;   // ��ƽ����
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    HAL_GPIO_Init(EXTI_TEST_IN_PORT, &GPIO_InitStruct);    // �˴���ʼ���������жϵĳ�ʼ��
         
    /*Configure GPIO pin : PF0 */
    EXTI_TEST_OUT_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin   = EXTI_TEST_OUT_PIN;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(EXTI_TEST_OUT_PORT, &GPIO_InitStruct);   // PF0���ڸ���PG8
}

//////////////////
// �ⲿ�����жϻص�����
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == EXTI_TEST_IN_PIN)   // �ⲿ���Ŵ����жϵĻص�����
  {
      if(Get_EXTI_TEST_Pin())        // �ж����Ÿߵ�ƽ, ������������ߵ�ƽ
      {
          EXTI_TEST_OUT_H();
      }
      else
      {
          EXTI_TEST_OUT_L();         // �ж����ŵ͵�ƽ, ������������͵�ƽ
      }
  }
}

