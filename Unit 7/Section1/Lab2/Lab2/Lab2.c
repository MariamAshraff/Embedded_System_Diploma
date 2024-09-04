/*
 * Lab2.c
 *
 * Created: 9/4/2024 12:33:43 PM
 *  Author: VTE
 */ 


#include "std_macros.h"
#include "MemoryMap.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

int main(void)
{
	// pin D0 INPUT
	CLR_BIT(DDRD,0);
	// pin D4 OUTPUT
	SET_BIT(DDRD,4);
	while(1)
	{
		if(READ_BIT(PIND,0)==1)
		{
			SET_BIT(PORTD,4);
			_delay_ms(1000);
			CLR_BIT(PORTD,4);
		}
	}
}