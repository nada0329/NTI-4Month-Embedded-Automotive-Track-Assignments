/*
 * TIMR1_prog.c
 *
 * Created: 3/2/2023 1:58:57 PM
 *  Author: Nada
 */ 

#include "type.h"
#include "bit.h"
#include "TIMR1_int.h"
#include "TIMR1_priv.h"
#include "TIMR1_config.h"

void (*TMR1_ptr_OVF) (void);
void (*TMR1_ptr_OCMA) (void);
void (*TMR1_ptr_OCMB) (void);
void (*TMR1_ptr_ICU) (void);

void Timer1_Init(void)
{
	#if Timer1MODE==TMR1_NOREMAL_MODE
		clrbit(TCCR1A,WGM10);
		clrbit(TCCR1A,WGM11);
		clrbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_PHASECORRECT8bit_MODE
		setbit(TCCR1A,WGM10);
		clrbit(TCCR1A,WGM11);
		clrbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_PHASECORRECT9bit_MODE
		clrbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		clrbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_PHASECORRECT10bit_MODE
		setbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		clrbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_CTCOCR_MODE
		clrbit(TCCR1A,WGM10);
		clrbit(TCCR1A,WGM11);
		setbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_FASTPWM8bit_MODE
		setbit(TCCR1A,WGM10);
		clrbit(TCCR1A,WGM11);
		setbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_FASTPWM9bit_MODE
		clrbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		setbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_FASTPWM10bit_MODE
		setbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		setbit(TCCR1B,WGM12);
		clrbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_PHASEFREQ_ICR_MODE
		clrbit(TCCR1A,WGM10);
		clrbit(TCCR1A,WGM11);
		clrbit(TCCR1B,WGM12);
		setbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_PHASEFREQ_OCR_MODE
		setbit(TCCR1A_REG,WGM10);
		clrbit(TCCR1A_REG,WGM11);
		clrbit(TCCR1B_REG,WGM12);
		setbit(TCCR1B_REG,WGM13);
	#elif Timer1MODE==TMR1_PHASECORRECT_ICR_MODE
		clrbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		clrbit(TCCR1B,WGM12);
		setbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_PHASECORRECT_OCR_MODE
		setbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		clrbit(TCCR1B,WGM12);
		setbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_CTCICR_MODE
		clrbit(TCCR1A,WGM10);
		clrbit(TCCR1A,WGM11);
		setbit(TCCR1B,WGM12);
		setbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_FASTPWM_ICR_MODE
		clrbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		setbit(TCCR1B,WGM12);
		setbit(TCCR1B,WGM13);
	#elif Timer1MODE==TMR1_FASTPWM_OCR_MODE
		setbit(TCCR1A,WGM10);
		setbit(TCCR1A,WGM11);
		setbit(TCCR1B,WGM12);
		setbit(TCCR1B,WGM13);
	#endif
	
	#if Timer1PWM_status_CHB==TMR1_disconnect
	clrbit(TCCR1A, COM1B0);
	clrbit(TCCR1A, COM1B1);
	#elif Timer1PWM_status_CHB==TMR1_toggle
	setbit(TCCR1A, COM1B0);
	clrbit(TCCR1A, COM1B1);
	#elif Timer1PWM_status_CHB==TMR1_nonInv
	clrbit(TCCR1A, COM1B0);
	setbit(TCCR1A, COM1B1);
	#elif Timer1PWM_status_CHB==TMR1_Inv
	setbit(TCCR1A, COM1B0);
	setbit(TCCR1A, COM1B1);
	#endif
	
	#if Timer1PWM_status_CHA==TMR1_disconnect
	clrbit(TCCR1A, COM1A0);
	clrbit(TCCR1A, COM1A1);
	#elif Timer1PWM_status_CHA==TMR1_toggle
	setbit(TCCR1A, COM1A0);
	clrbit(TCCR1A, COM1A1);
	#elif Timer1PWM_status_CHA==TMR1_nonInv
	clrbit(TCCR1A, COM1A0);
	setbit(TCCR1A, COM1A1);
	#elif Timer1PWM_status_CHA==TMR1_Inv
	setbit(TCCR1A, COM1A0);
	setbit(TCCR1A, COM1A1);
	#endif
	
	// set prescalar
	TCCR1B&=0xf8; // make sure first 3bits=0
	TCCR1B|=Timer1Prescaler;  // assign prescaler value	
}

