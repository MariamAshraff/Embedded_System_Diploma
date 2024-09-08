/*
 * STM32F103CX6.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Mariam Ashraf
 */

#ifndef INC_STM32F103CX6_H_
#define INC_STM32F103CX6_H_



//----------------------------
//Includes
//----------------------------
#include "stdlib.h"
#include <stdint.h>

//----------------------------
//Base addresses for Memories
//----------------------------

#define FLASH_MEMORY_BASE						0x08000000UL
#define SYSTEM_MEMORY_BASE						0x1FFFF000UL
#define SRAM_MEMORY_BASE						0x20000000UL


#define PRIPHERALS_BASE							0x40000000UL
#define CORETEX_M3_INTERNAL_PRIPHERALS_BASE		0xE0000000UL

//----------------------------
//Base addresses for BUS Peripherals
//----------------------------

/***********Base addresses for AHB Peripherals***************/
#define RCC_BASE								 0x40021000UL

/***********Base addresses for APB2 Peripherals*************/

// GPIO

// A&B Fully included in LQFP48 Package

#define GPIOA_BASE								 0x40010800UL
#define GPIOB_BASE								 0x40010C00UL

// C&D Partial included in LQFP48 Package
#define GPIOC_BASE								 0x40011000UL
#define GPIOD_BASE								 0x40011400UL

// E not included LQFP48 Package
#define GPIOE_BASE								 0x40011800UL


#define EXTI_BASE								 0x40010400UL
#define AFIO_BASE								 0x40010000UL


//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register
//-*-*-*-*-*-*-*-*-*-*-*

/***********************Peripheral registers:GPIO**************************/
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_TypeDef;

/***********************Peripheral registers:RCC***************************/
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;

}RCC_TypeDef;

/***********************Peripheral registers:EXTI**************************/
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_TypeDef;


/***********************Peripheral registers:AFIO**************************/
typedef struct
{
	volatile uint32_t 	EVCR ;
	volatile uint32_t 	MAPR ;
	volatile uint32_t 	EXTICR1;
	volatile uint32_t 	EXTICR2 ;
	volatile uint32_t 	EXTICR3 ;
	volatile uint32_t 	EXTICR4 ;
	volatile uint32_t 	EXTICR5 ;
	uint32_t 			RESERVED; // 0x18
	volatile uint32_t 	MAPR2 ;   // 0x1C

}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

/***********************Peripheral Instants:GPIO**************************/
#define GPIOA 				((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB 				((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC 				((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD 				((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE 				((GPIO_TypeDef*)GPIOE_BASE)

/***********************Peripheral Instants:RCC***************************/
#define RCC 				((RCC_TypeDef*)RCC_BASE)

/***********************Peripheral Instants:AFIO**************************/
#define AFIO 				((AFIO_TypeDef*)AFIO_BASE)

/***********************Peripheral Instants:EXTI**************************/
#define EXTI 				((EXTI_TypeDef*)EXTI_BASE)

//-*-*-*-*-*-*-*-*-*-*-*
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

/***********************clock enable Macros:GPIO**************************/
#define RCC_GPIOA_CLOCK_ENABLE()  	(RCC->APB2ENR|=1<<2)
#define RCC_GPIOB_CLOCK_ENABLE()  	(RCC->APB2ENR|=1<<3)
#define RCC_GPIOC_CLOCK_ENABLE()  	(RCC->APB2ENR|=1<<4)
#define RCC_GPIOD_CLOCK_ENABLE()  	(RCC->APB2ENR|=1<<5)
#define RCC_GPIOE_CLOCK_ENABLE()  	(RCC->APB2ENR|=1<<6)

/***********************clock enable Macros:AFIO**************************/
#define RCC_AFIO_CLOCK_ENABLE()  	(RCC->APB2ENR|=1<<0)

//-*-*-*-*-*-*-*-*-*-*-*
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*




#endif /* INC_STM32F103CX6_H_ */
