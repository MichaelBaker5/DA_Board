/*
 * DAC.c
 *
 *  Created on: Mar 6, 2015
 *      Author: Mikew
 */

#include "../inc/DAC.h"

bool U0C0_SSC_vSendData(uint16_t Data) // 不需要更改传入的参数,使用传入变量的拷贝值即可
{
	bool Result = FALSE;
	IO004_SetOutputValue(IO004_Handle0,1);
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	IO004_SetOutputValue(IO004_Handle0,0);
	asm("NOP");
	asm("NOP");
	Result = SPI001_WriteData(&SPI001_Handle0, &Data, SPI001_STANDARD);
	return Result;
}
// TODO: 处理sync的问题
bool DAOutputs(uint16_t *Data,uint16_t Num)
{
	bool Result = FALSE;
    uint16_t channel, DAFIFO[8];

    for (channel=0;channel<Num;channel++)
    {
    	DAFIFO[channel] = ((channel<<12U)|(Data[channel] << 4U)) & (~(1 << 15U));//
           Result = U0C0_SSC_vSendData(DAFIFO[channel]);
           if(!Result)
           {
        	   break;
           }
    }
    asm("NOP");
    IO004_SetOutputValue(IO004_Handle0,1);
    return Result;
}
