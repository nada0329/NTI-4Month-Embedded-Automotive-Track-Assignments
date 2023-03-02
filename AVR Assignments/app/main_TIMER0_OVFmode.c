/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "TIMR0_int.h"
#include "TIMR00_priv.h"
#include "TIMR0_config.h"
#include "GlobalINT.h"






void func_o(void);

int main(void)
{
	LED_init(LED_RED_PORT,LED_RED_PIN);
	
	TIMER0_void_SetOVCallBack(func_o);
	TIMER0_void_Init();
	TIMER0_void_SetTimerReg(66);
	TIMER0_void_EnableOVInt();
	GlobalINT_Enable();

	while (1)
	{
		
		
	}
}

void func_o(void)
{
	static volatile u8 count_t=0;
	if(count_t==4)
	{
		TIMER0_void_SetTimerReg(66);
		count_t=0;
		LED_TOG(LED_RED_PORT,LED_RED_PIN);
	}
	else
	{
		count_t++;
	}
	
}




