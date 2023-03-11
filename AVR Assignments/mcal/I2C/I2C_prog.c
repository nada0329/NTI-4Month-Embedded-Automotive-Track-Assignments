/*
 * I2C_prog.c
 *
 * Created: 3/5/2023 10:45:18 AM
 *  Author: Nada
 */ 

#include "type.h"
#include "bit.h"
#include "I2C_conf.h"
#include "I2C_priv.h"
#include "I2C_int.h"

void I2C_Master_initVid()
{
	#if	  I2C_Prescaler_Value==I2C_PRESCALER_1
	TWIBR_REG = BITRATE(TWISR_REG = 0x00);
	#elif I2C_Prescaler_Value==I2C_PRESCALER_4
	TWIBR_REG = BITRATE(TWISR_REG = 0x01);
	#elif I2C_Prescaler_Value==I2C_PRESCALER_16
	TWIBR_REG = BITRATE(TWISR_REG = 0x02);
	#elif I2C_Prescaler_Value==I2C_PRESCALER_64
	TWIBR_REG = BITRATE(TWISR_REG = 0x03);
	#endif
	// enable I2C
	setbit(TWICR_REG,TWEN);
	// bit0 = 0 to avoid general call
	TWIAR_REG = 0b00000010; //Not for address
	
}

void I2C_Slave_initVid(u8 address)
{
	//set address
	TWIAR_REG = address;
	// enable ACK generation
	setbit(TWICR_REG,TWEA);
	// enable I2C
	setbit(TWICR_REG,TWEN);
}

u8 I2C_GetStatus(void)
{
	u8 status;
	status = (TWISR_REG & 0xf8);
	return status;
}

u8 I2C_start(u8 address)
{
	TWICR_REG = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);//start cond,enable twi,clear int flag
	while(getbit(TWICR_REG,TWINT) == 0);//wait until the current event ends(starting)
	if(I2C_GetStatus() != I2C_START) //check whether start is transmitted or not
	{
		return 0;	//return 0 if start fail
	}
	TWIDR_REG = address; //write slave address in data reg
	TWICR_REG = (1<<TWEN)|(1<<TWINT); //enable and clear interrupt
	while(getbit(TWICR_REG,TWINT) == 0);//wait until the current event ends(send address of the slave)
	if(I2C_GetStatus() == I2C_MT_SLA_W_ACK)
	{
		return 1;	//ack received
	}
	if(I2C_GetStatus() == I2C_MT_SLA_W_NACK)
	{
		return 2;	//Nack received
	}

	return 3; 	// SLA + W failed

}

u8 I2C_repeated_start(u8 address)
{
	TWICR_REG = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);//start cond,enable twi,clear int flag
	while(getbit(TWICR_REG,TWINT) == 0);//wait until the current event ends(repeated start)
	if(I2C_GetStatus() != I2C_REP_START) //check whether start is transmitted or not
	{
		return 0;	//return 0 if repeated start fail
	}
	TWIDR_REG = address; //write slave address and read bit in data reg
	TWICR_REG = (1<<TWEN)|(1<<TWINT); //enable and clear interrupt
	while(getbit(TWICR_REG,TWINT) == 0);//wait until the current event ends(send address of the slave)
	if(I2C_GetStatus() == I2C_MR_SLA_R_ACK)
	{
		return 1;	//ack received
	}
	if(I2C_GetStatus() == I2C_MR_SLA_R_NACK)
	{
		return 2;	//Nack received
	}

	return 3; 	// SLA + R failed
}

u8 I2C_write(u8 data)//data or address
{
	TWIDR_REG = data;
	TWICR_REG = (1<<TWEN)|(1<<TWINT); //enable and clear interrupt
	while(getbit(TWICR_REG,TWINT) == 0);//wait until the current event ends(writing data)
	if(I2C_GetStatus() == I2C_MT_DATA_ACK)
	{
		return 0;	//ack received
	}
	if(I2C_GetStatus() == I2C_MT_DATA_NACK)
	{
		return 1; //nack received
	}
	return 2;	//transmission failure
}

u8 I2C_read_ack(void)
{
	TWICR_REG = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);//Enable TWI,INT and Enable acknowledge
	while(getbit(TWICR_REG,TWINT) == 0);//wait until the current event ends(reading data)
	return TWIDR_REG;
}


u8 I2C_read_nack(void)
{
	TWICR_REG = (1<<TWEN)|(1<<TWINT);
	while(getbit(TWICR_REG,TWINT) == 0);//wait until the current event ends(reading data)
	return TWIDR_REG;
}

void I2C_stop(void)
{
	TWICR_REG = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}


u8 I2C_Slave_Listen(void)
{
	while(1)
	{
		while(getbit(TWICR_REG,TWINT) == 0);
		if((I2C_GetStatus() == I2C_SR_SLA_W_ACK) || (I2C_GetStatus() == I2C_SR_ARB_LOST))
		{
			/* Own SLA+W received &ack returned */
			return 0;
		}
		if((I2C_GetStatus() == I2C_ST_SLA_R_ACK) || (I2C_GetStatus() == I2C_ST_ARB_LOST_SLA_R_W_ACK))
		{
			/* Own SLA+R received &ack returned */
			return 1;
		}
		if((I2C_GetStatus() == I2C_SR_GEN_CALL) || (I2C_GetStatus() == I2C_SR_ARB_LOST_GEN_CALL))
		{
			/* General call received &ack returned */
			return 2;
		}
		else
		continue;

	}

}


u8 I2C_Slave_Send(u8 data)
{
	TWIDR_REG = data;
	TWICR_REG = (1<<TWINT) | (1<<TWEN)| (1<<TWEA);
	while(getbit(TWICR_REG,TWINT) == 0);
	/* Check for STOP/REPEATED START received */
	if(I2C_GetStatus() == I2C_SR_REP_START_OR_STOP)
	{
		setbit(TWICR_REG,TWINT);
		return 16;
	}
	/* Check for data transmitted &ack received */
	if(I2C_GetStatus() == I2C_ST_DATA_ACK)
	{
		setbit(TWICR_REG,TWINT);
		return 0;
	}
	/* Check for data transmitted &nack received */
	if(I2C_GetStatus() == I2C_ST_DATA_NACK)
	{
		setbit(TWICR_REG,TWINT);
		return 26;
	}
	/* Last byte transmitted with ack received */
	if(I2C_GetStatus() == I2C_ST_LAST_BYTE)
	{
		return 36;
	}
	else
	{
		return 46;	//transmission failed
	}
}

u8 I2C_Salve_Receive(void)
{

	TWICR_REG = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(getbit(TWICR_REG,TWINT) == 0);
	/* Check for data received &ack returned */
	if((I2C_GetStatus() == I2C_SR_PRE_ADD_SLA_W_ACK) ||(I2C_GetStatus() == I2C_SR_PRE_ADD_GEN_CALL_ACK))
	{
		return TWIDR_REG;
	}
	/* Check for data received, nack returned & switched to not addressed slave mode */
	if((I2C_GetStatus() == I2C_SR_PRE_ADD_SLA_W_NACK) ||(I2C_GetStatus() == I2C_SR_PRE_ADD_GEN_CALL_NACK))
	{
		return TWIDR_REG;
	}
	/* Check wether STOP/REPEATED START */
	if(I2C_GetStatus() == I2C_SR_REP_START_OR_STOP)
	{
		setbit(TWICR_REG,TWINT);
		return 15;
	}
	else
	return 25;//Receiving failed

}

