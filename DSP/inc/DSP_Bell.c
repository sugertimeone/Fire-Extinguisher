#include "DSP_Bell.h"
void BELLorLEDS(int mode)
{
	if(mode ==TPW)
	{
		if(CountTime.ThirtySeconds%TPW==0)
		HAL_GPIO_WritePin(ALARM_BELL_OUT_GPIO_Port,ALARM_BELL_OUT_Pin,GPIO_PIN_SET);
		if(CountTime.ThirtySeconds%2==0)
		HAL_GPIO_WritePin(ALARM_BELL_OUT_GPIO_Port,ALARM_BELL_OUT_Pin,GPIO_PIN_RESET);
		CountTime.ThirtySeconds++;
	}
	if(mode ==COW)
	{if(CountTime.ThirtySeconds%COW==0)
		HAL_GPIO_TogglePin(ALARM_BELL_OUT_GPIO_Port,ALARM_BELL_OUT_Pin);
		CountTime.ThirtySeconds++;
	}
	if(mode ==TPVW)
	{if(CountTime.ThirtySeconds%TPVW==0)
		HAL_GPIO_TogglePin(ALARM_BELL_OUT_GPIO_Port,ALARM_BELL_OUT_Pin);
		CountTime.ThirtySeconds++;
	}
	if(mode ==TPANDCOW)
	{if(CountTime.ThirtySeconds%TPANDCOW==0)
		HAL_GPIO_TogglePin(ALARM_BELL_OUT_GPIO_Port,ALARM_BELL_OUT_Pin);
		CountTime.ThirtySeconds++;
	}
}