void Timer1_OVFInt_Enable()
{
	setbit(TIMSK,TOIE1);
}
void Timer1_OVFInt_Disable()
{
	clrbit(TIMSK,TOIE1);
}
void Timer1_OCMAInt_Enable()
{
	setbit(TIMSK,OCIE1A);
}
void Timer1_OCMAInt_Disable()
{
	clrbit(TIMSK,OCIE1A);
}
void Timer1_OCMBInt_Enable()
{
	setbit(TIMSK,OCIE1B);
}
void Timer1_OCMBInt_Disable()
{
	clrbit(TIMSK,OCIE1B);
}
void Timer1_ICUInt_Enable()
{
	setbit(TIMSK,TICIE1);
}
void Timer1_ICUInt_Disable()
{
	clrbit(TIMSK,TICIE1);
}

void Timer1_SetCallBack_OVF(void (*ptr) (void))
{
	TMR1_ptr_OVF=ptr;
}
void Timer1_SetCallBack_OCMA(void (*ptr) (void))
{
	TMR1_ptr_OCMA=ptr;
}
void Timer1_SetCallBack_OCMB(void (*ptr) (void))
{
	TMR1_ptr_OCMB=ptr;
}
void Timer1_SetCallBack_ICU(void (*ptr) (void))
{
	TMR1_ptr_ICU=ptr;
}


void Timer1_SetTimingLimits_ovf(u16 initial_val)
{	
		TCNT1L=initial_val;
}
void Timer1_SetTimingLimits_cmpA(u16 comp1)
{	
	OCR1AL=comp1;
}
void Timer1_SetTimingLimits_cmpB(u16 comp2)
{
	OCR1BL=comp2;
}
void Timer1_SetTimingLimits_cmp_base_period(u16 compA,u16 compB,u16 base)
{
	OCR1AL=compA;
	OCR1BL=compB;
	ICR1L=base;
}


/* 
	func used in mode14 TMR1_FASTPWM_ICR_MODE
	get req ratio and fixed freq on channal A
	based on using ICR reg
*/
void Timer1_PWMfastA_dutyCyc_freq(f32 ratio,u16 freqinKHz)
{
	// use prescalar 1
	// F(timer)= F(clk) / prescalar
	// F(cycle)= F(timer) / ICR
	// get ratio as number of 100
	// @non-inverting:  ratio= (OCR+1) / ICR
	// @inverting:		ratio= 1 - [(OCR+1) / ICR]
	u16 icr=(u16)(8000/freqinKHz);
	ICR1L=icr;
	u16 ocr;
	
	#if	Timer1PWM_status_CHA==TMR1_nonInv
		ocr=(u16)((ratio*icr)/100)-1;
	#elif	Timer1PWM_status_CHA==TMR1_Inv
		ocr=(icr-(u16)((ratio*icr)/100))-1;
	#endif	
	OCR1AL=ocr;
}

/* 
	func used in mode14 TMR1_FASTPWM_ICR_MODE
	get req ratio and fixed freq on channal B
	based on using ICR reg
*/
void Timer1_PWMfastB_dutyCyc_freq(f32 ratio,u16 freqinKHz )
{
	// using prescalar 1
	// F(timer)= F(clk) / prescalar
	// F(cycle)= F(timer) / ICR
	// get ratio as number of 100
	// @non-inverting:  ratio= (OCR+1) / ICR
	// @inverting:		ratio= 1 - [(OCR+1) / ICR]
	u16 icr=(u16)(8000/freqinKHz);
	ICR1L=icr;
	u16 ocr;
	#if	Timer1PWM_status_CHB==TMR1_nonInv
		ocr=(u16)((ratio*icr)/100)-1;
	#elif	Timer1PWM_status_CHB==TMR1_Inv
		ocr=(icr-(u16)((ratio*icr)/100))-1;
	#endif
	OCR1BL=ocr;

}


