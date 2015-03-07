/*
 * DAC.c
 *
 *  Created on: Mar 6, 2015
 *      Author: Mikew
 */

#include "../inc/DAC.h"

static bool U0C0_SSC_vSendData(uint16_t Data) // 不需要更改传入的参数,使用传入变量的拷贝值即可
{
	bool Result = FALSE;
	Result = SPI001_WriteData(&SPI001_Handle0, &Data, SPI001_STANDARD);
	return Result;
}
bool DAOutputs(uint16_t *Data,uint16_t Num)
{
	bool Result = FALSE;
    uint16_t channel, DAFIFO[8];

    for (channel=0;channel<Num;channel++)
    {
           DAFIFO[channel] = (channel<<12)|(((Data[channel]+0x8000)>>4)&0x0FFF);//
           Result = U0C0_SSC_vSendData(DAFIFO[channel]);
           if(!Result)
           {
        	   break;
           }
    }
    return Result;
}
