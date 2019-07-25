#include "DSP_flash.h"


uint32_t addr=0x08007000;

void Flash_Iint(void)
{
//	uint64_t data1=0xFF0001;
//	if(!((readFlashTest()&(0xFF<<4))&&((readFlashTest()&(0x01<<0)))))
//	{
//		writeFlashTest(data1);
//	}
	if(readFlashTest()!=2||readFlashTest()!=1)	writeFlashTest(1);
}

void writeFlashTest(uint32_t writeFlashData)
{
	//解锁FLAH
	HAL_FLASH_Unlock();
	
	//擦除FLASH
	FLASH_EraseInitTypeDef f;
	f.TypeErase = FLASH_TYPEERASE_PAGES;
	f.PageAddress = addr;
	f.NbPages = 1;
	
	//设置PageError
	uint32_t PageError=0;
	HAL_FLASHEx_Erase(&f,&PageError);
	
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,addr,writeFlashData);
	
	HAL_FLASH_Lock();
}

//FLASH读取数据测试
uint32_t readFlashTest(void)
{
	uint32_t temp =*(__IO uint32_t*)(addr);
	return temp;
}
