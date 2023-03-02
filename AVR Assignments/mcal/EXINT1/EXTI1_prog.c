/*
 * EXTI1_prog.c
 *
 * Created: 2/24/2023 11:56:00 AM
 *  Author: Nada
 */ 

#include "type.h"
#include "bit.h"
//#include "Lbt_int.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI1_int.h"
#include "EXTI1_config.h"
#include "EXTI1_private.h"

/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/
//typedef void (*pf) (void);
volatile pf y; 

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT1_voidInit (void)
{
	
	/*  ( if / else if ) condition for Macros */
	#if EXT1_SENSE_MODE == IOC
	setbit(MCUCR , 2);
	clrbit(MCUCR , 3);
	
	#elif EXT1_SENSE_MODE == RISING
	setbit(MCUCR , 2);
	setbit(MCUCR , 3);
	
	#elif EXT1_SENSE_MODE == FALLING
	clrbit(MCUCR , 2);
	setbit(MCUCR , 3);
	
	#elif EXT1_SENSE_MODE == LOW_LEVEL
	clrbit(MCUCR , 2);
	clrbit(MCUCR , 3);
	
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT1 in initialization function  **/
/** like : void EXT1_voidDisable(); 		  */
	clrbit( GICR , 7 );
	setbit(GIFR , 7 ) ;
	
	
}


/****************************************************************/
/* Description    : This function used to Enable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidEnable()
{
	
	setbit( GICR , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Disable EXT0			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidDisable()
{
	
	clrbit( GICR , 7 );
	
}


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/ 
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT1_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		y = addresscpy;
	}
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/ 
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidSetSignalch(u8 SenseCpy)
{
	switch(SenseCpy)
	{
		case IOC:		
			setbit(MCUCR , 2);
			clrbit(MCUCR , 3);
			break;
		case FALLING:
			clrbit(MCUCR , 2);
			setbit(MCUCR , 3);
			break;
		case RISING:
			setbit(MCUCR , 2);
			setbit(MCUCR , 3);
			break;
		case LOW_LEVEL:
			clrbit(MCUCR , 2);
			clrbit(MCUCR , 3);
			break;
		default: break;
		
	}	
}

/****************************************************************/
/* Description    : This function used to Check if interrupt is */
/*					Executed or Not.							*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : flag Status [ LBTY_OK , LBTY_NOK ]	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
/*
flagStatus EXT0_enuIsExecuted( void )
{
	flagStatus ErrorStatus ;
	
	if( (GET_BIT(GIFR, 6)) == 1 )
	{
		
		ErrorStatus = LBTY_NOK ;
	}
	else if ( (GET_BIT(GIFR, 6)) == 0 )
	{
		
		ErrorStatus = LBTY_OK ;
	}
	
	return ErrorStatus ;
}
*/
/** Linker Problem solved */
void __vector_2(void) __attribute__(( signal , used ));


void __vector_2(void)
{
	y();
	
}