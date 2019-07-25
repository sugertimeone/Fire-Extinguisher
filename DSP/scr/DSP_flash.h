#ifndef 	__DSP_FLSH_H
#define 	__DSP_FLSH_H
#include "stm32f1xx_hal.h"


void writeFlashTest(uint32_t writeFlashData);
uint32_t readFlashTest(void);
void Flash_Iint(void);
#endif
