/*
 * SPI_conf.h
 *
 * Created: 3/4/2023 1:20:41 PM
 *  Author: Nada
 */ 


#ifndef SPI_CONF_H_
#define SPI_CONF_H_

/************************/
#define SPI_Prescalar	SPI_PRE16
#define SPI_PRE4	0
#define SPI_PRE16	1
#define SPI_PRE64	2
#define SPI_PRE128	3
#define SPI_PRE2	4
#define SPI_PRE8	5
#define SPI_PRE32	6
//#define SPI_PRE64	7

/************************/
#define  SPI_CLK_PH		SPI_LEAD_SAMPLE

#define SPI_LEAD_SAMPLE 0
#define SPI_LEAD_SETUP	1

/************************/
#define SPI_CLK_POL		SPI_LEAD_RISE

#define SPI_LEAD_RISE 0
#define SPI_LEAD_FALL 1

/************************/
#define SPI_DATA_ORDER	SPI_MSB

#define SPI_MSB	0
#define SPI_LSB	1

/************************/
#define SPI_SPEED	SPI_NRM

#define SPI_NRM	0
#define SPI_DBL	1



#endif /* SPI_CONF_H_ */