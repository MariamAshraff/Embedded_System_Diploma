/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include "stdint.h"
#include "stdio.h"


//GPIO_A
#define GPIOA_BASE     0x40010800
#define GPIOA_CRH     *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL     *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR     *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR	  *(volatile uint32_t *)(GPIOA_BASE + 0x08)

//GPIO_B
#define GPIOB_BASE      0x40010C00
#define GPIOB_CRH     *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL     *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR     *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR	  *(volatile uint32_t *)(GPIOB_BASE + 0x08)

//RCC
#define RCC_BASE       0x40021000
#define RCC_APB2ENR   *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR      *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR        *(volatile uint32_t *)(RCC_BASE + 0x00)

//EXTI
#define EXTI_BASE      0x40010400
#define EXTI_IMR      *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR     *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR       *(volatile uint32_t *)(EXTI_BASE + 0x14)

//AFIO
#define AFIO_BASE       0x40010000
#define AFIO_EXTICR1   *(volatile uint32_t *)(AFIO_BASE + 0x08)

//NVIC
#define NVIC_BASE       0xE000E100
#define NVIC_EXTIE0   *(volatile uint32_t *)(NVIC_BASE + 0x00)

#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)    (reg&(1<<bit))>>bit
void delay(unsigned int x){

	unsigned int i ,j ;
	for(i=0; i<x; i++)
		for(j=0; j<256; j++);
}


void Clock_Init()
{
	SET_BIT(RCC_APB2ENR,2);
	SET_BIT(RCC_APB2ENR,3);
	//RCC_APB2ENR |=(1<<2); //I/O port A clock enable
	//RCC_APB2ENR |=(1<<3); // I/O port B clock enable
}

void GPIO_Init()
{
	//set port A pin 13 as input floating
	GPIOA_CRH |=(0b00<<20);
	GPIOA_CRH |=(0b01<<22);
	//set port A pin 1 as input floating
	GPIOA_CRL |=(0b00<<4);
	GPIOA_CRL |=(0b01<<6);
	//set port B pin 1 as output mode (push-pull),max speed 10MHZ
	GPIOB_CRL |=(0b01<<4);
	GPIOB_CRL |=(0b00<<6);
	// set portB pin 13 as output mode(push-pull),max speed 10MHZ
	GPIOB_CRH |=(0b01<<20);
	GPIOB_CRH |=(0b00<<22);
}

int main(void)
{
	Clock_Init();
	GPIO_Init();

	while(1)
	{
		if(READ_BIT(GPIOA_IDR,1)==0)  //single pressing
		{
			TOG_BIT(GPIOB_ODR,1);
			while(READ_BIT(GPIOA_IDR,1)==0);
		}
		if(READ_BIT(GPIOA_IDR,13)==1) //multi pressing
		{
			TOG_BIT(GPIOB_ODR,13);
		}
		delay(3);

	}
}
