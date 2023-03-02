/*
 * type.h
 *
 *  Created on: Dec 19, 2022
 *      Author: Nada
 */

#ifndef REG_H_
#define REG_H_

#include "type.h"
#include "bit.h"

//DDR address
#define DDRA_REG	 *((volatile u8*)0x3A)
#define DDRB_REG	 *((volatile u8*)0x37)
#define DDRC_REG	 *((volatile u8*)0x34)
#define DDRD_REG	 *((volatile u8*)0x31)
//PORT address		 
#define PORTA_REG	 *((volatile u8*)0x3B)
#define PORTB_REG	 *((volatile u8*)0x38)
#define PORTC_REG	 *((volatile u8*)0x35)
#define PORTD_REG	 *((volatile u8*)0x32)
//PIN address
#define PINA_REG	 *((volatile u8*)0x39)
#define PINB_REG	 *((volatile u8*)0x36)
#define PINC_REG	 *((volatile u8*)0x33)
#define PIND_REG	 *((volatile u8*)0x30)
//TIMER address
/*#define TCCR0_REG    *((volatile u8*)0x53)
#define TCNT0_REG    *((volatile u8*)0x52)
#define OCR0_REG     *((volatile u8*)0x5C)*/
#define TCCR1A_REG   *((volatile u8*)0x4F)
#define TCCR1B_REG   *((volatile u8*)0x4E)
	//#define TCNT1H_REG  *((volatile u8*)0x4D)
#define TCNT1L_REG   *((volatile u16*)0x4C)
	//#define OCR1AH_REG  *((volatile u8*)0x4B)
#define OCR1AL_REG   *((volatile u16*)0x4A)
	//#define OCR1BH_REG  *((volatile u8*)0x49)
#define OCR1BL_REG   *((volatile u16*)0x48)
	//#define ICR1H_REG   *((volatile u8*)0x47)
#define ICR1L_REG    *((volatile u16*)0x46)
#define TCCR2_REG    *((volatile u8*)0x45)
#define TCNT2_REG    *((volatile u8*)0x44)
#define OCR2_REG     *((volatile u8*)0x43)
/*#define TIMSK_REG    *((volatile u8*)0x59)
#define TIFR_REG     *((volatile u8*)0x58)*/
// Global INT Enable BIT
#define SREG_REG     *((volatile u8*)0x5F)
//ADC address
/*#define ADCL_REG	 *((volatile u16*)0x24)
#define ADCSRA_REG	 *((volatile u8*)0x26)
#define ADMUX_REG	 *((volatile u8*)0x27)*/
//Special Function IO
/*#define SFIOR_REG	 *((volatile u8 *)(0x50))*/
//WDT address
#define WDTCR_REG	 *((volatile u8 *)(0x41))
//INT address
/*#define MCUCR_REG	 *((volatile u8 *)(0x55))
#define MCUCSR_REG	 *((volatile u8 *)(0x54))
#define GICR_REG	 *((volatile u8 *)(0x5B))
#define GIFR_REG	 *((volatile u8 *)(0x5A))*/
//UART address		 
#define UDR_REG		 *((volatile u8 *)(0x2C))
#define UCSRA_REG	 *((volatile u8 *)(0x2B))
#define UCSRB_REG	 *((volatile u8 *)(0x2A))
#define UBRRL_REG	 *((volatile u8 *)(0x29))
#define UCSRC_REG	 *((volatile u8 *)(0x40))
#define UBRRH_REG	 *((volatile u8 *)(0x40))
//SPI address		 
#define SPCR_REG	 *((volatile u8 *)(0x2D))
#define SPSR_REG	 *((volatile u8 *)(0x2E))
#define SPDR_REG	 *((volatile u8 *)(0x2F))
#define SPI_DDR_REG  *((volatile u8 *)(0x37))
#define SPI_PORT_REG *((volatile u8 *)(0x38))
//EEPROM address
#define EEARL_REG	 *((volatile u16 *)(0x3E))
	//#define EEARL_REG	 *((volatile u8 *)(0x3E))
	//#define EEARH_REG	 *((volatile u8 *)(0x3F))
#define EEDR_REG	 *((volatile u8 *)(0x3D))
#define EECR_REG	 *((volatile u8 *)(0x3C))


#endif /* TYPE_H_ */
