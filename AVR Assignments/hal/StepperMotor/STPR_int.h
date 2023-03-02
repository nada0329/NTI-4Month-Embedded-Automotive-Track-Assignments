/*
 * STPR_int.h
 *
 * Created: 3/1/2023 10:55:31 PM
 *  Author: Nada
 */ 


#ifndef STPR_INT_H_
#define STPR_INT_H_

void StprMotor_voidInit( void );
void StprMotor_voidRotateClkwiseFullstep( u8 motor);
void StprMotor_voidRotateAntiClkwiseFullstep( u8 motor );
void StprMotor_voidRotateClkwiseHalfstep( u8 motor);
void StprMotor_voidRotateAntiClkwiseHalfstep( u8 motor);
void StprMotor_voidStop( u8 motor);

#endif /* STPR_INT_H_ */