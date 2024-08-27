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
typedef volatile unsigned int vuint32_t ;
 #include <stdint.h>
 #include <stdlib.h>
 #include <stdio.h>
#define GPIOA_BASE     0x40010800
#define GPIOA_CRH     *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR     *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE       0x40021000
#define RCC_APB2ENR   *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR      *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR        *(volatile uint32_t *)(RCC_BASE + 0x00)
int main(void)
 {
	/* Bit 2 IOPAEN: I/O port A clock enable
	 Set and cleared by software.
	 0: I/O port A clock disabled
	 1:I/O port A clock enabled
	 */


	RCC_CFGR |=(0b0110<<18); //  PLL input clock x 8

	RCC_CFGR |=(0b101<<11);
	RCC_CFGR |=(0b100<<8);

	RCC_CFGR |=(0b10<<0); //  PLL selected as system clock



	RCC_CR |=(1<<24); // enable PLL

	RCC_APB2ENR |=(1<<2);

	 GPIOA_CRH   &= 0xFF0FFFFF;
	 GPIOA_CRH   |= 0x00200000;
	 while(1)
	 {
		 GPIOA_ODR |=  1<<13 ;
		 for (int i = 0; i < 5000; i++); // arbitrary delay
		 GPIOA_ODR  &=  ~(1<<13) ;
		 for (int i = 0; i < 5000; i++); // arbitrary delay
	 }
 }
