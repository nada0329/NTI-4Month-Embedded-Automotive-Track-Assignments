/*
 * GccApplication1.c
 *
 * Created: 3/4/2023 10:38:38 AM
 * Author : Nada
 */ 


#include "type.h"
#include "bit.h"
#include "DIO.h"
#include "kit_cnfg.h"
#include "GlobalINT.h"
#include "LED.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"

#include "SPI_priv.h"
#include "SPI_conf.h"
#include "SPI_int.h"


int main(void)
{
	LCD_voidInit();
	LCD_voidClearDisplay();
	
	SPI_Init(SPI_SLV);
	
	u8 x=0;
	LED_init(LED_BLUE_PORT,LED_BLUE_PIN);
	LED_init(LED_RED_PORT,LED_RED_PIN);
	LED_init(LED_GREEN_PORT,LED_GREEN_PIN);
	LED_init(LED_YELLOW_PORT,LED_YELLOW_PIN); 
	
	while(1)
	{
		LCD_WritingPosition(1,1);
		LCD_voidWriteString("Lights");
		x=SPI_Slv_RecData();
		switch(x)
		{
			case 10:
			LED_TOG(LED_BLUE_PORT,LED_BLUE_PIN);
			break;
			case 11:
			LED_TOG(LED_RED_PORT,LED_RED_PIN);
			break;
			case 12:
			LED_TOG(LED_GREEN_PORT,LED_GREEN_PIN);
			break;
			case 13:
			LED_TOG(LED_YELLOW_PORT,LED_YELLOW_PIN);
			break;
			default:
			break;
		}
	}
	
	
	
	
		
  
	
}

