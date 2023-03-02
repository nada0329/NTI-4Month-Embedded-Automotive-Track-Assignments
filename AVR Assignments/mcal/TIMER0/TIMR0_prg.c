
#include "type.h"
#include "bit.h"
#include "TIMR0_int.h"
#include "TIMR00_priv.h"
#include "TIMR0_config.h"

void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;

void TIMER0_void_Init(void)
{
	#if(TIMER0_MODE == TIMER0_NORMAL)
		clrbit(TCCR0 , 6);
		clrbit(TCCR0 , 3);
	
	#elif(TIMER0_MODE == TIMER0_CTC)
		clrbit(TCCR0 , 6);
		setbit(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER0_FAST_PWM )
		setbit(TCCR0 , 6);
		setbit(TCCR0 , 3);
		
	#elif(TIMER0_MODE == TIMER0_PHASE_PWM )
		setbit(TCCR0 , 6);
		clrbit(TCCR0 , 3);
		
	#endif
	
	#if(TIMER0_PRESCALER == TIMER0_DIV_BY_1)
		setbit(TCCR0 , 0);
		clrbit(TCCR0 , 1);
		clrbit(TCCR0 , 2);
	
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_8)
		clrbit(TCCR0 , 0);
		setbit(TCCR0 , 1);
		clrbit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_64 )
		setbit(TCCR0 , 0);
		setbit(TCCR0 , 1);
		clrbit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_256 )
		clrbit(TCCR0 , 0);
		clrbit(TCCR0 , 1);
		setbit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_1024 )
		setbit(TCCR0 , 0);
		clrbit(TCCR0 , 1);
		setbit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_CNT_FALLING )
		clrbit(TCCR0 , 0);
		setbit(TCCR0 , 1);
		setbit(TCCR0 , 2);
	#elif(TIMER0_PRESCALER == TIMER0_CNT_RISING )
		setbit(TCCR0 , 0);
		setbit(TCCR0 , 1);
		setbit(TCCR0 , 2);	
		
	#endif
	
#if (TIMER0_MODE == TIMER0_CTC || TIMER0_MODE == TIMER0_NORMAL )	
	#if(TIMER0_COM_EVENT == TIMER0_NO_ACTION)
		clrbit(TCCR0 , 4);
		clrbit(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_TOGGLE)
		setbit(TCCR0 , 4)
		clrbit(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_CLEAR )
		clrbit(TCCR0 , 4);
		setbit(TCCR0 , 5);
	#elif(TIMER0_COM_EVENT == TIMER0_SET )
		setbit(TCCR0 , 4);
		setbit(TCCR0 , 5);

		
	#endif
	
	#else
		#if TMR0_PWM_STATUS==TIMER0_PWM_NONINV
		clrbit(TCCR0,4);
		setbit(TCCR0,5);
		#elif TMR0_PWM_STATUS==TIMER0_PWM_INV
		setbit(TCCR0,4);
		setbit(TCCR0,5);
		
		#endif
#endif	
	/*Disable Interrupts*/
	clrbit(TIMSK , 0);	
	clrbit(TIMSK , 1);
	/*CLEAR FLAGS*/
	setbit(TIFR , 0);	
	setbit(TIFR , 1);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
	
	
}

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT0 = Copy_uint8Val ;
}

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = Copy_uint8Val ;
}

void TIMER0_void_EnableOVInt(void)
{
	setbit(TIMSK , 0);
}

void TIMER0_void_DisableOVInt(void)
{
	clrbit(TIMSK , 0);
}

void TIMER0_void_EnableCTCInt(void)
{
	setbit(TIMSK , 1);
}

void TIMER0_void_DisableCTCInt(void)
{
	clrbit(TIMSK , 1);
}

u8 TIMER0_u8_CounterValue()
{
	return TCNT0;
}

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{

		TIMER0_OV_CallBack();
	

}

void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	
	TIMER0_CTC_CallBack();
}


void Timer0_PWMPhase_dutyCyc(u8 ratio)
{
	// get ratio as number of %100
	// F(timer)= F(clk) / prescalar
	// F(pwm)= F(timer) / 510
	// @non-inverting:  duty= 2*(OCR) / 2*(2^8-1)
	// @inverting:		duty= 1 - [2*(OCR) / 2*(2^8-1)]
	#if TMR0_PWM_STATUS==TIMER0_PWM_NONINV
	OCR0=(u8)((ratio*255)/100);
	#elif TMR0_PWM_STATUS==TIMER0_PWM_INV
	OCR0=255-(u8)((ratio*255)/100);
	#endif
}

void Timer0_PWMfast_dutyCyc(u8 ratio)
{
	// get ratio as number of %100
	// F(timer)= F(clk) / prescalar
	// F(pwm)= F(timer) / 2^8
	// @non-inverting:  duty= (OCR+1) / 2^8
	// @inverting:		duty= 1 - [(OCR+1) / 2^8]
	#if TMR0_PWM_STATUS==TIMER0_PWM_NONINV
	OCR0=(u8)((ratio*256)/100)-1;
	#elif TMR0_PWM_STATUS==TIMER0_PWM_INV
	OCR0=(256-(u8)((ratio*256)/100))-1;
	#endif	
}