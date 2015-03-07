/*
 * Main.c
 *
 *  Created on: Mar 6, 2015
 *      Author: Mikew
 */





#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "Dave/Generated/inc/SPI001/SPI001.h"

static uint16_t SendData = 0x5555;
/*extern bool SPI001_WriteData
(
  const SPI001_HandleType* Handle,
  const uint16_t* DataPtr,
  SPI001_TransmitMode TrMode
);*/

int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)


	DAVE_Init();			// Initialization of DAVE Apps


	while(1)
	{
	    /* the slave will send 16 bit data back */
	    // Clear the flags before writing data
	//	SPI001_ClearFlag(&SPI001_Handle0, SPI001_RECV_IND_FLAG);
	    /*
		 * SPI001_ClearFlag(&SPI001_Handle0, SPI001_ALT_RECV_IND_FLAG);
	     */
		SPI001_WriteData(&SPI001_Handle0, &SendData, SPI001_STANDARD); // 1

	}
	return 0;
}
