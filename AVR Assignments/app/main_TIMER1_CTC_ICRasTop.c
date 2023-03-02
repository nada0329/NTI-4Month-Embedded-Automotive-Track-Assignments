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



void func_c1(void);
void func_c2(void);
int main(void)
{
	LED_init(LED_RED_PORT,LED_RED_PIN);
	LED_init(LED_BLUE_PORT,LED_BLUE_PIN);
	Timer1_SetCallBack_OCMA(func_c1);
	Timer1_SetCallBack_OCMB(func_c2);
	Timer1_Init();
	Timer1_SetTimingLimits_cmp_base_period(20000,40000,60000);
	Timer1_OCMAInt_Enable();
	Timer1_OCMBInt_Enable();
	GlobalINT_Enable();

	while (1)
	{
		
		
	}
}

// event each 600msec
void func_c1(void)
{
	static volatile u8 count1_t=0;
	if(count1_t==9)
	{
		count1_t=0;
		LED_TOG(LED_RED_PORT,LED_RED_PIN);
	}
	else
	{
		count1_t++;
	}
}

// event each 300msec
void func_c2(void)
{
	static volatile u8 count2_t=0;
	if(count2_t==4)
	{
		count2_t=0;
		LED_TOG(LED_BLUE_PORT,LED_BLUE_PIN);
	}
	else
	{
		count2_t++;
	}
	
	
}
