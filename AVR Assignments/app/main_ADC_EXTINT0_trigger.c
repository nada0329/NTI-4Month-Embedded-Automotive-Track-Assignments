/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 

#include "LED.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include <util/delay.h>
#include "GlobalINT.h"
#include "EXTI0_int.h"
#include "EXTI0_config.h"
#include "EXTI0_private.h"
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"

void func1(void);
void func(u16 p);
u16 val;

int main(void)
{
	
	DIO_voidSetPinDir(APORT,Pin0,input);
	
	LCD_voidInit();
	LCD_voidClearDisplay();
	LED_init(LED_BLUE_PORT , LED_BLUE_PIN);
	
	ADC_voidCallBack(func);
	ADC_voidInit();
	ADC_voidAutoTrigger();
	ADC_voidEnable();
	
	/* Ext1 button input & pullup */
	DIO_voidSetPinDir(DPORT,Pin2,input);
	DIO_voidSetPinVal(DPORT,Pin2,high);
	
	EXT0_voidCallBack(func1);
	EXT0_voidInit();
	
	EXT0_voidEnable();
	ADC_voidInterrputEnable();
	GlobalINT_Enable();
    /* Replace with your application code */
    while (1) 
    {
		LCD_WritingPosition(1,1);
		LCD_voidWriteString("ADC value");
		LCD_WritingPosition(2,1);
		LCD_ptrConvertIntToStrDisplay(val);
		
    }
}
// adc code 
void func(u16 p)
{
	val=p;
}

void func1(void)
{	
//	just to trigger this interupt really happen use led
LED_TOG(LED_BLUE_PORT,LED_BLUE_PIN);	

}

