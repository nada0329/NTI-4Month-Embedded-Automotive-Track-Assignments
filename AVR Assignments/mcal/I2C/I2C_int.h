/*
 * I2C_int.h
 *
 * Created: 3/5/2023 10:45:57 AM
 *  Author: Nada
 */ 


#ifndef I2C_INT_H_
#define I2C_INT_H_


#define I2C_PRESCALER_1		0
#define I2C_PRESCALER_4		1	
#define I2C_PRESCALER_16	2
#define I2C_PRESCALER_64	3
	
void I2C_Master_initVid(void);
void I2C_Slave_initVid(u8 address);
u8 I2C_GetStatus(void);
u8 I2C_start(u8 address);
u8 I2C_repeated_start(u8 address);
u8 I2C_write(u8 data);
u8 I2C_read_ack(void);
u8 I2C_read_nack(void);
void I2C_stop(void);
u8 I2C_Slave_Listen(void);
u8 I2C_Slave_Send(u8 data);
u8 I2C_Salve_Receive(void);


#endif /* I2C_INT_H_ */