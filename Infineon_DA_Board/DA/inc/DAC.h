/*
 * DAC.h
 *
 *  Created on: Mar 6, 2015
 *      Author: Mikew
 */

#ifndef DAC_H_
#define DAC_H_

#include <DAVE3.h>

bool DAOutputs(uint16_t *Data,uint16_t Num);
static bool U0C0_SSC_vSendData(uint16_t Data);
#endif /* DAC_H_ */
