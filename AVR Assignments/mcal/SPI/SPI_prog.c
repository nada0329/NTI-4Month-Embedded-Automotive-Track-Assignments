/*
 * SPI_prog.c
 *
 * Created: 3/4/2023 1:21:35 PM
 *  Author: Nada
 */ 

#include "type.h"
#include "bit.h"
#include "SPI_priv.h"
#include "SPI_conf.h"
#include "SPI_int.h"

void (*SPI_ptr) (void);

void SPI_INT_Enable(void)
{
	setbit(SPCR_REG,SPIE);
}
void SPI_INT_Disable(void)
{
	clrbit(SPCR_REG,SPIE);
}
void SPI_Enable(void)
{
	setbit(SPCR_REG,SPE);
}
void SPI_Disable(void)
{
	clrbit(SPCR_REG,SPE);
}
void SPI_SetCallBack_(void (*ptr) (void))
{
	SPI_ptr=ptr;
}

void SPI_Init(SPI_MODE mode)
{
	/*select operation mode*/
	switch(mode)
	{
		case SPI_MSTR:
		/*port B mosi,ss,sck pins output*/
		SPI_DDR_REG|=(1<<SPI_MOSI) |(1<<SPI_SS)|(1<<SPI_SCK);
		SPI_DDR_REG&=~(1<<SPI_MISO);
		setbit(SPCR_REG, MSTR);
		setbit(SPI_PORT_REG,SPI_SS);
		break;
		case SPI_SLV:
		/*port B miso pin as output*/
		SPI_DDR_REG |=(1<<SPI_MISO);
		SPI_DDR_REG &= ~ ( (1<<SPI_MOSI) |(1<<SPI_SS)|(1<<SPI_SCK) );
		clrbit(SPCR_REG, MSTR);
		break;
		default:
		break;
	}
	
	#if	  SPI_CLK_PH==SPI_LEAD_SAMPLE
	clrbit(SPCR_REG,CPHA);
	#elif SPI_CLK_PH==SPI_LEAD_SETUP
	setbit(SPCR_REG,CPHA);
	#endif
	
	#if   SPI_CLK_POL==SPI_LEAD_RISE
	clrbit(SPCR_REG,CPOL);
	#elif SPI_CLK_POL==SPI_LEAD_FALL
	setbit(SPCR_REG,CPOL);
	#endif
	
	#if   SPI_DATA_ORDER==SPI_LSB
	setbit(SPCR_REG,DORD);
	#elif SPI_DATA_ORDER==SPI_MSB
	clrbit(SPCR_REG,DORD);
	#endif
	
	#if   SPI_SPEED==SPI_NRM
	#elif SPI_SPEED==SPI_DBL
	#endif
	
	#if   SPI_Prescalar==SPI_PRE4
	clrbit(SPSR_REG,SPI2X); clrbit(SPCR_REG,SPR1); clrbit(SPCR_REG,SPR0);
	#elif SPI_Prescalar==SPI_PRE16
	clrbit(SPSR_REG,SPI2X); clrbit(SPCR_REG,SPR1); setbit(SPCR_REG,SPR0);
	#elif SPI_Prescalar==SPI_PRE64
	clrbit(SPSR_REG,SPI2X); setbit(SPCR_REG,SPR1); clrbit(SPCR_REG,SPR0);
	#elif SPI_Prescalar==SPI_PRE128
	clrbit(SPSR_REG,SPI2X); setbit(SPCR_REG,SPR1); setbit(SPCR_REG,SPR0);
	#elif SPI_Prescalar==SPI_PRE2
	setbit(SPSR_REG,SPI2X); clrbit(SPCR_REG,SPR1); clrbit(SPCR_REG,SPR0);
	#elif SPI_Prescalar==SPI_PRE8
	setbit(SPSR_REG,SPI2X); clrbit(SPCR_REG,SPR1); setbit(SPCR_REG,SPR0);
	#elif SPI_Prescalar==SPI_PRE32
	setbit(SPSR_REG,SPI2X); setbit(SPCR_REG,SPR1); clrbit(SPCR_REG,SPR0);
	#elif SPI_Prescalar==SPI_PRE64
	setbit(SPSR_REG,SPI2X); setbit(SPCR_REG,SPR1); setbit(SPCR_REG,SPR0);
	#endif
	/*enable SPI*/
	setbit(SPCR_REG,SPE);
}

void SPI_Mstr_SendData(u8 Sdata)
{
	clrbit(SPI_PORT_REG,SPI_SS);
	u8 Rdata;
	SPDR_REG=Sdata;
	/*Wait till flag*/
	while(getbit(SPSR_REG,SPIF) == 0);
	Rdata=SPDR_REG;
}
u8 SPI_Mstr_RecData()
{
	clrbit(SPI_PORT_REG,SPI_SS);
	u8 Rdata;
	SPDR_REG=0xff;
	/*Wait till flag*/
	while(getbit(SPSR_REG,SPIF) == 0);
	// delay here 1m
	Rdata=SPDR_REG;
	return Rdata;
}
u8 SPI_Mstr_Send_RecData(u8 Sdata)
{
	clrbit(SPI_PORT_REG,SPI_SS);
	u8 Rdata;
	SPDR_REG=Sdata;
	/*Wait till flag*/
	while(getbit(SPSR_REG,SPIF) == 0);
	Rdata=SPDR_REG;
	return Rdata;
}

void SPI_Slv_SendData(u8 Sdata)
{
	/*Wait till flag*/
	while(getbit(SPSR_REG,SPIF) == 0);
	SPDR_REG=Sdata;
	//while(getbit(SPSR_REG,SPIF) == 0);
}
u8 SPI_Slv_RecData()
{
	u8 Rdata;
	/*Wait till flag*/
	while(getbit(SPSR_REG,SPIF) == 0);
	Rdata=SPDR_REG;
	return Rdata;
}

void __vector_12(void) __attribute__(( signal , used ));
void __vector_12(void)
{
	
	SPI_ptr();
}