/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 10/9/2022         *****************/
/**************** SWC     : LCD               *****************/
/**************** Version : 2.3               *****************/
/**************************************************************/
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_u8_LINE1      1
#define LCD_u8_LINE2      2

void LCD_VoidInit             (void);
                              
void LCD_VoidSendCommand      (u8 Copy_U8Command);
                              
void LCD_VoidSendChar         (u8 Copy_U8Char);  
                              
u8 LCD_u8GoToLine             (u8 Copy_LineNum,u8 Copy_Loction);

void LCD_VoidSentSringAndNum  (u8 *Copy_Pu8StringAndNum);
                            
void LCD_VoidClear            (void);
                              
void LCD_VoidShiftPatterns    (u8 Copy_TypeShift,u8 Copy_NumShift);

void LCD_VoidSinsoul          (u8 *Copy_Pu8StringAndNum);
void LCD_voidSendNumber       (u32 Copy_u8Number);


#endif
