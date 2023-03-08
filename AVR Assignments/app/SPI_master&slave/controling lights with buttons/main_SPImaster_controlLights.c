/*
 * GccApplication1.c
 *
 * Created: 3/4/2023 10:38:38 AM
 * Author : Nada
 */ 

#include "type.h"
#include "bit.h"
#include "kit_cnfg.h"
#include "DIO.h"
#include "Button.h"
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
	
	SPI_Init(SPI_MSTR);
	
	PB_Init(PB1);
	PB_Init(PB2);
	PB_Init(PB3);
	PB_Init(PB4);
	
	while(1)
	{
		LCD_WritingPosition(1,1);
		LCD_voidWriteString("Control");
		if(PB_GetState(PB1)==PB_PRESS)
			SPI_Mstr_SendData(10);
		if(PB_GetState(PB2)==PB_PRESS)
			SPI_Mstr_SendData(11);
		if(PB_GetState(PB3)==PB_PRESS)
			SPI_Mstr_SendData(12);
		if(PB_GetState(PB4)==PB_PRESS)
			SPI_Mstr_SendData(13);
	}
	
		
	
	
	
}

