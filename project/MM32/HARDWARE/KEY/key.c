#include "key.h"
#include "delay.h"


//////////////////////////////////////////////////////////////////////////////////	 
//������
//�������� ��������		   
//////////////////////////////////////////////////////////////////////////////////	 

//������ʼ������ 

void KEY_Init(void)
{
    
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA|RCC_AHBPeriph_GPIOB|RCC_AHBPeriph_GPIOC,ENABLE);//ʹ��GPIOA,GPIOB,GPIOCʱ��
    
    
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10|GPIO_Pin_11;//PB10,PB11,K3,K4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //PB10,PB11���ó��������� 
    GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB.10,11
    
} 
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//����ֵ��
//0��û���κΰ�������
//KEY_ONOFF_PRES��KEY3����
//KEY_BRAKE_PRES��KEY4����
u8 KEY_Scan(u8 mode)
{	 
    static u8 key_up=1;//�������ɿ���־
	  static u8 key_onoff=1;
	  static u8 key_brake=1;
	
    if(mode)key_up=1;  //when mode:0,��֧��������  
    if(key_up&&(key_onoff==0||key_brake==0))
    {
        key_up=0;
       
        if(KEY_ONOFF==0)//if yes, means this key has pressed
				{
					key_onoff = KEY_ONOFF;//update this key's status
					key_brake = KEY_BRAKE;//update this key's status
					return KEY_ONOFF_PRES;
				}
        else if(KEY_BRAKE==0)//if yes, means this key has pressed
				{
					key_onoff = KEY_ONOFF;//update this key's status
					key_brake = KEY_BRAKE;//update this key's status
					return KEY_BRAKE_PRES;
				}
    }
		else if(KEY_ONOFF==1&&KEY_BRAKE==1)//if yes, means all keys have released
		{			
			key_up=1; //all keys have released
    }	
		
    key_onoff = KEY_ONOFF;
		key_brake = KEY_BRAKE; 		
    return 0;// �ް�������
}






