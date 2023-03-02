/*
 * bit.h
 *
 *  Created on: Dec 10, 2022
 *      Author: Nada
 */

#ifndef BIT_H_
#define BIT_H_

#define assignbit(var,num,val) var|=(val<<num)
#define clrbit(var,num) var&=~(1<<num)
#define togbit(var,num) var^=(1<<num)
#define setbit(var,num) var|=(1<<num)
#define sethighnibble(var) var|=0xf0
#define setlownibble(var) var|=0x0f
#define clrlownibble(var) var&=0xf0
#define clrhighnibble(var) var&=0x0f
#define getbit(var,num) ((var>>num)& 0x01)

#endif /* BIT_H_ */
