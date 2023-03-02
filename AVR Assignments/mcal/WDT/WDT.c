/*
 * WDT.c
 *
 *  Created on: Jan 07, 2023
 *      Author: Nada
 */

#include "WDT.h"

void WDT_Init(WDT_Prescaler pre)
{
	/*enable WDT*/
	setbit(WDTCR_REG,WDE);
	/*select period*/
	WDTCR_REG&=0xf8; // make sure first 3bits=0
	WDTCR_REG|=pre;  // assign pre value
}
void WDT_Enable()
{
	setbit(WDTCR_REG,WDE);
}
void WDT_reset()
{
	WDR();
	//asm volatile("wdr=0");
}
void WDT_Disable()
{
	/*write one to WDTOE and WDE in same operation*/
	WDTCR_REG |= (1 << WDTOE) | (1 << WDE);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}
