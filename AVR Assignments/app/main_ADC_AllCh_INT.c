/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 

#include "kit_cnfg.h"
#include "DIO.h"
#include "GlobalINT.h"
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"


void func_adc(u16 p);
u16 adc_value[8];

int main(void)
{
	
	// make adc ch input
	DIO_voidSetPinDir(APORT,Pin0,input);
	DIO_voidSetPinDir(APORT,Pin1,input);
	DIO_voidSetPinDir(APORT,Pin2,input);
	DIO_voidSetPinDir(APORT,Pin3,input);
	DIO_voidSetPinDir(APORT,Pin4,input);
	DIO_voidSetPinDir(APORT,Pin5,input);
	DIO_voidSetPinDir(APORT,Pin6,input);
	DIO_voidSetPinDir(APORT,Pin7,input);
	
	LCD_voidInit();
	LCD_voidClearDisplay();
	
	ADC_voidCallBack(func_adc);
	ADC_voidInit();
	ADC_voidAutoTrigger();
	ADC_voidEnable();
	ADC_voidInterrputEnable();
	GlobalINT_Enable();
    /* Replace with your application code */
    while (1) 
    {
		ADC_ReadAllCh_INT(adc_value);
		LCD_WritingPosition(1,1);
		LCD_ptrConvertIntToStrDisplay(adc_value[0]);
		LCD_WritingPosition(1,8);
		LCD_ptrConvertIntToStrDisplay(adc_value[1]);
		LCD_WritingPosition(2,1);
		LCD_ptrConvertIntToStrDisplay(adc_value[2]);
		LCD_WritingPosition(2,8);
		LCD_ptrConvertIntToStrDisplay(adc_value[3]);
		LCD_WritingPosition(3,1);
		LCD_ptrConvertIntToStrDisplay(adc_value[4]);
		LCD_WritingPosition(3,8);
		LCD_ptrConvertIntToStrDisplay(adc_value[5]);
		LCD_WritingPosition(4,1);
		LCD_ptrConvertIntToStrDisplay(adc_value[6]);
		LCD_WritingPosition(4,8);
		LCD_ptrConvertIntToStrDisplay(adc_value[7]);
		
		
    }
}
// adc call back to save reading of adc
void func_adc(u16 p)
{
	ADC_ReadAllCh_INT(adc_value);
}



