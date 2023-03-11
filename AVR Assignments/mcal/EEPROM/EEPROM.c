/*
 * EEPROM.c
 *
 * Created: Jan 30, 2023
 *  Author: Nada
 */ 


#include "EEPROM.h"

void (*EEPROM_ptr) (void);

u8 EEPROM_ReadByteFromAddress(u16 Address)
{
	/* wait for completion of previous write */
	while (((EECR_REG & (1 << EEWE))>>EEWE)==1);
	/* Set up address register */
	EEARL_REG = Address;
	/* Start EEPROM read by writing EERE */
	EECR_REG |= (1 << EERE);
	/* Return data from data register */
	return EEDR_REG;
}

void EEPROM_ReadBlockFromAddress(u16 Address, u8* Target, u16 size)
{
	u16 count=0;
	/* wait for completion of previous write */
	while (((EECR_REG & (1 << EEWE))>>EEWE)==1);
	/* loop to get required data */
	while(count<size)
	{
		/* Set up address register */
		EEARL_REG = Address+count;
		/* Start EEPROM read by writing EERE */
		EECR_REG |= (1 << EERE);
		/* Return data from data register */
		*(Target+count)=EEDR_REG;
		/* move to next element */
		count++;
	}
}

void EEPROM_WriteByteToAddress(u16 Address ,u8 Data)
{
	/* wait for completion of previous write */
	while (((EECR_REG & (1 << EEWE))>>EEWE)==1);
	/* Set up address register and data */
	EEARL_REG = Address;
	EEDR_REG=Data;	
	/* Write logical one to EEMWE */
	EECR_REG |= (1 << EEMWE);
	/* Start EEPROM write by setting EEWE */
	EECR_REG |= (1 << EEWE);
		
}

void EEPROM_WriteBlockToAddress(u16 Address, u8* Source, u16 size)
{
	u16 count=0;
	while(count<size)
	{
		/* wait for completion of previous write */
		while (((EECR_REG & (1 << EEWE))>>EEWE)==1);
		/* Set up address register and data */
		EEARL_REG = Address;
		EEDR_REG = *(Source+count);
		/* Write logical one to EEMWE */
		EECR_REG |= (1 << EEMWE);
		/* Start EEPROM write by setting EEWE */
		EECR_REG |= (1 << EEWE);
	}	
}

void EEPROM_Enable_INT()
{
	setbit(EECR_REG,EERIE);
}
void EEPROM_Disable_INT()
{
	clrbit(EECR_REG,EERIE);	
}
void EEPROM_SetCallBack_(void (*ptr) (void))
{
	EEPROM_ptr=ptr;
}

void __vector_17(void) __attribute__(( signal , used ));
void __vector_17(void)
{
	EEPROM_ptr();
}
