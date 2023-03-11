/*
 * SPI_int.h
 *
 * Created: 3/4/2023 1:21:09 PM
 *  Author: Nada
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_

typedef enum
{
	SPI_MSTR,
	SPI_SLV
	
}SPI_MODE;

void SPI_INT_Enable(void);
void SPI_INT_Disable(void);
void SPI_Enable(void);
void SPI_Disable(void);
void SPI_SetCallBack_(void (*ptr) (void));
void SPI_Init(SPI_MODE mode);
void SPI_Mstr_SendData(u8 Sdata);
u8 SPI_Mstr_RecData(void);
u8 SPI_Mstr_Send_RecData(u8 Sdata);
void SPI_Slv_SendData(u8 Sdata);
u8 SPI_Slv_RecData(void);



#endif /* SPI_INT_H_ */