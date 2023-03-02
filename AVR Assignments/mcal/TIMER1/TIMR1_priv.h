/*
 * TIMR1_priv.h
 *
 * Created: 3/2/2023 12:11:05 PM
 *  Author: Nada
 */ 


#ifndef TIMR1_PRIV_H_
#define TIMR1_PRIV_H_

#define TIMSK	 (*(volatile u8 * )0x59)
#define TIFR	 (*(volatile u8 * )0x58)
#define TCCR1A   *((volatile u8 * )0x4F)
#define TCCR1B   *((volatile u8 * )0x4E)
#define TCNT1L   *((volatile u16* )0x4C)
#define OCR1AL   *((volatile u16* )0x4A)
#define OCR1BL   *((volatile u16* )0x48)
#define ICR1L    *((volatile u16* )0x46)


// TCCR1_REG
#define COM1A1	7
#define COM1A0	6
#define COM1B1	5
#define COM1B0	4
#define FOC1A	3
#define FOC1B	2
#define WGM11	1
#define WGM10	0

#define ICNC1	7
#define ICES1	6
#define WGM13	4
#define WGM12	3
#define CS12	2
#define CS11	1
#define CS10	0
// TIMSK_REG
#define TOIE0	0
#define OCIE0	1
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5
#define TOIE2	6
#define OCIE2	7


#define TMR1_NOREMAL_MODE			0
#define TMR1_PHASECORRECT8bit_MODE	1
#define TMR1_PHASECORRECT9bit_MODE	2
#define TMR1_PHASECORRECT10bit_MODE	3
#define TMR1_CTCOCR_MODE			4
#define TMR1_FASTPWM8bit_MODE		5
#define TMR1_FASTPWM9bit_MODE		6
#define TMR1_FASTPWM10bit_MODE		7
#define TMR1_PHASEFREQ_ICR_MODE		8
#define TMR1_PHASEFREQ_OCR_MODE		9
#define TMR1_PHASECORRECT_ICR_MODE	10
#define TMR1_PHASECORRECT_OCR_MODE	11
#define TMR1_CTCICR_MODE			12
#define TMR1_FASTPWM_ICR_MODE		14
#define TMR1_FASTPWM_OCR_MODE		15


#define TMR1_STOP		0
#define TMR1_PRE_1		1
#define TMR1_PRE_8		2
#define TMR1_PRE_64		3
#define TMR1_PRE_256	4
#define TMR1_PRE_1024	5
#define TMR1_EXT_FALL	6
#define TMR1_EXT_RISE	7


#define TMR1_disconnect		0
#define TMR1_toggle			1
#define TMR1_nonInv			2
#define TMR1_Inv			3


#define TMR1_Rising		0
#define TMR1_falling	1


#endif /* TIMR1_PRIV_H_ */