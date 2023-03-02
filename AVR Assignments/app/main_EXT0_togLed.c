/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "EXTI0_int.h"
#include "EXTI0_Config.h"
#include "EXTI0_private.h"
#include "GlobalINT.h"

void func(void);
int main(void)
{
	LED_init(LED_BLUE_PORT,LED_BLUE_PIN);
	DIO_voidSetPinDir(DPORT,Pin2,input);
	EXT0_voidInit();
	EXT0_voidCallBack(func);
	EXT0_voidEnable();
	GlobalINT_Enable();
	while (1)
	{
		
	}
}

void func(void)
{
	LED_TOG(LED_BLUE_PORT,LED_BLUE_PIN);
}