/*
 * Button.c
 *
 *  Created on: Dec 11, 2022
 *      Author: Nada
 */


#include "Button.h"


void SW_Init(u8 id)
{
	switch(id)
	{	
		case SW1:	DIO_voidSetPinDir(SW_1_PORT,SW_1_PIN,input);	break;
		case SW2:	DIO_voidSetPinDir(SW_2_PORT,SW_2_PIN,input);	break;
		case SW3:	DIO_voidSetPinDir(SW_3_PORT,SW_3_PIN,input);	break;
		case SW4:	DIO_voidSetPinDir(SW_4_PORT,SW_4_PIN,input);	break;
		case SW5:	DIO_voidSetPinDir(SW_5_PORT,SW_5_PIN,input);	break;
		case SW6:	DIO_voidSetPinDir(SW_6_PORT,SW_6_PIN,input);	break;
		case SW7:	DIO_voidSetPinDir(SW_7_PORT,SW_7_PIN,input);	break;
		case SW8:	DIO_voidSetPinDir(SW_8_PORT,SW_8_PIN,input);	break;
		default:	break;
	}
	switch(id)
	{
		
		case SW1:	DIO_voidSetPinVal(SW_1_PORT,SW_1_PIN,high);	break;
		case SW2:	DIO_voidSetPinVal(SW_2_PORT,SW_2_PIN,high);	break;
		case SW3:	DIO_voidSetPinVal(SW_3_PORT,SW_3_PIN,high);	break;
		case SW4:	DIO_voidSetPinVal(SW_4_PORT,SW_4_PIN,high);	break;
		case SW5:	DIO_voidSetPinVal(SW_5_PORT,SW_5_PIN,high);	break;
		case SW6:	DIO_voidSetPinVal(SW_6_PORT,SW_6_PIN,high);	break;
		case SW7:	DIO_voidSetPinVal(SW_7_PORT,SW_7_PIN,high);	break;
		case SW8:	DIO_voidSetPinVal(SW_8_PORT,SW_8_PIN,high);	break;
		default:	break;
	}
}

u8 SW_GetState(u8 id)
{
	u8 state=SW_RELEASE;
	switch(id)
	{

		case SW1:	state= DIO_u8GetPinVal(SW_1_PORT,SW_1_PIN);	break;
		case SW2:	state= DIO_u8GetPinVal(SW_2_PORT,SW_2_PIN);	break;
		case SW3:	state= DIO_u8GetPinVal(SW_3_PORT,SW_3_PIN);	break;
		case SW4:	state= DIO_u8GetPinVal(SW_4_PORT,SW_4_PIN);	break;
		case SW5:	state= DIO_u8GetPinVal(SW_5_PORT,SW_5_PIN);	break;
		case SW6:	state= DIO_u8GetPinVal(SW_6_PORT,SW_6_PIN);	break;
		case SW7:	state= DIO_u8GetPinVal(SW_7_PORT,SW_7_PIN);	break;
		case SW8:	state= DIO_u8GetPinVal(SW_8_PORT,SW_8_PIN);	break;
		default:	break;
		
		
	}
	return state;
}


void PB_Init(u8 id)
{
	switch(id)
	{
		case PB1:	DIO_voidSetPinDir(PB_1_PORT,PB_1_PIN,input);	break;
		case PB2:	DIO_voidSetPinDir(PB_2_PORT,PB_2_PIN,input);	break;
		case PB3:	DIO_voidSetPinDir(PB_3_PORT,PB_3_PIN,input);	break;
		case PB4:	DIO_voidSetPinDir(PB_4_PORT,PB_4_PIN,input);	break;
		default:	break;
	}
	
}

u8 PB_GetState(u8 id)
{
	
	u8 state=PB_RELEASE;
	switch(id)
	{

		case PB1:
		if( DIO_u8GetPinVal(PB_1_PORT,PB_1_PIN)==PB_PRESS)
		{
			/* pressed */
			while( DIO_u8GetPinVal(PB_1_PORT,PB_1_PIN)==PB_PRESS);
			_delay_ms(50);
			state=PB_PRESS;
		}
		/*else
		state=PB_RELEASE;*/
		break;
		case PB2:
		if( DIO_u8GetPinVal(PB_2_PORT,PB_2_PIN)==PB_PRESS)
		{
			/* pressed */
			while( DIO_u8GetPinVal(PB_2_PORT,PB_2_PIN)==PB_PRESS );
			_delay_ms(50);
			state=PB_PRESS;
		}
		else
		state=PB_RELEASE;
		break;
		case PB3:
		if( DIO_u8GetPinVal(PB_3_PORT,PB_3_PIN)==PB_PRESS)
		{
			/* pressed */
			while( DIO_u8GetPinVal(PB_3_PORT,PB_3_PIN)==PB_PRESS );
			_delay_ms(50);
			state=PB_PRESS;
		}
		else
		state=PB_RELEASE;
		break;
		case PB4:
		if( DIO_u8GetPinVal(PB_4_PORT,PB_4_PIN)==PB_PRESS)
		{
			/* pressed */
			while( DIO_u8GetPinVal(PB_4_PORT,PB_4_PIN)==PB_PRESS );
			_delay_ms(50);
			state=PB_PRESS;
		}
		else
		state=PB_RELEASE;
		break;
		
		default:	break;
		
		
	}
	return state;
	

}
