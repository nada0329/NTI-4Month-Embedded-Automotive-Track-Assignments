/*
 * LED.c
 *
 *  Created on: Dec 10, 2022
 *      Author: Nada
 */


#include "LED.h"

void LED_init(u8 PortName , u8 PinNum)
{
	DIO_voidSetPinDir(PortName,PinNum,output);
}
void LED_ON(u8 PortName , u8 PinNum)
{
	DIO_voidSetPinVal(PortName,PinNum,high);
}
void LED_OFF(u8 PortName , u8 PinNum)
{
	DIO_voidSetPinVal(PortName,PinNum,low);
}

void LED_TOG(u8 PortName , u8 PinNum)
{
	DIO_voidTogPinVal(PortName,PinNum);
}