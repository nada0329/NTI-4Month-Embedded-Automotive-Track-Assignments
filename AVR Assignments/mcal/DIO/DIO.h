/*
 * DIO.h
 *
 *  Created on: Dec 10, 2022
 *      Author: Nada
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#include "Registers.h"

//PortName//
#define APORT 0
#define BPORT 1
#define CPORT 2
#define DPORT 3
//PortDir//
#define input 0
#define output 1
//PinVal//
#define high 1
#define low 0
//PinNum
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7
/////////////////
void DIO_viodSetPortDir(u8 PortName , u8 PortDir); //decide is port in or out
void DIO_voidSetPortVal(u8 PortName , u8 PortVal); //put certain value on a port
u8 DIO_u8GetPortVal(u8 PortName); //get the value stored in a port

void DIO_voidSetPinDir(u8 PortName , u8 PinNum , u8 PinDir);
void DIO_voidSetPinVal(u8 PortName , u8 PinNum , u8 PinVal);
u8 DIO_u8GetPinVal(u8 PortName , u8 PinNum);
void DIO_voidTogPinVal(u8 PortName , u8 PinNum);

#endif /* MCAL_DIO_H_ */
