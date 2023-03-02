/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "TIMR1_int.h"
#include "TIMR1_priv.h"
#include "TIMR1_config.h"
#include "GlobalINT.h"



void func_o1(void);

int main(void)
{
	LED_init(LED_RED_PORT,LED_RED_PIN);
	
	Timer1_SetCallBack_OVF(func_o1);
	Timer1_Init();
	Timer1_SetTimingLimits_ovf(48576);
	Timer1_OVFInt_Enable();
	GlobalINT_Enable();

	while (1)
	{
		
		
	}
}

void func_o1(void)
{
	static volatile u8 count1_t=0;
	if(count1_t==15)
	{
		Timer1_SetTimingLimits_ovf(48576);
		count1_t=0;
		LED_TOG(LED_RED_PORT,LED_RED_PIN);
	}
	else
	{
		count1_t++;
	}
	
	
}