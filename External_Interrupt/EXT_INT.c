/*
 * EXT_INT.c
 *
 *  Created on: Dec 17, 2021
 *      Author: Abdurrahman Mohamed
 */
#include<avr/interrupt.h>
#include"dio_registers.h"
#include"int_registers.h"
#include"bit_math.h"

void INT0_init();

ISR(INT0_vect)
{
	TOGGLE_BIT(DDRB_REG,0);
}

int main()
{
	INT0_init();

	/*set PB0 as output and clear it*/
	SET_BIT(DDRB_REG,0);
	SET_BIT(PORTB_REG,0);


	while(1)
	{

	}
	return 0;
}


void INT0_init()
{
	CLR_BIT(STATUS_REG,7);

	CLR_BIT(DDRA_REG,0);
	SET_BIT(PORTA_REG,0);

	SET_BIT(GICR_REG,6);

	SET_BIT(MCUCR_REG,1);
	SET_BIT(MCUCR_REG,0);

	SET_BIT(STATUS_REG,7);


}
