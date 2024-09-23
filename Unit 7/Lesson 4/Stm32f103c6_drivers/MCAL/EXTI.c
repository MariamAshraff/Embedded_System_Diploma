/*
 * EXTI.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Mariam Ashraf
 */

#include "EXTI.h"
void Enable_NVIC(uint16_t IRQ) {
	switch (IRQ) {
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}
}
void Disable_NVIC(uint16_t IRQ) {
	switch (IRQ) {
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;
	}
}
void (*GP_IRQ_CallBack[15])(void);

void EXTI0_IRQHandler(void)
{
	EXTI->PR|=1<<0;
	GP_IRQ_CallBack[0]();
}
void EXTI1_IRQHandler(void)
{
	EXTI->PR|=1<<1;
	GP_IRQ_CallBack[1]();
}
void EXTI2_IRQHandler(void)
{
	EXTI->PR|=1<<2;
	GP_IRQ_CallBack[2]();
}
void EXTI3_IRQHandler(void)
{
	EXTI->PR|=1<<3;
	GP_IRQ_CallBack[3]();
}
void EXTI4_IRQHandler(void)
{
	EXTI->PR|=1<<4;
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI->PR & 1 << 5) { EXTI->PR |= 1 << 5;  GP_IRQ_CallBack[5](); }
	if (EXTI->PR & 1 << 6) { EXTI->PR |= 1 << 6;  GP_IRQ_CallBack[6](); }
	if (EXTI->PR & 1 << 7) { EXTI->PR |= 1 << 7;  GP_IRQ_CallBack[7](); }
	if (EXTI->PR & 1 << 8) { EXTI->PR |= 1 << 8;  GP_IRQ_CallBack[8](); }
	if (EXTI->PR & 1 << 9) { EXTI->PR |= 1 << 9;  GP_IRQ_CallBack[9](); }
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI->PR & 1 << 10) { EXTI->PR |= 1 << 10;  GP_IRQ_CallBack[10](); }
	if (EXTI->PR & 1 << 11) { EXTI->PR |= 1 << 11;  GP_IRQ_CallBack[11](); }
	if (EXTI->PR & 1 << 12) { EXTI->PR |= 1 << 12;  GP_IRQ_CallBack[12](); }
	if (EXTI->PR & 1 << 13) { EXTI->PR |= 1 << 13;  GP_IRQ_CallBack[13](); }
	if (EXTI->PR & 1 << 14) { EXTI->PR |= 1 << 14;  GP_IRQ_CallBack[14](); }
	if (EXTI->PR & 1 << 15) { EXTI->PR |= 1 << 15;  GP_IRQ_CallBack[15](); }
}

#define AFIO_GPIO_EXTI_Mapping_PORT(x)	((x == GPIOA)? 	0:\
									(x ==  GPIOB)? 	1:\
									(x ==  GPIOC)? 	2:\
									(x ==  GPIOD)? 	3:0)
/**================================================================
 * @Fn					 	-MCAL_EXTI_GPIO_Init
 * @brief 				 	-initializes the EXTI GPIOx PINy peripheral
 * @param [in] 			 	-EXTI_config pointer to a EXTI_CONFIG structure that contains
 * 						   	the configuration information
 * @retval				 	-none
 * Note-					-none
 */
void MCAL_EXTI_GPIO_Init(EXTI_CONFIG *EXTI_config){

	// 1-Configure GPIO to AF input (Floating input)
	GPIO_PIN_CONFIG_t GPIO_cfg;
	GPIO_cfg.GPIO_MODE=GPIO_MODE_AF_INPUT;
	GPIO_cfg.GPIO_PinNumber=EXTI_config->EXTI_PORT_PIN.GPIO_PIN;
	MCAL_GPIO_init(EXTI_config->EXTI_PORT_PIN.GPIO_PORT,&GPIO_cfg);


	// 2- Update AFIO to route between EXTI Line with Port A,B,C,D
	uint8_t AFIO_EXTICR_Index = EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM/4;
	uint8_t AFIO_EXTICR_Position = 4*(EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM%4);

	// Clear the four bit
	AFIO->EXTICR[AFIO_EXTICR_Index]&=~(0xf<<AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index]|=(AFIO_GPIO_EXTI_Mapping_PORT(EXTI_config->EXTI_PORT_PIN.GPIO_PORT)&0xf)<<AFIO_EXTICR_Position;

	// 3- Update Rising and Falling Edge
	if (EXTI_config->TRIGGER==EXTI_Rising_Edge)
	{
		EXTI->RTSR|=1<<EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
	}
	else if (EXTI_config->TRIGGER==EXTI_Falling_Edge)
	{
		EXTI->FTSR|=1<<EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
	}
	else if (EXTI_config->TRIGGER==EXTI_Rising_Falling)
	{
		EXTI->RTSR|=1<<EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
		EXTI->FTSR|=1<<EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
	}

	// 4- Update IRQ Handling Call Back
	GP_IRQ_CallBack[EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM] = EXTI_config->P_IRQ_CallBack;

	// 5- Enable/Disable IRQ EXTI & NVIC
	if (EXTI_config->IRQ_EN==EXTI_IRQ_Enable)
	{
		EXTI->IMR|=1<<EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM;
		Enable_NVIC(EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM);
	}
	else{
		EXTI->IMR&=~(1<<EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM);
		Disable_NVIC(EXTI_config->EXTI_PORT_PIN.EXTI_INPUT_LINE_NUM);
	}
}

/* @Fn					 -MCAL_EXTI_GPIO_DeInit
 * @brief 				 -reset all the EXTI registers
 * @retval				 - none
 * Note                  - none
 */
void MCAL_EXTI_GPIO_DeInit(void){

	//reset all registers values
	EXTI->IMR=0x00000000;
	EXTI->FTSR=0x00000000;
	EXTI->IMR=0x00000000;
	EXTI->RTSR=0x00000000;
	EXTI->SWIER=0x00000000;
	EXTI->PR=0x0FFFFFFFF;


	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}
/**================================================================
 * @Fn					 	-MCAL_EXTI_GPIO_Update
 * @brief 				 	-Update the EXTI GPIOx PINy peripheral
 * @param [in] 			 	-EXTI_config pointer to a EXTI_CONFIG structure that contains
 * 						   	the configuration information
 * @retval				 	-none
 * Note-					-none
 */
void MCAL_EXTI_GPIO_Update(EXTI_CONFIG *EXTI_config){
	MCAL_EXTI_GPIO_Init(EXTI_config);
}
