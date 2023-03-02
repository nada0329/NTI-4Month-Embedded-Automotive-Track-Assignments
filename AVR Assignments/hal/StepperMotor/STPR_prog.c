/*
 * STPR_prog.c
 *
 * Created: 3/1/2023 10:54:32 PM
 *  Author: Nada
 */ 
#include "type.h"
#include "DIO.h"
#include "STPR_int.h"
#include "STPR_conf.h"
#include "STPR_priv.h"
#define F_CPU 8000000UL		/* Define CPU Frequency 8MHz */
#include <util/delay.h>


void StprMotor_voidInit( void )
{
	
	/*****************************************************************/
	/* !comment : Loop to initialize all Stepper Motors				 	 */
	/*****************************************************************/
	
	for( u8 i = 0 ; i < NUMBER_OF_STPRMOTORS ; i++ )
	{
		DIO_voidSetPinDir(ArrayOfStprMotor[i].Stpr_Port_A ,ArrayOfStprMotor[i].Stpr_Pin_A ,output );
		DIO_voidSetPinDir(ArrayOfStprMotor[i].Stpr_Port_B ,ArrayOfStprMotor[i].Stpr_Pin_B ,output );
		DIO_voidSetPinDir(ArrayOfStprMotor[i].Stpr_Port_C ,ArrayOfStprMotor[i].Stpr_Pin_C ,output );
		DIO_voidSetPinDir(ArrayOfStprMotor[i].Stpr_Port_D ,ArrayOfStprMotor[i].Stpr_Pin_D ,output );
	}
	for( u8 i = 0 ; i < NUMBER_OF_STPRMOTORS ; i++ )
	{
		DIO_voidSetPinVal(ArrayOfStprMotor[i].Stpr_Port_A ,ArrayOfStprMotor[i].Stpr_Pin_A ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[i].Stpr_Port_B ,ArrayOfStprMotor[i].Stpr_Pin_B ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[i].Stpr_Port_C ,ArrayOfStprMotor[i].Stpr_Pin_C ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[i].Stpr_Port_D ,ArrayOfStprMotor[i].Stpr_Pin_D ,low );
	}
}

void StprMotor_voidRotateAntiClkwiseFullstep( u8 motor)
{
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );

	_delay_ms(SPEED_OF_STPMOTORS);

	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );

	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );

	_delay_ms(SPEED_OF_STPMOTORS);


}

void StprMotor_voidRotateClkwiseFullstep( u8 motor)
{
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );
		
		_delay_ms(SPEED_OF_STPMOTORS);
		
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );
		
		_delay_ms(SPEED_OF_STPMOTORS);
		
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
		
		_delay_ms(SPEED_OF_STPMOTORS);
		
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
		DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
		
		_delay_ms(SPEED_OF_STPMOTORS);
		
}

void StprMotor_voidRotateClkwiseHalfstep( u8 motor)
{
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );

	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );

	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );

	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
}

void StprMotor_voidRotateAntiClkwiseHalfstep( u8 motor)
{
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );

	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
	
	_delay_ms(SPEED_OF_STPMOTORS);

	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );

	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
	
	_delay_ms(SPEED_OF_STPMOTORS);
	
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,high );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );

	_delay_ms(SPEED_OF_STPMOTORS);
	
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,high );
	
	_delay_ms(SPEED_OF_STPMOTORS);	
}


void StprMotor_voidStop( u8 motor)
{
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_A ,ArrayOfStprMotor[motor].Stpr_Pin_A ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_B ,ArrayOfStprMotor[motor].Stpr_Pin_B ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_C ,ArrayOfStprMotor[motor].Stpr_Pin_C ,low );
	DIO_voidSetPinVal(ArrayOfStprMotor[motor].Stpr_Port_D ,ArrayOfStprMotor[motor].Stpr_Pin_D ,low );
									   
}