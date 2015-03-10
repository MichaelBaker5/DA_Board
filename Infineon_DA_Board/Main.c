/*
 * Main.c
 *
 *  Created on: Mar 6, 2015
 *      Author: Mikew
 */





#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "Dave/Generated/inc/SPI001/SPI001.h"
#include "DA/inc/DAC.h"

static uint16_t SendData[3] = {0};
uint16_t Data[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	bool Result = FALSE;

	DAVE_Init();			// Initialization of DAVE Apps
	// Reset mode : DAC data and control reset.
	SendData[0] = (uint16_t)((1 << 15U)  | (7 << 12U));
	// Output range : 0 ~ 1*VREF.
	// VDD is used as a reference.
	SendData[1] = (uint16_t)((1 << 15U)  | (3 <<  0U));
	// LDAC permanently low allowing the DAC registers to be updated continuously.
	SendData[2] = (uint16_t)(((1 << 15U) | (1 << 13U)) & (1 << 0U));
	U0C0_SSC_vSendData(SendData[0]);
	U0C0_SSC_vSendData(SendData[1]);
	U0C0_SSC_vSendData(SendData[2]);

	while(1)
	{
        Result = DAOutputs(Data,8);
	}
	return 0;
}

