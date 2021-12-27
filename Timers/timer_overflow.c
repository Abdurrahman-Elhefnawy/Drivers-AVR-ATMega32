/*
 * timer_overflow.c
 *
 *  Created on: Aug 31, 2021
 *      Author: Abdurrahman Mohamed
 */
#include<avr/interrupt.h>
#include"dio_interface.h"
#include"int_registers.h"
#include"timer_registers.h"

#define F_CPU 1000000UL

/* Description :
 * A program to increment the number displayed on a 7 segment every 0.5 second
 * we used Timer0 in Normal (Overflow) mode to control the 7 segment
 * used 1MHz clock and a prescaler = 1024 so every count takes 1ms and every overflow takes 256 ms
 * so we need timer to overflow 4 times to get a second
 */


#define NUMBER_OF_OVF_PER_SECOND 4
u8 output_value=0;


void timer_init(void);


ISR(TIMER0_OVF_vect)
{
	static u8 ticks = 0 ;
	ticks++;
	if(ticks==NUMBER_OF_OVF_PER_SECOND)
	{
		output_value++;
		if(output_value==10)
			output_value=0;
		ticks=0;
	}
}

int main()
{
    DIO_setPortDirection(PORT_C , OUTPUT);   // configure PORTC pins as output
    DIO_setPortValue(PORT_C , 0);  			 // initialize all PORTC pins as low so the 7-segment displays 0 at first

	timer_init();   //timer configuration

	while(1)
	{
		DIO_setPortValue(PORT_C , output_value);
//		PORTC_REG=output_value;
	}

	return 0;
}


void timer_init(void)
{
	SET_BIT(STATUS_REG,7);	//Enable global interrupt pin
	TCNT0_REG=0;			//initialize the counter
	SET_BIT(TIMSK_REG,0);	//Enable Overflow interrupt

	/* Configure the timer control register*/
	SET_BIT(TCCR0_REG,7);	// Non PWM mode FOC0=1
	SET_BIT(TCCR0,0);		//prescaler =(1024) CS00=1 CS01=0 CS02=1
	SET_BIT(TCCR0,2);		//prescaler =(1024) CS00=1 CS01=0 CS02=1

}
