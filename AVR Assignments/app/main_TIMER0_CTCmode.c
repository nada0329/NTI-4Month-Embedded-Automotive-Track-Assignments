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




void func_c(void);

int main(void)
{
	LED_init(LED_RED_PORT,LED_RED_PIN);
	TIMER0_void_SetCTCCallBack(func_c);
	TIMER0_void_Init();
	TIMER0_void_SetCompareVal(250);
	TIMER0_void_EnableCTCInt();
	GlobalINT_Enable();
    while (1) 
    {
		
		
    }
}

void func_c(void)
{
	static volatile u8 count_t=0;
	if(count_t==4)
	{
		count_t=0;
		LED_TOG(LED_RED_PORT,LED_RED_PIN);
	}
	else
	{
		count_t++;
	}
}






