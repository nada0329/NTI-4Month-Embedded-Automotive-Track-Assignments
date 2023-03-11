/*
 * I2C_priv.h
 *
 * Created: 3/5/2023 10:45:36 AM
 *  Author: Nada
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#define TWIBR_REG	*((volatile u8*)0x20) 
#define TWICR_REG	*((volatile u8*)0x56)
#define TWISR_REG	*((volatile u8*)0x21)
#define TWIDR_REG	*((volatile u8*)0x23)
#define TWIAR_REG	*((volatile u8*)0x22)

//TWICR bits
#define TWIE  0
#define TWEN  2
#define TWWC  3
#define TWSTO 4
#define TWSTA 5
#define TWEA  6
#define TWINT 7

//TWISR bits
#define TWPS0 0
#define TWPS1 1

extern double pow(double __x, double __y) __attribute__((__const__));
#define BITRATE(TWISR_REG)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWISR_REG&((1<<TWPS0)|(1<<TWPS1)))))


#define I2C_START			0x08
#define I2C_REP_START		0x10
#define I2C_MT_SLA_W_ACK	0x18
#define I2C_MT_SLA_W_NACK	0x20
#define I2C_MT_DATA_ACK		0x28
#define I2C_MT_DATA_NACK	0x30
#define I2C_MT_ARB_LOST		0x38

#define I2C_MR_SLA_R_ACK	0x40
#define I2C_MR_SLA_R_NACK	0x48
#define I2C_MR_DATA_ACK		0x50
#define I2C_MR_DATA_NACK	0x58

#define I2C_SR_SLA_W_ACK				0x60
#define I2C_SR_ARB_LOST					0x68
#define I2C_SR_GEN_CALL					0x70
#define I2C_SR_ARB_LOST_GEN_CALL		0x78
#define I2C_SR_PRE_ADD_SLA_W_ACK		0x80
#define I2C_SR_PRE_ADD_SLA_W_NACK		0x88
#define I2C_SR_PRE_ADD_GEN_CALL_ACK		0x90
#define I2C_SR_PRE_ADD_GEN_CALL_NACK	0x98
#define I2C_SR_REP_START_OR_STOP		0xA0

#define I2C_ST_SLA_R_ACK			 0xA8
#define I2C_ST_ARB_LOST_SLA_R_W_ACK  0xB0
#define I2C_ST_DATA_ACK				 0xB8
#define I2C_ST_DATA_NACK			 0xC0
#define I2C_ST_LAST_BYTE			 0xC8

#define I2C_NO_STATUS_INFO	0xf8
#define I2C_BUS_ERROR		0x00



#endif /* I2C_PRIV_H_ */