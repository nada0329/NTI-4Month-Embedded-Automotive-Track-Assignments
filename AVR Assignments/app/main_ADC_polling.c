/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 


#include "kit_cnfg.h"
#include "DIO.h"
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"


u16 val;

int main(void)
{
	
	u16 adc_value=0;
	/* make adc ch0 input */
	DIO_voidSetPinDir(APORT,Pin0,input);
	/* lcd init */
	LCD_voidInit();
	LCD_voidClearDisplay();
	/* adc setup */
	ADC_voidInit();
	ADC_voidAutoTrigger();
	ADC_voidEnable();
	
	
    /* Replace with your application code */
    while (1) 
    {
		ADC_voidStartConversion();
		adc_value=ADC_u16ReadADCInMV();
		LCD_WritingPosition(1,1);
		LCD_voidWriteString("ADC value: ");
		LCD_WritingPosition(2,1);
		LCD_ptrConvertIntToStrDisplay(adc_value);
		
		adc_value=0;
		
    }
}
