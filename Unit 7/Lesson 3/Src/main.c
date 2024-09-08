/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mariam Ashraf
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103C6_GPIO_DRIVER.h"

void delay(unsigned int x){

	unsigned int i ,j ;
	for(i=0; i<x; i++)
		for(j=0; j<256; j++);
}


void Clock_Init()
{
	RCC_GPIOA_CLOCK_ENABLE();
	RCC_GPIOB_CLOCK_ENABLE();

}

void GPIO_Init()
{

	//set port A pin 13 as input floating
	GPIO_PIN_CONFIG_t PinConfig;
	PinConfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_13;
	MCAL_GPIO_init(GPIOA, &PinConfig);

	//set port A pin 1 as input floating
	PinConfig.GPIO_MODE=GPIO_MODE_INPUT_FLO;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	MCAL_GPIO_init(GPIOA, &PinConfig);

	//set port B pin 1 as output mode (push-pull),max speed 10MHZ
	PinConfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_1;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinConfig);
	// set portB pin 13 as output mode(push-pull),max speed 10MHZ

	PinConfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_PinNumber=GPIO_PIN_13;
	PinConfig.GPIO_Output_Speed=GPIO_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinConfig);
}

int main(void)
{
	Clock_Init();
	GPIO_Init();

	while(1)
	{

		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0)  //single pressing
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);

			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0);
		}
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)==1) //multi pressing
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		delay(3);

	}
}
