/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */
#include "stm32f1xx_hal.h"
#include "stdint.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define LED_Pin GPIO_PIN_4
#define LED_GPIO_Port GPIOA
#define ALARM_KEY_Pin GPIO_PIN_6
#define ALARM_KEY_GPIO_Port GPIOA
#define ALARM_RESET_Pin GPIO_PIN_7
#define ALARM_RESET_GPIO_Port GPIOA
#define N00_Pin GPIO_PIN_0
#define N00_GPIO_Port GPIOB
#define N01_Pin GPIO_PIN_1
#define N01_GPIO_Port GPIOB
#define N02_Pin GPIO_PIN_2
#define N02_GPIO_Port GPIOB
#define N03_Pin GPIO_PIN_3
#define N03_GPIO_Port GPIOB
#define ALARM_BELL_OUT_Pin GPIO_PIN_5
#define ALARM_BELL_OUT_GPIO_Port GPIOB
#define CTL_OUT_Pin GPIO_PIN_6
#define CTL_OUT_GPIO_Port GPIOB
#define DS18B20_DQ_Pin GPIO_PIN_7
#define DS18B20_DQ_GPIO_Port GPIOB


/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */
#define CO_W 			50			//һ����̼Ũ��
#define TP_W			 40				//�¶ȱ�����ֵ
#define TP_V 			3.6				//һ���ӵ���������
#define TPW 			3
#define COW 			2
#define TPVW 			4
#define TPANDCOW 	1
#define releaseTimeofAlarm   120
#define timeOfDelivery				2
#define keySOfTime 						10 //��������ȥ��ʱ��
#define FiveMinutesStop       60//��������ʱ
 
static struct
{
	float concentration; //һ����̼Ũ��
	uint8_t con[9];
	float temp;						//��ǰ�¶�
	float tempx;					//�¶�С������
	float oldtemp;        //һ����ǰ���¶�
	uint8_t ID;						//���뿪�ؾ�����ID
	uint8_t temp_Data[8]; //���дӻ����¶�ֵ��������
	uint8_t temp_Datax[8];//���дӻ����¶�ֵС������
	uint32_t ID_Dat[8];	//���еĴӻ�IDֵ
	float temp_oneminutrData[8]; //���дӻ����¶�ֵһ����ǰ
	float temp_twominutrData[8]; //���дӻ����¶�ֵһ���Ӻ�
	uint8_t coPotency[8];				//�ӻ�һ����̼Ũ
	float x;
	float y;
	char Stop_W;
}data_Box;
static struct
{
	char Temp_Warn;							//�¶ȱ�����־
	char CoPotencyWarn;					//һ����̼Ũ�ȱ���
	char Temp_VWarn;						//�¶���������
	char NUM[8];								//�¶��쳣����λ������
	char NUM1[8];								//����Ũ���쳣����λ
	char W_Flag;
}flag;
static struct
{
	char OneSecond;//�ӻ����͵�����
	char FiveSecond;//������5s��
	char FiveSecond1;
	uint32_t ThirtySeconds;//������ʱ
	uint32_t ThirtySeconds1;//30s�ڵļ�������
	uint32_t FiveMinutes;//�������������
}CountTime;	
static void CAN1_Filter_Speed_Init(void);
static void CAN2_Filter_Speed_Init(void);
float kalmanFilter_A(float inData);
/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
