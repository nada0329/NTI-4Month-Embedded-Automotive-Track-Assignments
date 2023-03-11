/*
 * EEPROM.h
 *
 * Created: Jan 30, 2023
 *  Author: Nada
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "type.h"
#include "bit.h"
#include "Registers.h"

//EECR_REG
#define EERIE	3
#define EEMWE	2
#define EEWE	1
#define EERE	0

u8 EEPROM_ReadByteFromAddress(u16 Address);
void EEPROM_ReadBlockFromAddress(u16 Address, u8* Target, u16 size);
void EEPROM_WriteByteToAddress(u16 Address ,u8 Data);
void EEPROM_WriteBlockToAddress(u16 Address, u8* Source, u16 size);
void EEPROM_Enable_INT();
void EEPROM_Disable_INT();
void EEPROM_SetCallBack_(void (*ptr) (void));

#endif /* EEPROM_H_ */