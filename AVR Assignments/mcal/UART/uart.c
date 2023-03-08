/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  uart.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "uart_reg.h"
#include "uart.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void (*UART_RXC_ptr) (u8);
u8 (*UART_TXC_ptr) (void);
u8 (*UART_UDRE_ptr) (void);
// use in TX int
u8 arr[20];
u8 byte_index=0;
// use in RX int
u8 arr2[20];
u8 byte_index2=0;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void UART_Init(u16 baudRate)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : baudRate   UART baudrate                                                                     
* \Return value:   : None                                   
*******************************************************************************/
void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRL_REG = (u8)baudRate;
	UART_UBRRH_REG = (u8)(baudRate>>8);

	/* Enable receiver and transmitter */
	setbit(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	setbit(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO) | UART_8_BIT_DATA | UART_EVEN_PARITY;

	setbit(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
	setbit(UART_UCSRB_REG,6); /*	Enable Tx Complete Interrupt	*/
}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : data   data byte                                                                    
* \Return value:   : None                                   
*******************************************************************************/
void UART_TransmitChr(u8 data)
{
	/* Put data into buffer*/
	while(getbit(UART_UCSRA_REG,5) == 0);
	UART_UDR_REG = data;
}

/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                    
* \Return value:   : u8     received data byte                                   
*******************************************************************************/
u8 UART_ReceiveChr(void)
{
	while(getbit(UART_UCSRA_REG,7) == 0);
	/*check errors*/
	if(getbit(UART_UCSRA_REG,4)==1 || getbit(UART_UCSRA_REG,3)==1 || getbit(UART_UCSRA_REG,2)==1 )
	return -1;
	return UART_UDR_REG;
}

void UART_TransmitStr(u8 *data)
{
	while(*data !='\0')
	{
		UART_TransmitChr(*data);
		data++;
		
	}
}


u8 UART_ReceiveStr(u8 *data)
{
	u8 i=0;
	u8 x=UART_ReceiveChr();
	while(x !='!')
	{
		data[i]=x;
		x=UART_ReceiveChr();
		i++;
	}
	data[i]='\0';
	return i;
}


void UART_TXINT_Enable(void)
{
	setbit(UART_UCSRB_REG,6);
}
void UART_TXINT_Disable(void)
{
	clrbit(UART_UCSRB_REG,6);
}
void UART_RXINT_Enable(void)
{
	setbit(UART_UCSRB_REG,7);
}
void UART_RXINT_Disable(void)
{
	clrbit(UART_UCSRB_REG,7);
}
void UART_UDRINT_Enable(void)
{
	setbit(UART_UCSRB_REG,5);
}
void UART_UDRINT_Disable(void)
{
	clrbit(UART_UCSRB_REG,5);
}
void UART_RXC_SetCallBack_(void (*ptr) (u8))
{
	UART_RXC_ptr=ptr;
}
void UART_UDRE_SetCallBack_(u8 (*ptr) (void))
{
	UART_UDRE_ptr=ptr;
}
void UART_TXC_SetCallBack_(u8 (*ptr) (void))
{
	UART_TXC_ptr=ptr;
}

u8 UART_ReceiveChr_INT(void)
{
	/*check errors*/
	if(getbit(UART_UCSRA_REG,4)==1 || getbit(UART_UCSRA_REG,3)==1 || getbit(UART_UCSRA_REG,2)==1 )
	return -1;
	return UART_UDR_REG;
}
void UART_TransmitChr_INT(u8 data)
{
	/* Put data into buffer*/
	UART_UDR_REG = data;
}


void __vector_13(void) __attribute__(( signal , used ));
void __vector_13(void)
{
/*	u8 x;
	x=UART_ReceiveChr_INT();
	UART_RXC_ptr(x);
*/

	arr2[byte_index2]=UART_UDR_REG;
	byte_index2++;	
}
// use in RX int
void UART_RX_STR(u8* str)
{
	u8 i;
		for( i=0; arr2[i]!='!';i++)
		{
			str[i]=arr2[i];
		}
		str[i]='\0';
		byte_index2=0;
	
}
u8 UART_Check_Rec_Str()
{
	if(byte_index2==0)
		return 0;
	else if(arr2[byte_index2-1] == '!')
		return 1;
	else
		return 0;	
}

void __vector_14(void) __attribute__(( signal , used ));
void __vector_14(void)
{
	u8 x=UART_UDRE_ptr();
	UART_TransmitChr_INT(x);
	//UART_UDRE_ptr();
	
}

void __vector_15(void) __attribute__(( signal , used ));
void __vector_15(void)
{
	//UART_TXC_ptr();
	byte_index++;
	if(arr[byte_index] != '\0')
	{
		UART_UDR_REG=arr[byte_index];
	}
	else
	{
		byte_index=0;
	}
	
}

// use in TX int
void UART_TX_STR(u8* str)
{
	if(byte_index==0)
	{
		
		for(u8 i=0; str[i]!='\0';i++)
		{
			arr[i]=str[i];
		}
		UART_UDR_REG=arr[byte_index];
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
