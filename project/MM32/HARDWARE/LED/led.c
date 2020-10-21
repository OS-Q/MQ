
#include "led.h"
#include "Whole_Motor_Parameters.h"

/********************************************************************************************************
**������Ϣ ��LED_Init(void)
**�������� ��LED��ʼ��
**������� ����
**������� ����
********************************************************************************************************/
void LED_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

	  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);  //����GPIOAʱ��
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11 |GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

	  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);  //����GPIOBʱ��
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//setup to Pull up input
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);  //����GPIOCʱ��
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13 |GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    LED0_OFF;
    LED1_OFF;


//	  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);  //����GPIOA,GPIOBʱ��
//    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//	  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);  //����GPIOA,GPIOBʱ��
//    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);

//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA|RCC_AHBPeriph_GPIOB, ENABLE);  //����GPIOA,GPIOBʱ��
//
//    GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_15;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);

//    LED2_OFF();
//    LED3_OFF();
//    LED4_OFF();
}

