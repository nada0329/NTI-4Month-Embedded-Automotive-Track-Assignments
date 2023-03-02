/*
 * EXTI2_prog.c
 *
 * Created: 3/2/2023 7:22:51 PM
 *  Author: Nada
 */ 

#include "type.h"
#include "bit.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "EXTI2_int.h"
#include "EXTI2_Config.h"
#include "EXTI2_private.h" 


/***********************************************************/
/**!comment   :  pointer to function for callback	       */
/***********************************************************/
//typedef void (*pf) (void);
volatile pf x2; 

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/


/****************************************************************/
/* Description    :  This function used to initialize EXT2      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/



void EXT2_voidInit (void)
{	
	#if EXT2_SENSE_MODE == RISING
	setbit(MCUCSR,6);
	
	#elif EXT2_SENSE_MODE == FALLING
	clrbit(MCUCSR,6);
	#endif
	/* End ( if ) condition for Macros */

	
/** disable EXT2 in initialization function  **/
/** like : void EXT2_voidDisable(); 		  */
	clrbit( GICR , 5 );
	setbit(GIFR , 5 ) ;
	
	
}


/****************************************************************/
/* Description    : This function used to Enable EXT2			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidEnable()
{
	
	setbit( GICR , 5 );
	
}


/****************************************************************/
/* Description    : This function used to Disable EXT2			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void EXT2_voidDisable()
{
	
	clrbit( GICR , 5 );
	
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

void EXT2_voidCallBack(pf addresscpy)
{
	if(addresscpy != NULL)
	{
		x2 = addresscpy;
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
void EXT2_voidSetSignalch(u8 SenseCpy)
{
	switch(SenseCpy)
	{
		case FALLING:
			clrbit(MCUCSR,6);
			break;
		case RISING:
			setbit(MCUCSR,6);
			break;
		default: break;
		
	}	
}


/** Linker Problem solved */
void __vector_3(void) __attribute__(( signal , used ));


void __vector_3(void)
{
	x2();
	
}
