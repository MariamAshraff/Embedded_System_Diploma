/*
 * Lcd.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Mariam
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include "stdlib.h"
#include "GPIO.h"
#include "STM32F103X6.h"
/******************PORTA*************************/
#define LCD_data_PORT 			GPIOA
#define LCD_CTRL_PORT 			GPIOA
#define LCD_RS 					GPIO_PIN_8
#define LCD_RW 					GPIO_PIN_9
#define LCD_EN 					GPIO_PIN_10

#define LCD_DATA_PIN_0 GPIO_PIN_0
#define LCD_DATA_PIN_1 GPIO_PIN_1
#define LCD_DATA_PIN_2 GPIO_PIN_2
#define LCD_DATA_PIN_3 GPIO_PIN_3
#define LCD_DATA_PIN_4 GPIO_PIN_4
#define LCD_DATA_PIN_5 GPIO_PIN_5
#define LCD_DATA_PIN_6 GPIO_PIN_6
#define LCD_DATA_PIN_7 GPIO_PIN_7

/******************PORTB*************************/
/*#define LCD_data_PORT 			GPIOB
#define LCD_CTRL_PORT 			GPIOB
#define LCD_RS 					GPIO_PIN_12
#define LCD_RW 					GPIO_PIN_13
#define LCD_EN 					GPIO_PIN_14

#define LCD_DATA_PIN_0 GPIO_PIN_0
#define LCD_DATA_PIN_1 GPIO_PIN_1
#define LCD_DATA_PIN_2 GPIO_PIN_3
#define LCD_DATA_PIN_3 GPIO_PIN_4
#define LCD_DATA_PIN_4 GPIO_PIN_5
#define LCD_DATA_PIN_5 GPIO_PIN_6
#define LCD_DATA_PIN_6 GPIO_PIN_7
#define LCD_DATA_PIN_7 GPIO_PIN_8*/

//#define DATA_shift 0 // in 8 bit mode 0 and in 4 bit mode 4

//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
#define LCD_HOME            						(0X02)
#define LCD_CGRAM_ADDRESS   						(0X40)
#define LCD_DDRAM_SETCURS   						(0X80)

void LCD_voidLCDInit();
void LCD_voidSendCMD(uint8_t u8CMD);
void LCD_voidWriteChar(uint8_t u8CHAR);
void LCD_voidGoTo(int8_t X, int8_t Y);
void LCD_ClrLCD();
void LCD_voidWriteStrig(uint8_t *ptrStr);
void LCD_voidWriteNum(int32_t s32NUM);
void LCD_voidSaveCustomChar(uint8_t CGRAMIndex, uint8_t CustomChar[]);
void LCD_voidWriteCustomChar(uint8_t CGRAMIndex);

#endif /* HAL_LCD_H_ */
