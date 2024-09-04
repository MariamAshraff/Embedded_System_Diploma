/*
 * main.c
 *
 * Created: 9/4/2024 12:11:26 PM
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
	// pin D5,D6,D7 OUTPUT
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
    while(1)
    {
		if(READ_BIT(PIND,0)==1)
		{
			SET_BIT(PORTD,5);
			_delay_ms(3000);
			SET_BIT(PORTD,6);
			_delay_ms(3000);
			SET_BIT(PORTD,7);
			_delay_ms(3000);
			CLR_BIT(PORTD,7);
			_delay_ms(3000);
			CLR_BIT(PORTD,6);
			_delay_ms(3000);
			CLR_BIT(PORTD,5);
			_delay_ms(3000);
		}			
    }
}