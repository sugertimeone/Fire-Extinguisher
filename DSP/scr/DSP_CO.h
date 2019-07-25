#ifndef __DSP_CO_H_
#define __DSP_CO_H_
#include "stm32f1xx_hal.h"
#include "usart.h"
void DSPCoInit(void);
unsigned char FucCheckSum(unsigned char *i,unsigned char ln);
#endif
