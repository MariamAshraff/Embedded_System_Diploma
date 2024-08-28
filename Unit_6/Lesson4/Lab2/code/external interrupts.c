#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LED.h"
#include "button.h"
#include "std_macros.h"

int main(void)
{
	LED_vInit('D',7); 
	DIO_vconnectpullup('D',2,1);
	button_vInit('D',2);
	sei(); // to open global interrupt bit (I-bit)
	SET_BIT(MCUCR,ISC00); // to select rising & falling edge mode
	CLR_BIT(MCUCR,ISC01);

	SET_BIT(GICR,INT0);

	while(1)
	{
		
	}
}

ISR(INT0_vect)
{
	LED_vTurnOn('D',7); 
	_delay_ms(1000); 
	LED_vTurnOff('D',7);
}

