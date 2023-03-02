/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "TIMR2_int.h"
#include "TIMR2_priv.h"
#include "TIMR2_config.h"
#include "GlobalINT.h"



void func_o(void);

int main(void)
{
	LED_init(LED_RED_PORT,LED_RED_PIN);
	
	TIMER2_void_SetOVCallBack(func_o);
	TIMER2_void_Init();
	TIMER2_void_SetTimerReg(66);
	TIMER2_void_EnableOVInt();
	GlobalINT_Enable();

	while (1)
	{
		
		
	}
}

void func_o(void)
{
	static volatile u8 count2_t=0;
	if(count2_t==9)
	{
		TIMER2_void_SetTimerReg(66);
		count2_t=0;
		LED_TOG(LED_RED_PORT,LED_RED_PIN);
	}
	else
	{
		count2_t++;
	}
	
}