/* 
	func used in mode15 TMR1_FASTPWM_OCR_MODE 
	get req ratio and freq based on OCR value 
	based on OCRA so only channal B generate wave
*/
void Timer1_PWMfast_dutyCyc_freq(f32 ratio,u16 freqinKHz )
{
	// using prescalar 1
	// F(timer)= F(clk) / prescalar
	// F(cycle)= F(timer) / OCRA
	// get ratio as number of 100
	// @non-inverting:  ratio= (OCRB+1) / OCRA
	// @inverting:		ratio= 1 - [(OCRB+1) / OCRA]
	
	OCR1AL=(u16)(8000/freqinKHz);
	
	#if	Timer1PWM_status_CHB==TMR1_nonInv
		OCR1BL=(u16)((ratio* OCR1AL )/100)-1;
	#elif	Timer1PWM_status_CHB==TMR1_Inv
		OCR1BL=(OCR1AL_REG-(u16)((ratio*OCR1AL)/100))-1;
	#endif
}



/**************************************************************************************************/
/* 
	func used in mode10 TMR1_PHASECORRECT_ICR_MODE
	get req ratio and freq on channal A
	based on using ICR reg
*/
void Timer1_PWMphaseA_dutyCyc_freq(f32 ratio,u16 freqinHz )
{
	// using prescalar 64
	// F(timer)= F(clk) / prescalar
	// F(cycle)= F(timer) / (2ICR-2)
	// get ratio as number of 100
	// @non-inverting:  ratio= (2*OCR) / 2(ICR-1)
	// @inverting:		ratio= 1 - [(2*OCR) / 2(ICR-1)]
	u16 icr=(u16)(62500/freqinHz);
	ICR1L=icr;
	u16 ocr;
	#if	Timer1PWM_status_CHA==TMR1_nonInv
		ocr=(u16)((ratio*(icr-1))/100);
	#elif	Timer1PWM_status_CHA==TMR1_Inv
		ocr=((icr-1)-(u16)((ratio*(icr-1))/100));
	#endif
	OCR1AL=ocr;

}
/* 
	func used in mode10 TMR1_PHASECORRECT_ICR_MODE
	get req ratio and freq on channal B
	based on using ICR reg
*/
void Timer1_PWMphaseB_dutyCyc_freq(f32 ratio,u16 freqinHz )
{
	// using prescalar 64
	// F(timer)= F(clk) / prescalar
	// F(cycle)= F(timer) / (2ICR-2)
	// get ratio as number of 100
	// @non-inverting:  ratio= (2*OCR) / 2(ICR-1)
	// @inverting:		ratio= 1 - [(2*OCR) / 2(ICR-1)]
	u16 icr=(u16)(62500/freqinHz);
	ICR1L=icr;
	u16 ocr;
	#if	Timer1PWM_status_CHB==TMR1_nonInv
		ocr=(u16)((ratio*(icr-1))/100);
	#elif	Timer1PWM_status_CHB==TMR1_Inv:
		ocr=((icr-1)-(u16)((ratio*(icr-1))/100));
	#endif
	OCR1BL=ocr;

}


/* 
	func used in mode11 TMR1_PHASECORRECT_OCR_MODE
	get req ratio and freq on channal B
	based on using OCRA reg
*/
void Timer1_PWMphase_dutyCyc_freq(f32 ratio,u16 freqinHz )
{
	// using prescalar 64
	// F(timer)= F(clk) / prescalar
	// F(cycle)= F(timer) / (2OCRA-2)
	// get ratio as number of 100
	// @non-inverting:  ratio= (2*OCRB) / 2(OCRA-1)
	// @inverting:		ratio= 1 - [(2*OCRB) / 2(OCRA-1)]
	OCR1AL=(u16)(62500.0/freqinHz);
	
	#if	Timer1PWM_status_CHB==TMR1_nonInv
		OCR1BL=(u16)((ratio*(OCR1AL-1))/100);
	#elif	Timer1PWM_status_CHB==TMR1_Inv
		OCR1BL=((OCR1AL-1)-(u16)((ratio*(OCR1AL-1))/100));
	#endif
}


void __vector_9(void) __attribute__((signal , used));
void __vector_9(void)
{
	TMR1_ptr_OVF();
}

void __vector_7(void) __attribute__((signal , used));
void __vector_7(void)
{
	TMR1_ptr_OCMA();
}

void __vector_8(void) __attribute__((signal , used));
void __vector_8(void)
{
	TMR1_ptr_OCMB();
}

void __vector_6(void) __attribute__((signal , used));
void __vector_6(void)
{
	TMR1_ptr_ICU();
}