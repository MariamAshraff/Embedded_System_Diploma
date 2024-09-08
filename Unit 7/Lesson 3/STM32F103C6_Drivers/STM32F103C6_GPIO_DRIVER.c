/*
 * STM32F103C6_GPIO_DRIVER.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Mariam Ashraf
 */
#include "STM32F103C6_GPIO_DRIVER.h"
#include "math.h"
uint8_t Get_CRLH_Position(uint16_t PinNumber)
{

//	uint8_t x=0;
//	//log2(PinNumber);
//	while (PinNumber>1)
//	{
//		PinNumber/=2;
//		x++;
//	}
//	if (x < GPIO_PIN_8)
//		return  x;
//	else
//		return  (x-8);
	switch (PinNumber)
	{
		case GPIO_PIN_0 :
			return 0;
			break;
		case GPIO_PIN_1 :
			return 4;
			break;
		case GPIO_PIN_2 :
			return 8 ;
			break;
		case GPIO_PIN_3 :
			return 12;
			break;
		case GPIO_PIN_4 :
			return 16;
			break;
		case GPIO_PIN_5 :
			return 20;
			break;
		case GPIO_PIN_6 :
			return 24;
			break;
		case GPIO_PIN_7 :
			return 28;
			break;
		case GPIO_PIN_8 :
			return 0;
			break;
		case GPIO_PIN_9 :
			return 4;
			break;
		case GPIO_PIN_10 :
			return 8 ;
			break;
		case GPIO_PIN_11 :
			return 12;
			break;
		case GPIO_PIN_12 :
			return 16;
			break;
		case GPIO_PIN_13 :
			return 20;
			break;
		case GPIO_PIN_14 :
			return 24;
			break;
		case GPIO_PIN_15 :
			return 28;
			break;
	}

}


/**================================================================
 * @Fn					 	-MCAL_GPIO_init
 * @brief 				 	-initializes the GPIOx PINy peripheral according to specified parameters in the PinConfig
 * @param [in] 			 	-GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @param [in] 			 	-PinConfig pointer to a GPIO_PIN_CONFIG_t structure that contains
 * 						   	the configuration information for the specified GPIO PIN
 * @retval				 	-none
 * Note-					-none
 */
void MCAL_GPIO_init(GPIO_TypeDef *GPIOx, GPIO_PIN_CONFIG_t* PinConfig){
	volatile uint32_t *ConfigRegister= NULL;
	uint8_t pin_config=0;
	//Specify config register( CRL OR CRH )
	ConfigRegister=(PinConfig->GPIO_PinNumber <GPIO_PIN_8? &GPIOx->CRL : &GPIOx->CRH);

	// clear CNF[1:0] MODE[1:0]
	*ConfigRegister&=~(0xf<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//check if mode is output
	if (PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_AF_OD||PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_AF_PP||PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_OD||PinConfig->GPIO_MODE==GPIO_MODE_OUTPUT_PP)
	{
		//*ConfigRegister|=(PinConfig->GPIO_Output_Speed>>Get_CRLH_Position(PinConfig->GPIO_PinNumber));
		pin_config=((PinConfig->GPIO_Output_Speed | ((PinConfig->GPIO_MODE)- 4 << 2))&0x0f);
	}
	// if input
	else
	{
		pin_config=(((PinConfig->GPIO_MODE)<< 2)&0x0f);
		if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
		{
			//Table 20. Port bit configuration table PxODR register 1
			GPIOx->ODR |= PinConfig->GPIO_PinNumber;
		}
		else if( PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PD)
		{
			//Table 20. Port bit configuration table PxODR register 0
			GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
		}

	}
	*ConfigRegister|=(pin_config<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}
/**==================================================================================================
 * @Fn					 -MCAL_GPIO_DeInit
 * @brief 				 -reset all the GPIOx registers
 * @param [in] 			 -GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @retval				 - none
 * Note                  - none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx){
	//Reset using reset controller by setting then resetting
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |=(1<<2); // Bit 2 IOPARST : IO port A reset
		RCC->APB2RSTR &= ~(1<<2);

	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=(1<<3); // Bit 3 IOPARST : IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=(1<<4);  //// Bit 4 IOPARST : IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |=(1<<5);  //// Bit 5 IOPARST : IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}
}


/**================================================================
 * @Fn					 -MCAL_GPIO_ReadPin
 * @brief 				 -Read Specific PIN
 * @param [in] 			 -GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @param [in]			 -PinNumber set pin number according to @ref GPIO_PINS_define
 * @retval				 - the input PIN value (two values based on @ref GPIO_PIN_State)
 * Note                  - none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber){
	if (((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		return GPIO_PIN_SET;
	}
	else
	{
		return GPIO_PIN_RESET;
	}
}

/**================================================================
 * @Fn					 -MCAL_GPIO_ReadPort
 * @brief 				 -Read Specific Port
 * @param [in] 			 -GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @param [in]			 -PinNumber set pin number according to @ref GPIO_PINS_define
 * @retval				 - the input Port value
 * Note                  - none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx){
	uint16_t port_value;
	port_value =(uint16_t)(GPIOx->IDR);
	return port_value;
}
/**================================================================
 * @Fn					 -MCAL_GPIO_WritePin
 * @brief 				 -write on Specific output Pin
 * @param [in] 			 -GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @param [in]			 -PinNumber set pin number according to @ref GPIO_PINS_define
 * @param [in]			 -value : Pin value
 * @retval				 - none
 * Note                  - none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber,uint8_t value){
	if ( value != GPIO_PIN_RESET)
	  {
		 // GPIOx->ODR |=PinNumber;
		 GPIOx->BSRR =(uint32_t)PinNumber;
	  }
	else
	  {
		  GPIOx->BRR =(uint32_t)PinNumber;
	  }
}
/**================================================================
 * @Fn					 -MCAL_GPIO_WritePort
 * @brief 				 -Write on Specific output Port
 * @param [in] 			 -GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @param [in]			 -value : Port value
 * @retval				 - none
 * Note                  - none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t value){
	GPIOx->ODR =(uint32_t)value;
}
/**================================================================
 * @Fn					 -MCAL_GPIO_TogglePin
 * @brief 				 -Toggle Specific output Pin
 * @param [in] 			 -GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @param [in]			 -PinNumber set pin number according to @ref GPIO_PINS_define
 * @retval				 - none
 * Note                  - none
 */

void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}
/**================================================================
 * @Fn					 -MCAL_GPIO_LockPin
 * @brief 				 -The locking mechanism allows the IO configuration to be frozen
 * @param [in] 			 -GPIOx : where x can be (A..D depend on device used) to select the GPIO peripheral
 * @param [in]			 -PinNumber set pin number according to @ref GPIO_PINS_define
 * @retval				 -Ok if pin config is locked or ERROR if pin not Loced (Ok and ERROR are defined @ref GPIO_RETURN_LOCK)
 * Note                  -none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber){

	volatile uint32_t tmp =1<<16;
	//set specific bit  LCKy
	 tmp |=PinNumber;
	 //Write 1
	 GPIOx->LCKR =tmp;
	 //Write 0
	 GPIOx->LCKR =PinNumber;
	 //Write 1
	 GPIOx->LCKR =tmp;
	 //Read 0
	 tmp= GPIOx->LCKR;
	 //Read 1 (this read is optional but confirms that the lock is active)
	 if((uint32_t)(GPIOx->LCKR & 1<<16 ))
	 {
		 return GPIO_RETURN_LOCK_Enabled;
	 }
	 else
	 {
		 return GPIO_RETURN_LOCK_ERROR;
	 }
}
