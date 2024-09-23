/*
 * CFile1.c
 *
 * Created: 14/08/2024 10:38:08
 *  Author: Mariam Ashraf
 */

#include "LCD.h"

GPIO_PIN_CONFIG_t PinCfg;

uint16_t LCD_DATA_PIN[8] = {
		LCD_DATA_PIN_0,
		LCD_DATA_PIN_1,
		LCD_DATA_PIN_2,
		LCD_DATA_PIN_3,
		LCD_DATA_PIN_4,
		LCD_DATA_PIN_5,
		LCD_DATA_PIN_6,
		LCD_DATA_PIN_7
};

void _delay_ms(int x) {
	unsigned i, j;
	for (i = 0; i < x; i++)
		for (j = 0; j < 255; j++);
}

void LCD_voidSendCMD(uint8_t u8CMD) //Send Instruction to LCD
{

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS, GPIO_PIN_RESET);

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RW, GPIO_PIN_RESET);
#if defined EIGHT_BIT_MODE

	//MCAL_GPIO_WritePort(LCD_data_PORT, u8CMD);

	for (uint8_t i = 0; i < 8; i++) {
		MCAL_GPIO_WritePin(LCD_data_PORT, LCD_DATA_PIN[i], READ_BIT(u8CMD, i));
	}

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_SET);
	_delay_ms(20);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_RESET);

#elif defined FOUR_BIT_MODE

	for (uint8_t i = 4; i < 8; i++) {
		MCAL_GPIO_WritePin(LCD_data_PORT, LCD_DATA_PIN[i], READ_BIT(u8CMD, i));
	}

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_SET);
	_delay_ms(20);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_RESET);

	for (uint8_t i = 4; i < 8; i++) {
		MCAL_GPIO_WritePin(LCD_data_PORT, LCD_DATA_PIN[i],
				READ_BIT(u8CMD, i - 4));
	}

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_SET);
	_delay_ms(20);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_RESET);
	_delay_ms(30);
#endif
}

void LCD_voidWriteChar(uint8_t u8CHAR) //Send data to LCD
{
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RW, GPIO_PIN_RESET);

#if defined EIGHT_BIT_MODE
	for (uint8_t i = 0; i < 8; i++) {
		MCAL_GPIO_WritePin(LCD_data_PORT, LCD_DATA_PIN[i], READ_BIT(u8CHAR, i));
	}

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_SET);
	_delay_ms(20);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_RESET);
#elif defined FOUR_BIT_MODE

	for (uint8_t i = 4; i < 8; i++) {
		MCAL_GPIO_WritePin(LCD_data_PORT, LCD_DATA_PIN[i], READ_BIT(u8CHAR, i));
	}
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_SET);
	_delay_ms(20);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_RESET);

	for (uint8_t i = 4; i < 8; i++) {
		MCAL_GPIO_WritePin(LCD_data_PORT, LCD_DATA_PIN[i],READ_BIT(u8CHAR, i - 4));
	}
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_SET);
	_delay_ms(20);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_EN, GPIO_PIN_RESET);

#endif
	_delay_ms(5);
}

void LCD_voidLCDInit() {

	_delay_ms(30);
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	PinCfg.GPIO_PinNumber = LCD_RS;
	MCAL_GPIO_init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_RW;
	MCAL_GPIO_init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = LCD_EN;
	MCAL_GPIO_init(LCD_CTRL_PORT, &PinCfg);

#if defined EIGHT_BIT_MODE

	for (uint8_t i = 0; i < 8; i++) {
		PinCfg.GPIO_PinNumber = LCD_DATA_PIN[i];
		MCAL_GPIO_init(LCD_data_PORT, &PinCfg);
	}

	_delay_ms(30);
	LCD_voidSendCMD(LCD_FUNCTION_8BIT_2LINES);

#elif defined FOUR_BIT_MODE
	for (uint8_t i = 4; i < 8; i++) {
		PinCfg.GPIO_PinNumber = LCD_DATA_PIN[i];
		MCAL_GPIO_init(LCD_data_PORT, &PinCfg);
	}

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RW, GPIO_PIN_RESET);
	_delay_ms(30);
	LCD_voidSendCMD(LCD_HOME);
	LCD_voidSendCMD(LCD_FUNCTION_4BIT_2LINES);

#endif

	_delay_ms(1);
	LCD_voidSendCMD(LCD_DISP_ON);
	_delay_ms(1);
	LCD_voidSendCMD(LCD_CLEAR_SCREEN);
	_delay_ms(1);
	LCD_voidSendCMD(LCD_ENTRY_MODE);
	_delay_ms(1);
	LCD_voidSendCMD(LCD_BEGIN_AT_FIRST_ROW);

}

void LCD_voidGoTo(int8_t X, int8_t Y) {
	if (X > 0 && X <= 16) {
		switch (Y) {
		case 1:
			LCD_voidSendCMD(127 + X);
			break;
		case 2:
			LCD_voidSendCMD(191 + X);
			break;
		default:
			break;
		}
	}
}

void LCD_ClrLCD() {
	LCD_voidSendCMD(LCD_CLEAR_SCREEN);
	_delay_ms(2);

}
void LCD_voidWriteStrig(uint8_t *ptrStr) {
	uint8_t counter = 0;

	while (ptrStr[counter] != '\0') {
		LCD_voidWriteChar(ptrStr[counter]);
		counter++;
	}

}

void LCD_voidWriteNum(int32_t s32NUM) {
	int32_t temp = 1;
	if (s32NUM == 0) {
		LCD_voidWriteChar('0');
	}

	if (s32NUM < 0) {
		LCD_voidWriteChar('-');
		s32NUM *= -1;
	}
	while (s32NUM != 0) {
		temp = (temp * 10) + s32NUM % 10;
		s32NUM /= 10;
	}
	while (temp != 1) {
		LCD_voidWriteChar((temp % 10) + 48);
		temp /= 10;
	}
}

void LCD_voidSaveCustomChar(uint8_t CGRAMIndex, uint8_t CustomChar[]) {

	LCD_voidSendCMD(LCD_CGRAM_ADDRESS + CGRAMIndex * 8);

	for (uint8_t i = 0; i < 8; i++) {

		LCD_voidWriteChar(CustomChar[i]);
	}

	LCD_voidSendCMD(LCD_DDRAM_SETCURS);
}

void LCD_voidWriteCustomChar(uint8_t CGRAMIndex) {
	if (CGRAMIndex) {
		LCD_voidWriteChar(CGRAMIndex);

	}
}
