/*
 * EXTI2_int.h
 *
 * Created: 3/2/2023 7:25:01 PM
 *  Author: Nada
 */ 


#ifndef EXTI2_INT_H_
#define EXTI2_INT_H_

#define FALLING		4
#define RISING		7


typedef void (*pf) (void);


/****************************************************************/
/* Description    :  This function used to initialize EXT2      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT2_voidInit ( void );


/****************************************************************/
/* Description    : This function used to Enable EXT2			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT2_voidEnable( void );


/****************************************************************/
/* Description    : This function used to Disable EXT2  		*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT2_voidDisable( void );


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
void EXT2_voidCallBack(pf addresscpy);


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
void EXT2_voidSetSignalch(u8 SenseCpy);



#endif /* EXTI2_INT_H_ */