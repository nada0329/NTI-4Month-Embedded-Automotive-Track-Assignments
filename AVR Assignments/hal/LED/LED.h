/*
 * LED.h
 *
 *  Created on: Dec 10, 2022
 *      Author: Nada
 */

#ifndef LED_H_
#define LED_H_

#include "DIO.h"

void LED_init(u8 PortName , u8 PinNum);
void LED_ON(u8 PortName , u8 PinNum);
void LED_OFF(u8 PortName , u8 PinNum);
void LED_TOG(u8 PortName , u8 PinNum);


#endif