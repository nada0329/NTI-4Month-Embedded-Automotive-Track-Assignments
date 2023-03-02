#ifndef LCD_INT_H_
#define LCD_INT_H_

/* LCD control commands */
#define func_set       0b00111000
#define func_reset     0b00110000
#define display_on_off 0b00001100
#define display_off    0b00001000
#define display_clear  0b00000001
#define entrymode_set  0b00000110
#define set_CGRAM      0b01000000
#define set_DDRAM      0b10000000
#define home		   0b00000010


void LCD_voidInit(void);
void LCD_voidWriteChar(u8 ch);
void LCD_voidWriteString(u8* st);
void LCD_voidClearDisplay(void);
void LCD_WritingPosition(u8 row, u8 col);  // row is 1 or 2   // col is 1->16
void LCD_ptrConvertIntToStrDisplay(u16 val);
//void LCD_voidWritePattern(void);

#endif /* LCD_INT_H_ */
