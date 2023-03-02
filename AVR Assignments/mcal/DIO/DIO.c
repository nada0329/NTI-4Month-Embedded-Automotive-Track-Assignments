/*
 * DIO.c
 *
 *  Created on: Dec 10, 2022
 *      Author: Nada
 */


#include "DIO.h"


/****************
 *
 *  0 ->input    low
 *  1 ->output   high
 *
 ***************/

u8 DIO_u8GetPinVal(u8 PortName , u8 PinNum)
{
	u8 Pin_Val=0;
	switch(PortName)
	{
		case APORT:
		{
			Pin_Val =getbit(PINA_REG,PinNum);
			break;
		}
		case BPORT:
		{
			Pin_Val =getbit(PINB_REG,PinNum);
			break;
		}
		case CPORT:
		{
			Pin_Val =getbit(PINC_REG,PinNum);
			break;
		}
		case DPORT:
		{
			Pin_Val =getbit(PIND_REG,PinNum);
			break;
		}
		default : break;

	}

return Pin_Val;
}
//-----------------------------------------------------------
void DIO_voidSetPinVal(u8 PortName , u8 PinNum , u8 PinVal)
{
	if(PinVal == high)
	{
		switch(PortName)
		{
			case APORT:
			{
				setbit(PORTA_REG,PinNum);
				break;
			}
			case BPORT:
			{
				setbit(PORTB_REG,PinNum);
				break;
			}
			case CPORT:
			{
				setbit(PORTC_REG,PinNum);
				break;
			}
			case DPORT:
			{
				setbit(PORTD_REG,PinNum);
				break;
			}
			default: break;
		}
	}
	else if (PinVal == low)
	{
		switch(PortName)
		{
			case APORT:
			{
				clrbit(PORTA_REG,PinNum);
				break;
			}
			case BPORT:
			{
				clrbit(PORTB_REG,PinNum);
				break;
			}
			case CPORT:
			{
				clrbit(PORTC_REG,PinNum);
				break;
			}
			case DPORT:
			{
				clrbit(PORTD_REG,PinNum);
				break;
			}
			default: break;
		}
	}

}
//------------------------------------------------------------
void DIO_voidTogPinVal(u8 PortName , u8 PinNum)
{
	switch(PortName)
	{
		case APORT:
		{
			togbit(PORTA_REG,PinNum);
			break;
		}
		case BPORT:
		{
			togbit(PORTB_REG,PinNum);
			break;
		}
		case CPORT:
		{
			togbit(PORTC_REG,PinNum);
			break;
		}
		case DPORT:
		{
			togbit(PORTD_REG,PinNum);
			break;
		}
		default: break;
	}
}
//-----------------------------------------------------------
void DIO_voidSetPinDir(u8 PortName , u8 PinNum , u8 PinDir)
{
    switch(PortName)
    {
    	case APORT:
    	{
    		if(PinDir == input)
    		{
				clrbit(DDRA_REG,PinNum);
    			//setbit(PORTA_REG,PinNum);
    		}
    		else if(PinDir == output)
    			setbit(DDRA_REG,PinNum);
    		break;
    	}
    	case BPORT:
    	{
    		if(PinDir == input)
    		{
    			clrbit(DDRB_REG,PinNum);
    			//setbit(PORTB_REG,PinNum);
    		}
    		else if(PinDir == output)
   	  			setbit(DDRB_REG,PinNum);
    		break;
   		}
    	case CPORT:
    	{
    		if(PinDir == input)
    		{
    			clrbit(DDRC_REG,PinNum);
    			//setbit(PORTC_REG,PinNum);
    		}
    		else if(PinDir == output)
    			setbit(DDRC_REG,PinNum);
   			break;
   		}
   		case DPORT:
    	{
    		if(PinDir == input)
    		{
    			clrbit(DDRD_REG,PinNum);
    			//setbit(PORTD_REG,PinNum);
    		}
    		else if(PinDir == output)
       			setbit(DDRD_REG,PinNum);
    		break;
    	}
    		default: break;
    }

}
//--------------------------------------------
u8 DIO_u8GetPortVal(u8 PortName)
{
    u8 PIN_REG_VAL=0;
	switch(PortName)
	{
		case APORT:
		{
			PIN_REG_VAL = PINA_REG;
			break;
		}
		case BPORT:
		{
			PIN_REG_VAL = PINB_REG;
			break;
		}
		case CPORT:
		{
			PIN_REG_VAL = PINC_REG;
			break;
		}
		case DPORT:
		{
			PIN_REG_VAL = PIND_REG;
				break;
		}
		default: break;

	}

return PIN_REG_VAL;
}
//------------------------------------------------
void DIO_voidSetPortVal(u8 PortName , u8 PortVal)
{
	switch(PortName)
	{
		case APORT:
		{
			PORTA_REG = PortVal;
			break;
		}
		case BPORT:
		{
			PORTB_REG = PortVal;
			break;
		}
		case CPORT:
		{
			PORTC_REG = PortVal;
			break;
		}
		case DPORT:
		{
			PORTD_REG = PortVal;
			break;
		}
		default: break;
	}

}
//------------------------------------------------
void DIO_viodSetPortDir(u8 PortName , u8 PortDir)
{
	switch(PortName)
	{
		case APORT:
		{
			if(PortDir == input)
			{
				DDRA_REG =0x00;
				//PORTA_REG =0xff ;   //ACTIVATE PULL UP
			}
			else
				DDRA_REG =0xff;
			break;
		}
		case BPORT:
		{
			if(PortDir == input)
			{
				DDRB_REG =0x00;
				//PORTB_REG =0xff ;   //ACTIVATE PULL UP
			}
			else
				DDRB_REG =0xff;
			break;
		}
		case CPORT:
		{
			if(PortDir == input)
			{
				DDRC_REG =0x00;
				//PORTC_REG =0xff;  //ACTIVATE PULL UP
			}
			else
				DDRC_REG =0xff;
			break;
		}
		case DPORT:
		{
			if(PortDir == input)
			{
				DDRD_REG =0x00;
				//PORTD_REG =0xff ; //ACTIVATE PULL UP
			}
			else
				DDRD_REG =0xff;
			break;
		}
		default: break;
	}

}
