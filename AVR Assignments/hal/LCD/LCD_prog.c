
#include "type.h"
#define F_CPU 8000000UL
#include "kit_cnfg.h"
#include "util/delay.h"
#include "DIO.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "LCD_int.h"


void LCD_voidInit(void)    
{
	DIO_voidSetPinDir(RS_PORT , RS , output);
	DIO_voidSetPinDir(E_PORT , E , output);
	
	#if LCD_MODE == LCD_8_BIT
	DIO_viodSetPortDir(DATAPORT , output);

	_delay_ms(30);
	SendInstruction(func_set);
	_delay_ms(5);
	SendInstruction(display_on_off);
	_delay_ms(5);
	SendInstruction(display_clear);
	_delay_ms(5);
	SendInstruction(entrymode_set);
	
	#elif LCD_MODE == LCD_4_BIT
	DIO_voidSetPinDir(DATAPORT , PIN4_LCD , output);
	DIO_voidSetPinDir(DATAPORT , PIN5_LCD , output);
	DIO_voidSetPinDir(DATAPORT , PIN6_LCD , output);
	DIO_voidSetPinDir(DATAPORT , PIN7_LCD , output);
	
	_delay_ms(40);
	DIO_voidSetPinVal(RS_PORT , RS , low);
	DIO_voidSetPinVal(DATAPORT , PIN4_LCD , low);
	DIO_voidSetPinVal(DATAPORT , PIN5_LCD , high);
	DIO_voidSetPinVal(DATAPORT , PIN6_LCD , low);
	DIO_voidSetPinVal(DATAPORT , PIN7_LCD , low);
	DIO_voidSetPinVal(E_PORT , E , high);
	_delay_ms(5);
	DIO_voidSetPinVal(E_PORT , E , low);
	_delay_ms(5);
	SendInstruction(0b00000010);
	SendInstruction(0b00101000);  // DB4=0
	_delay_ms(40);
	SendInstruction(display_on_off);
	_delay_ms(40);
	SendInstruction(display_clear);
	_delay_ms(2);
	SendInstruction(entrymode_set);
	

	#endif
}

void SendInstruction(u8 Ins)  
{
	#if LCD_MODE == LCD_8_BIT
	//set RS 0
	DIO_voidSetPinVal(RS_PORT ,  RS , low);
	//set D0 ->D7
	DIO_voidSetPortVal( DATAPORT ,  Ins);
	//FALLING EDGE TO WRITE
	DIO_voidSetPinVal(E_PORT ,  E , high);  //high enable
	_delay_ms(2);
	DIO_voidSetPinVal(E_PORT ,  E , low);  //low enable
	_delay_ms(2);
	
	#elif LCD_MODE == LCD_4_BIT
	//set RS 0
	DIO_voidSetPinVal(RS_PORT ,  RS , low);
	//4 high bits first then 4 low bits
	DIO_voidSetPinVal(DATAPORT , PIN4_LCD , getbit(Ins,4));
	DIO_voidSetPinVal(DATAPORT , PIN5_LCD , getbit(Ins,5));
	DIO_voidSetPinVal(DATAPORT , PIN6_LCD , getbit(Ins,6));
	DIO_voidSetPinVal(DATAPORT , PIN7_LCD , getbit(Ins,7));
	DIO_voidSetPinVal(E_PORT , E , high);
	_delay_ms(5);
	DIO_voidSetPinVal(E_PORT , E , low);
	DIO_voidSetPinVal(DATAPORT , PIN4_LCD , getbit(Ins,0));
	DIO_voidSetPinVal(DATAPORT , PIN5_LCD , getbit(Ins,1));
	DIO_voidSetPinVal(DATAPORT , PIN6_LCD , getbit(Ins,2));
	DIO_voidSetPinVal(DATAPORT , PIN7_LCD , getbit(Ins,3));
	DIO_voidSetPinVal(E_PORT , E , high);
	_delay_ms(5);
	DIO_voidSetPinVal(E_PORT , E , low);
	
	#endif
}

