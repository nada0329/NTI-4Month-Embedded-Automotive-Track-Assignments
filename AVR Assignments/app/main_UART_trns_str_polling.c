/*
 * GccApplication1.c
 *
 * Created: 3/3/2023 9:36:09 AM
 * Author : Nada
 */ 

#include "type.h"
#include "bit.h"
#include "DIO.h"
#include "GlobalINT.h"
#include "LED.h"
#include "Button.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_int.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "uart_reg.h"
#include "uart.h"




int main(void)
{
	LCD_voidInit();
	LCD_voidClearDisplay();
	UART_Init(UART_BAUDRATE_9600);
	
	
    while (1) 
    {		
		// trans str in poll
		UART_TransmitStr("nada");
		
		
		
		
	}
}
