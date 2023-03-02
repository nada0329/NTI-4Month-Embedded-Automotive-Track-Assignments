/*
 * GlobalINT.c
 *
 *  Created on: Dec 20, 2022
 *      Author: Nada
 */
 
#include "GlobalINT.h"
 
void GlobalINT_Enable()
{
	setbit(SREG_REG,7);
}

void GlobalINT_Disable()
{
	clrbit(SREG_REG,7);
}