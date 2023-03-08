/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  uart.h
 *       Module:  uart
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_H_
#define UART_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#include "uart_reg.h"
#include "type.h"
#include "bit.h"

#define RX_BUFFER_SIZE				(25)

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x1A0)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			0x33//(0x67)
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x8)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void UART_Init(u16 baudRate);
void UART_TransmitChr(u8 data);
void UART_TransmitStr(u8 *str);
u8 UART_ReceiveChr(void);
u8 UART_ReceiveStr(u8 *data);
void UART_TransmitStr(u8 *data);

void UART_TXINT_Enable(void);
void UART_TXINT_Disable(void);
void UART_RXINT_Enable(void);
void UART_RXINT_Disable(void);
void UART_UDRINT_Enable(void);
void UART_UDRINT_Disable(void);
void UART_RXC_SetCallBack_(void (*ptr) (u8));
void UART_UDRE_SetCallBack_(u8 (*ptr) (void));
void UART_TXC_SetCallBack_(u8 (*ptr) (void));
u8 UART_ReceiveChr_INT(void);
void UART_TransmitChr_INT(u8 data);

void UART_TX_STR(u8* str);
void UART_RX_STR(u8* str);
u8 UART_Check_Rec_Str(void);

#endif  /* UART_H_ */

/**********************************************************************************************************************
 *  END OF FILE: uart.h
 *********************************************************************************************************************/
