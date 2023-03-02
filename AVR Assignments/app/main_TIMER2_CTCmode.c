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


void func2_c(void);

int main(void)
{
	LED_init(LED_RED_PORT,LED_RED_PIN);
	TIMER2_void_SetCTCCallBack(func2_c);
	TIMER2_void_Init();
	TIMER2_void_SetCompareVal(250);
	TIMER2_void_EnableCTCInt();
	GlobalINT_Enable();
	while (1)
	{
		
		
	}
}

void func2_c(void)
{
	static volatile u8 count_t=0;
	if(count_t==19)
	{
		count_t=0;
		LED_TOG(LED_RED_PORT,LED_RED_PIN);
	}
	else
	{
		count_t++;
	}
}
