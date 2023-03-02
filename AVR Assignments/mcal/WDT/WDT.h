/*
 * WDT.h
 *
 *  Created on: Jan 7, 2023
 *      Author: Nada
 */

#ifndef MCAL_WDT_H_
#define MCAL_WDT_H_

#include "Registers.h"

#define WDR() __asm__ __volatile__ ("wdr")

// WDTCR_REG
#define WDTOE	4
#define WDE		3
#define WDP2	2
#define WDP1	1	
#define WDP0	0


typedef enum
{
	WDT_TimeOut_16300us,
	WDT_TimeOut_32500us,
	WDT_TimeOut_65000us,
	WDT_TimeOut_130000us,
	WDT_TimeOut_260000us,
	WDT_TimeOut_520000us,
	WDT_TimeOut_1000000us,
	WDT_TimeOut_2100000us
	
}WDT_Prescaler;


void WDT_Init(WDT_Prescaler pre);
void WDT_Enable();
void WDT_reset();
void WDT_Disable();




#endif