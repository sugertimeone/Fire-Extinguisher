#ifndef __DS18B20_H
#define __DS18B20_H 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//DS18B20��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/7
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved										  
//////////////////////////////////////////////////////////////////////////////////
#include "stm32f1xx_hal.h"
#include "main.h"
#include "delay.h"
//IO��������
 
 
////IO��������											   
#define	DS18B20_DQ_OUT_SET   HAL_GPIO_WritePin(DS18B20_DQ_GPIO_Port,DS18B20_DQ_Pin, GPIO_PIN_SET)
#define	DS18B20_DQ_OUT_RESET HAL_GPIO_WritePin(DS18B20_DQ_GPIO_Port,DS18B20_DQ_Pin, GPIO_PIN_RESET)
#define DS18B20_DQ_IN HAL_GPIO_ReadPin(DS18B20_DQ_GPIO_Port,DS18B20_DQ_Pin)
#define u8 uint8_t
#define delay_us Delay_us
   	
u8 DS18B20_Init(void);			//��ʼ��DS18B20
short DS18B20_Get_Temp(void);	//��ȡ�¶�
void DS18B20_Start(void);		//��ʼ�¶�ת��
void DS18B20_Write_Byte(u8 dat);//д��һ���ֽ�
u8 DS18B20_Read_Byte(void);		//����һ���ֽ�
u8 DS18B20_Read_Bit(void);		//����һ��λ
u8 DS18B20_Check(void);			//����Ƿ����DS18B20
void DS18B20_Rst(void);			//��λDS18B20   
void DS18B20_IO_IN();
void DS18B20_IO_OUT();
#endif















