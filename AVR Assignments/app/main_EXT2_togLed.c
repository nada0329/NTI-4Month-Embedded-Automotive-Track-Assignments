/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "EXTI2_int.h"
#include "EXTI2_Config.h"
#include "EXTI2_private.h"
#include "GlobalINT.h"

void func(void);
int main(void)
{
	LED_init(LED_BLUE_PORT,LED_BLUE_PIN);
	DIO_voidSetPinDir(BPORT,Pin2,input);
	EXT2_voidInit();
	EXT2_voidCallBack(func);
	EXT2_voidEnable();
	GlobalINT_Enable();
	while (1)
	{
		
	}
}

void func(void)
{
	LED_TOG(LED_BLUE_PORT,LED_BLUE_PIN);
}