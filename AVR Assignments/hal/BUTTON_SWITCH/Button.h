/*
 * Button.h
 *
 *  Created on: Dec 11, 2022
 *      Author: Nada
 */
 
#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO.h"
#include "kit_cnfg.h"
#include <util/delay.h>

#define SW1		1
#define SW2		2
#define SW3		3
#define SW4		4
#define SW5		5
#define SW6		6
#define SW7		7
#define SW8		8
#define PB1		1
#define PB2		2
#define PB3		3
#define PB4		4

#define SW_PRESS	0 
#define SW_RELEASE	1
#define PB_PRESS	0
#define PB_RELEASE	1

void SW_Init(u8 id);
void PB_Init(u8 id);
u8 SW_GetState(u8 id);
u8 PB_GetState(u8 id);


#endif