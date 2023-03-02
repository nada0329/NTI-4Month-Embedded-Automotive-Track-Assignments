/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 

#include "kit_cnfg.h"
#include <util/delay.h>
#include "DIO.h"
#include "GlobalINT.h"
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"


void func(u16 p);
u16 val;

int main(void)
{
	
	DIO_voidSetPinDir(APORT,Pin0,input);
	LCD_voidInit();
	LCD_voidClearDisplay();
	
	ADC_voidCallBack(func);
	ADC_voidInit();
	ADC_voidAutoTrigger();
	ADC_voidEnable();
	ADC_voidInterrputEnable();
	GlobalINT_Enable();
    /* Replace with your application code */
    while (1) 
    {
		LCD_WritingPosition(1,1);
		LCD_voidWriteString("ADC val:");
		LCD_WritingPosition(2,1);
		LCD_ptrConvertIntToStrDisplay(val);
		
		
    }
}
// adc call back to save reading of adc
void func(u16 p)
{
	val=p;
}



