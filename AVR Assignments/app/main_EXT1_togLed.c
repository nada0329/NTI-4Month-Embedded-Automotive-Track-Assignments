/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "EXTI1_int.h"
#include "EXTI1_Config.h"
#include "EXTI1_private.h"
#include "GlobalINT.h"

void func(void);
int main(void)
{
	LED_init(LED_BLUE_PORT,LED_BLUE_PIN);
	DIO_voidSetPinDir(DPORT,Pin3,input);
	EXT1_voidInit();
	EXT1_voidCallBack(func);
	EXT1_voidEnable();
	GlobalINT_Enable();
	while (1)
	{
		
	}
}

void func(void)
{
	LED_TOG(LED_BLUE_PORT,LED_BLUE_PIN);
}