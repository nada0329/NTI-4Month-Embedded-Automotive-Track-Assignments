/*
 * GccApplication1.c
 *
 * Created: 2/24/2023 9:34:22 AM
 * Author : Nada
 */ 

//#define FCPU 8000000UL
//#include <util/delay.h>
#include "LED.h"
#include "DIO.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include "kit_cnfg.h"
#include "TIMR0_int.h"
#include "TIMR00_priv.h"
#include "TIMR0_config.h"
#include "GlobalINT.h"


/*
	to use this code change kit_config file for LCD
	as PIN0 of PORTB used in LCD for kit but here use it as input for timer
	for LCD use PIN3 instead of PIN0
*/
int main(void)
{
	LCD_voidInit();
	LCD_voidClearDisplay();
	DIO_voidSetPinDir(BPORT,Pin0,input);
	TIMER0_void_Init();
	TIMER0_void_EnableOVInt();
	u8 val=0;
	while (1)
	{
		LCD_WritingPosition(1,1);
		LCD_voidWriteString("T0");
		LCD_WritingPosition(2,1);
		val=TIMER0_u8_CounterValue();
		LCD_ptrConvertIntToStrDisplay((u16)val);
		
	}
}