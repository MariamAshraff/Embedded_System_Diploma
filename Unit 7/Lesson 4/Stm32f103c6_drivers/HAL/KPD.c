/*
 * KPD.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Mariam Ashraf
 */
#include "KPD.h"

uint8_t KEY_ROWS[4] = { R0, R1, R2, R3 };
uint8_t KEY_COLS[4] = { C0, C1, C2, C3 };
uint8_t arr[4][4] = {
		{ '7', '8', '9', '/' },
		{ '4', '5', '6', '*' },
		{ '1', '2', '3', '-' },
		{ 'A', '0', '=', '+' }
};

void Keypad_init(void) {

	GPIO_PIN_CONFIG_t Keypad_PinConfig;

	Keypad_PinConfig.GPIO_MODE = GPIO_MODE_INPUT_PU;

	//Keypad_PinConfig.GPIO_Direction = Input;
	for (uint8_t i = 0; i < 4; i++) {
		Keypad_PinConfig.GPIO_PinNumber = KEY_COLS[i];
		MCAL_GPIO_init(KEYPAD_PORT, &Keypad_PinConfig);
	}
	//start with ROWS are output and COLUMNS are input
	Keypad_PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Keypad_PinConfig.GPIO_Output_Speed = GPIO_SPEED_10M;
	for (uint8_t i = 0; i < 4; i++) {
		Keypad_PinConfig.GPIO_PinNumber = KEY_ROWS[i];
		MCAL_GPIO_init(KEYPAD_PORT, &Keypad_PinConfig);
	}

	//MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);
//

}

uint8_t Keypad_getkey(void) {
	uint8_t row, coloumn, x;
	uint8_t returnval = 0xff;

	for (row = 0; row < 4; row++) {
		//make all row pins high except the current row
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEY_ROWS[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEY_ROWS[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEY_ROWS[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEY_ROWS[3], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KEY_ROWS[row], GPIO_PIN_RESET);

		//check the columns
		for (coloumn = 0; coloumn < 4; coloumn++) {
			x = MCAL_GPIO_ReadPin(KEYPAD_PORT, KEY_COLS[coloumn]);
			if (x == 0) {
				returnval = arr[row][coloumn];

				while (x == 0) {
					x = MCAL_GPIO_ReadPin(KEYPAD_PORT, KEY_COLS[coloumn]);
				}
			}

		}
	}
	return returnval;
}
//int KeypadRow[] = {R0,R1,R2,R3};	//keypad rows
//int KeypadCol[] = {C0,C1,C2,C3};	//Keypad coulomb
//
//void Keypad_Init()
//{
//
//
//	//-------------------------------------------
//	//set upper part of keypad port as input
//	//KeypadDDR &=~(0x0F);
//	//KeypadDDR &=~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
//	PinCfg.GPIO_PinNumber = R0 ;
//	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
//	MCAL_GPIO_Init_Port_Range(KeypadPORT,&PinCfg,2);
//
//	PinCfg.GPIO_PinNumber = R2 ;
//	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
//	MCAL_GPIO_Init_Port_Range(KeypadPORT,&PinCfg,6);
//
//
//	MCAL_GPIO_WritePort(KeypadPORT, 0xFF);
//
//}
//
//char Keypad_Getkey()
//{
//
//	int i,j;
//	for(i=0; i<4; i++)
//	{
//		//KeypadPORT |=((1<<KeypadCol[0])|(1<<KeypadCol[1])|(1<<KeypadCol[2])|(1<<KeypadCol[3])) ;
//		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[0] , 1);
//		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[1] ,1);
//		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[2] , 1);
//		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[3] , 1);
//
//		//KeypadPORT &=~(1<<KeypadCol[i]); //send low to the next coulomb to check which intersect is pushed
//		MCAL_GPIO_WritePin(KeypadPORT,KeypadCol[i] ,0);
//
//		for(j=0; j<4; j++)
//		{
//			if(MCAL_GPIO_ReadPin(KeypadPORT, KeypadRow[j]) == 0) //check if key is pressed
//			{
//				while(MCAL_GPIO_ReadPin(KeypadPORT, KeypadRow[j]) == 0);
//				switch(i)
//				{
//					case 0 :
//					{
//						if (j == 0) return '7';
//						else if (j == 1) return '4';
//						else if (j == 2) return '1';
//						else if (j == 3) return '?';
//						break;
//					}
//					case 1 :
//					{
//						if (j == 0) return '8';
//						else if (j == 1) return '5';
//						else if (j == 2) return '2';
//						else if (j == 3) return '0';
//						break;
//					}
//					case 2 :
//					{
//						if (j == 0) return '9';
//						else if (j == 1) return '6';
//						else if (j == 2) return '3';
//						else if (j == 3) return '=';
//						break;
//					}
//					case 3 :
//					{
//						if (j == 0) return '/';
//						else if (j == 1) return '*';
//						else if (j == 2) return '-';
//						else if (j == 3) return '+';
//						break;
//					}
//				}
//			}
//
//		}
//	}
//	return 'A';	//Return 'A' if no key is pressed
//}
