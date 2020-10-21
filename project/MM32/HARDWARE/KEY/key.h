#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������
//������������	   
//////////////////////////////////////////////////////////////////////////////////   	 

#define KEY_ONOFF  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)//��ȡ����3
#define KEY_BRAKE  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)//��ȡ����4


#define KEY_ONOFF_PRES	3		//KEY3 
#define KEY_BRAKE_PRES	4		//KEY4 
void KEY_Init(void);        //IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��					    
#endif
