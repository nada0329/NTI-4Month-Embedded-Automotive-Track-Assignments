/*
 * STPR_conf.c
 *
 * Created: 3/1/2023 10:54:55 PM
 *  Author: Nada
 */ 
#include "type.h"
#include "DIO.h"
#include "STPR_int.h"
#include "STPR_conf.h"
#include "STPR_priv.h"


/*****************************************************************/
/* !comment : Array of struct ( StepperMotor ) from config.c	 	 */
/*****************************************************************/

StepperMotor ArrayOfStprMotor [ NUMBER_OF_STPRMOTORS ] =
{
	{ APORT , Pin0 , APORT , Pin1 , APORT , Pin2 , APORT , Pin3 }  
	
};