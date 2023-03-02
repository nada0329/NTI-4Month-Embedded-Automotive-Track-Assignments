/*
 * TIMR1_int.h
 *
 * Created: 3/2/2023 2:40:14 PM
 *  Author: Nada
 */ 


#ifndef TIMR1_INT_H_
#define TIMR1_INT_H_



void Timer1_Init(void);
void Timer1_OVFInt_Enable(void);
void Timer1_OVFInt_Disable(void);
void Timer1_OCMAInt_Enable(void);
void Timer1_OCMAInt_Disable(void);
void Timer1_OCMBInt_Enable(void);
void Timer1_OCMBInt_Disable(void);
void Timer1_ICUInt_Enable(void);
void Timer1_ICUInt_Disable(void);
void Timer1_SetCallBack_OVF(void (*ptr) (void));
void Timer1_SetCallBack_OCMA(void (*ptr) (void));
void Timer1_SetCallBack_OCMB(void (*ptr) (void));
void Timer1_SetCallBack_ICU(void (*ptr) (void));
void Timer1_SetTimingLimits_ovf(u16 initial_val);
void Timer1_SetTimingLimits_cmpA(u16 comp1);
void Timer1_SetTimingLimits_cmpB(u16 comp2);
void Timer1_SetTimingLimits_cmp_base_period(u16 compA,u16 compB,u16 base);

/*mode14*/
void Timer1_PWMfastA_dutyCyc_freq(f32 ratio,u16 freqinKHz);
void Timer1_PWMfastB_dutyCyc_freq(f32 ratio,u16 freqinKHz );
/*mode15*/
void Timer1_PWMfast_dutyCyc_freq(f32 ratio,u16 freqinKHz );
/*mode10*/
void Timer1_PWMphaseB_dutyCyc_freq(f32 ratio,u16 freqinHz );
void Timer1_PWMphaseA_dutyCyc_freq(f32 ratio,u16 freqinHz );
/*mode11*/
void Timer1_PWMphase_dutyCyc_freq(f32 ratio,u16 freqinHz );

#endif /* TIMR1_INT_H_ */