void LCD_voidWriteChar(u8 ch)
{
	#if LCD_MODE == LCD_8_BIT
	//set RS 1
	DIO_voidSetPinVal(RS_PORT ,  RS , high);
	
	//set D0 ->D7
	DIO_voidSetPortVal( DATAPORT ,  ch);
	
	//FALLING EDGE TO WRITE
	DIO_voidSetPinVal(E_PORT ,  E , high);  //high enable
	_delay_ms(2);
	DIO_voidSetPinVal(E_PORT ,  E , low);  //low enable
	_delay_ms(2);
	#elif LCD_MODE == LCD_4_BIT
	//set RS 1
	DIO_voidSetPinVal(RS_PORT ,  RS , high);
	//4 high bits first then 4 low bits
	DIO_voidSetPinVal(DATAPORT , PIN4_LCD , getbit(ch,4));
	DIO_voidSetPinVal(DATAPORT , PIN5_LCD , getbit(ch,5));
	DIO_voidSetPinVal(DATAPORT , PIN6_LCD , getbit(ch,6));
	DIO_voidSetPinVal(DATAPORT , PIN7_LCD , getbit(ch,7));
	DIO_voidSetPinVal(E_PORT , E , high);
	_delay_ms(5);
	DIO_voidSetPinVal(E_PORT , E , low);
	DIO_voidSetPinVal(DATAPORT , PIN4_LCD , getbit(ch,0));
	DIO_voidSetPinVal(DATAPORT , PIN5_LCD , getbit(ch,1));
	DIO_voidSetPinVal(DATAPORT , PIN6_LCD , getbit(ch,2));
	DIO_voidSetPinVal(DATAPORT , PIN7_LCD , getbit(ch,3));
	DIO_voidSetPinVal(E_PORT , E , high);
	_delay_ms(5);
	DIO_voidSetPinVal(E_PORT , E , low);
	
	#endif	
}

void LCD_voidWriteString(u8* st)
{
	u8 i;
	for(i=0;st[i] != '\0' ;i++)
		LCD_voidWriteChar(st[i]);
}

void LCD_voidClearDisplay(void)
{
	SendInstruction(display_clear);
}

void LCD_WritingPosition(u8 row, u8 col)
{
	switch(row)
	{
		case 1:
			SendInstruction(col -1+ 0x80);
			break;
		case 2:
			SendInstruction(col -1+ 0xc0);
			break;
		case 3:
			SendInstruction(col -1+ 0x94);
			break;
		case 4:
			SendInstruction(col -1+ 0xd4);
			break;		
		default:
			break;
	}
}

void LCD_ptrConvertIntToStrDisplay(u16 val)
{
	static u8 converted_val[16]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
	u8* ptr=&converted_val[15];
	*ptr= '\0';
	if(val==0)
	{
		ptr-- ;
		*ptr= '0';
	}
	while(val != 0)
	{
		ptr-- ;
		*ptr= (val%10)+'0';
		val/=10;
	}
	LCD_voidWriteString(ptr);

}
/*
void LCD_voidWritePattern(void)
{
	SendInstruction(set_CGRAM);

	u8 i,pattern[]={ 0x17,0x14,0x14,0x12,0x12,0x12,0x1e,0x00, //ye
		             0x00,0x01,0x01,0x01,0x01,0x01,0x0f,0x00,  //dal
					 0x0e,0x0a,0x0a,0x0a,0x0a,0x0a,0x1f,0x00,  //mem
					 0x00,0x08,0x04,0x02,0x01,0x01,0x1e,0x00, //ha
					 0x17,0x14,0x14,0x12,0x12,0x12,0x1e,0x00, //ye
					 0x00,0x01,0x01,0x01,0x01,0x01,0x0f,0x00,  //dal
					 0x04,0x05,0x01,0x01,0x01,0x01,0x1f,0x00 //non
	                                                                  };
	for(i=0;i<=55;i++)
	{
		LCD_voidWriteChar(pattern[i]);
	}
	SendInstruction(set_DDRAM);


		LCD_WritingPosition(2,5);
		for(i=0;i<7;i++)
			LCD_voidWriteChar(i);
}
*/





