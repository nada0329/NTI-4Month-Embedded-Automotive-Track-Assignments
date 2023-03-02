/*
 * STPR_priv.h
 *
 * Created: 3/1/2023 10:55:57 PM
 *  Author: Nada
 */ 


#ifndef STPR_PRIV_H_
#define STPR_PRIV_H_

typedef struct steppermotor
{
	u8 Stpr_Port_A;
	u8 Stpr_Pin_A;
	
	u8 Stpr_Port_B;
	u8 Stpr_Pin_B;
	
	u8 Stpr_Port_C;
	u8 Stpr_Pin_C;
	
	u8 Stpr_Port_D;
	u8 Stpr_Pin_D;
	
}StepperMotor;

/*****************************************************************/
/* !comment : Array of struct ( Stepper Motor ) from config.c	 */
/*****************************************************************/

extern StepperMotor ArrayOfStprMotor [ NUMBER_OF_STPRMOTORS ] ;



#endif /* STPR_PRIV_H_ */