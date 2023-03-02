/************************************************************/
/* 	Author 	 	 : Ahmed Atia Atia                          */
/* 	Date   		 : 2 May 2019	                            */
/* 	Version 	 : 1V 									    */
/* 	Description	 : prog.c for ADC		                    */
/************************************************************/


/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "type.h"
#include "bit.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h" 

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

volatile pf16 z; 
/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	/*set Ref volt*/
	#if VOLTAGE_REFERENCE==AREF
	clrbit(ADMUX,6);
	clrbit(ADMUX,7);
	#elif VOLTAGE_REFERENCE==AVCC
	setbit(ADMUX,6);
	clrbit(ADMUX,7);
	#elif VOLTAGE_REFERENCE==INTERNAL
	setbit(ADMUX,6);
	setbit(ADMUX,7);
	#endif
	
	/*adjust*/
	#if ADJUSTMENT==RIGHT_ADJUSTMENT
	clrbit(ADMUX,5);
	#elif ADJUSTMENT==LEFT_ADJUSTMENT
	setbit(ADMUX,5);
	#endif
	
	/*select channal*/
	ADMUX&=0xf8; // make sure first 3bits=0
	ADMUX|=ADC_CHANNEL_NUMBER;  // assign channal value

	/*set prescalar*/
	ADCSRA=0xf8; // make sure first 3bits=0
	#if	  ADC_PRESCALLER==DIVID_BY_2
	ADCSRA|=DIVID_BY_2;  // assign prescaler value
	#elif ADC_PRESCALLER==DIVID_BY_4
	ADCSRA|=DIVID_BY_4; 
	#elif ADC_PRESCALLER==DIVID_BY_8
	ADCSRA|=DIVID_BY_8; 
	#elif ADC_PRESCALLER==DIVID_BY_16
	ADCSRA|=DIVID_BY_16; 
	#elif ADC_PRESCALLER==DIVID_BY_32
	ADCSRA|=DIVID_BY_32; 
	#elif ADC_PRESCALLER==DIVID_BY_64
	ADCSRA|=DIVID_BY_64; 
	#elif ADC_PRESCALLER==DIVID_BY_128
	ADCSRA|=DIVID_BY_128; 
	#endif
	
	/* End ( if ) condition for Macros */	
	
	
}


/****************************************************************/
/* Description    : This function used to Enable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	setbit( ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/
u8 adclow()
{
	return ADCL;
}
u8 adchigh()
{
	return ADCH;
}

void ADC_voidInterrputEnable()
{

	
	setbit( ADCSRA , 3 );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	clrbit( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	setbit( ADCSRA , 6 );
	
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

void ADC_voidAutoTrigger()
{
	

	
/****************************************************************/	
/** !comment : From Data Sheet : Starting conversion on positive*/
/*			   edge when ADATE = 1						    	*/
/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

    setbit( ADCSRA , 5 );
	

		/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE 
	clrbit( SFIOR , 5 );
	clrbit( SFIOR , 6 );
	clrbit( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	setbit( SFIOR , 5 );
	clrbit( SFIOR , 6 );
	clrbit( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	clrbit( SFIOR , 5 );
	setbit( SFIOR , 6 );
	clrbit( SFIOR , 7 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	setbit( SFIOR , 5 );
	setbit( SFIOR , 6 );
	clrbit( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	clrbit( SFIOR , 5 );
	clrbit( SFIOR , 6 );
	setbit( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	setbit( SFIOR , 5 );
	clrbit( SFIOR , 6 );
	setbit( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	clrbit( SFIOR , 5 );
	setbit( SFIOR , 6 );
	setbit( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	setbit( SFIOR , 5 );
	setbit( SFIOR , 6 );
	setbit( SFIOR , 7 );	
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV()
{
	u16 mv_result,adc_read; u8  d;
	#if REQ_STATUS==POLLING	
	/*wait tell done*/
	while( getbit(ADCSRA,4)==0);
	/*clear flag*/
	setbit(ADCSRA,4);
	#elif REQ_STATUS==INTERUPT
	#endif	
	d=0;
	/*get the value*/
	#if ADJUSTMENT==LEFT_ADJUSTMENT
	adc_read=0;
	d=((ADCL&0xc0)>>6);
	adc_read= d |(ADCH<<2) ;
	#elif ADJUSTMENT==RIGHT_ADJUSTMENT
	adc_read=0;
	d=ADCL;
	adc_read=d | (ADCH&0x03)<<8;
	#endif

	
	return adc_read;
	
}

void ADC_ReadAllCh_Polling(u16* arr)
{
	u16 adc_read; 
	u8  d;
	for(u8 i=0;i<8;i++)
	{
		/*select channal*/
		ADMUX&=0xf8; // make sure first 3bits=0
		ADMUX|=i;  // assign channal value	
		/* start conv */
		setbit( ADCSRA , 6 );
		/*wait till flag*/
		while( getbit(ADCSRA,4)==0);
		/*clear flag*/
		setbit(ADCSRA,4);
		d=0;
		/*get the value*/
		#if ADJUSTMENT==LEFT_ADJUSTMENT
		adc_read=0;
		d=((ADCL&0xc0)>>6);
		adc_read= d |(ADCH<<2) ;
		#elif ADJUSTMENT==RIGHT_ADJUSTMENT
		adc_read=0;
		d=ADCL;
		adc_read=d | (ADCH&0x03)<<8;
		#endif
		arr[i]=adc_read;
		
	}
}

void ADC_ReadAllCh_INT(u16* arr)
{
	u16 adc_read;
	u8  d;
	static volatile u8 ch=0;
		/*select channal*/
		ADMUX&=0xf8; // make sure first 3bits=0
		ADMUX|=ch;  // assign channal value
		d=0;
		/*get the value*/
		#if ADJUSTMENT==LEFT_ADJUSTMENT
		adc_read=0;
		d=((ADCL&0xc0)>>6);
		adc_read= d |(ADCH<<2) ;
		#elif ADJUSTMENT==RIGHT_ADJUSTMENT
		adc_read=0;
		d=ADCL;
		adc_read=d | (ADCH&0x03)<<8;
		#endif
		arr[ch]=adc_read;
		ch++;
		if(ch==8)
			ch=0;
	
}

void ADC_voidCallBack(pf16 addresscpy)
{
	if(addresscpy != NULL)
	{
		z = addresscpy;
	}
}

void __vector_16(void)
{
	static u16 adc_val=0;
	//coment next line to read all channals in interrupt
		adc_val=ADC_u16ReadADCInMV();
	z(adc_val);
	
}
/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/