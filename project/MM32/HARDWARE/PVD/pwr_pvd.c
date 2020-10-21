#include "pwr_pvd.h"
#include "Whole_Motor_Parameters.h"

//bool FLAG4V2 = FALSE;
//bool FLAG2V7 = FALSE;
/********************************************************************************************************
**������Ϣ :                       
**�������� ��
**������� ����
**������� ����
********************************************************************************************************/
void PVD_IRQHandler(void)
{
  if( RESET != EXTI_GetITStatus(EXTI_Line16))
  {
		//�����ж���
    EXTI->IMR &= (~ 0x10000);
		
    //VDD����PVD��ֵ
    if( 0x04 ==(PWR->CSR & 0x04))
    {
      //__set_FAULTMASK(1);//�ر������ж�
      NVIC_SystemReset();//��λ
    }
    
    EXTI_ClearITPendingBit(EXTI_Line16);
		
		//�����ж���
    EXTI->IMR |= 0x10000;
  }
}
/********************************************************************************************************
**������Ϣ :                       
**�������� ��
**������� ����
**������� ����
********************************************************************************************************/
void PVD_EXTI_Init(void)
{
  EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ
  
  EXTI_InitStructure.EXTI_Line = EXTI_Line16;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
  
  NVIC_InitStructure.NVIC_IRQChannel = PVD_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	PWR_PVDLevelConfig(PVD_VOLTAGE); //Generate PVD Interrupt if VDD voltage under 3.0V 
  PWR_PVDCmd(ENABLE);
  
}

