/*
 * SPI_priv.h
 *
 * Created: 3/4/2023 1:19:34 PM
 *  Author: Nada
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPCR_REG	 *((volatile u8 *)(0x2D))
#define SPSR_REG	 *((volatile u8 *)(0x2E))
#define SPDR_REG	 *((volatile u8 *)(0x2F))
#define SPI_DDR_REG  *((volatile u8 *)(0x37))
#define SPI_PORT_REG *((volatile u8 *)(0x38))

//SPCR_REG address
#define SPIE	7
#define SPE		6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0
//SPSR_REG address
#define SPIF	7
#define WCOL	6
#define SPI2X	0
//SPI_DDR_REG
#define SPI_MOSI	5
#define SPI_MISO	6
#define SPI_SS		4
#define SPI_SCK		7





#endif /* SPI_PRIV_H_ */