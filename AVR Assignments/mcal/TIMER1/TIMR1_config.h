/*
 * TIMR1_config.h
 *
 * Created: 3/2/2023 12:08:07 PM
 *  Author: Nada
 */ 


#ifndef TIMR1_CONFIG_H_
#define TIMR1_CONFIG_H_

/*
TMR1_NOREMAL_MODE
TMR1_PHASECORRECT8bit_MODE
TMR1_PHASECORRECT9bit_MODE
TMR1_PHASECORRECT10bit_MODE
TMR1_CTCOCR_MODE
TMR1_FASTPWM8bit_MODE
TMR1_FASTPWM9bit_MODE
TMR1_FASTPWM10bit_MODE
TMR1_PHASEFREQ_ICR_MODE
TMR1_PHASEFREQ_OCR_MODE
TMR1_PHASECORRECT_ICR_MODE
TMR1_PHASECORRECT_OCR_MODE
TMR1_CTCICR_MODE
TMR1_FASTPWM_ICR_MODE
TMR1_FASTPWM_OCR_MODE
*/
#define Timer1MODE		TMR1_FASTPWM_OCR_MODE

/*
TMR1_STOP
TMR1_PRE_1
TMR1_PRE_8
TMR1_PRE_64
TMR1_PRE_256
TMR1_PRE_1024
TMR1_EXT_FALL
TMR1_EXT_RISE
*/
#define Timer1Prescaler		TMR1_PRE_1

/*
TMR1_disconnect
TMR1_toggle
TMR1_nonInv
TMR1_Inv
*/
#define Timer1PWM_status_CHB	TMR1_nonInv
#define Timer1PWM_status_CHA	TMR1_Inv

/*
TMR1_Rising
TMR1_falling
*/
#define Timer1ICU_trigger	TMR1_Rising




#endif /* TIMR1_CONFIG_H_ */