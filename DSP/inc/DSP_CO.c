#include "DSP_CO.h"
uint8_t mode[9]={0xFF,0x01,0x78,0x40,0x00,0x00,0x00,0x00,0x47};
void DSPCoInit(void)
{
	HAL_UART_Transmit(&huart1,mode,9,0);
}


unsigned char FucCheckSum(unsigned char *i,unsigned char ln)
{
unsigned char j,tempq=0;
i+=1;
for(j=0;j<(ln-2);j++)
{
tempq+=*i;
i++;
}
tempq=(~tempq)+1;
return(tempq);
}
