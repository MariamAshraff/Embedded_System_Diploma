/*
 * KPD.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Mariam Ashraf
 */

#ifndef INCLUDE_KPD_H_
#define INCLUDE_KPD_H_
#include "stdlib.h"
#include "GPIO.h"


#define KEYPAD_PORT GPIOA

//------------------
// Keypad Connection pins
//------------------
#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_2
#define R3 GPIO_PIN_3

#define C0 GPIO_PIN_4
#define C1 GPIO_PIN_5
#define C2 GPIO_PIN_6
#define C3 GPIO_PIN_7



//------------------
// Keypad functions
//------------------


/**================================================================
* @Fn- Keypad_init
* @brief		- Initialize the Keypad PINS as per the configuration
* @retval 		- None
* Note			-
*/
void Keypad_init(void);
/**================================================================
* @Fn		- Keypad_getkey
* @brief 	- Get the key pressed on the keypad in ASCII format
* @retval	- uint8_t: ASCII code of the key pressed
* Note		-
*/
uint8_t Keypad_getkey(void);

#endif /* INCLUDE_KPD_H_ */
