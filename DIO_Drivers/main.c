/*
 * main.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Abdurrahman Mohamed
 */
#include"dio_interface.h"
#include"util/delay.h"
int main()
{

	DIO_setPortDirection(PORTA ,INPUT);
	DIO_setInternalPullUp(PORTA ,5);

	DIO_setPortDirection(PORTB ,OUTPUT);
	DIO_setPortDirection(PORTC ,OUTPUT);
	DIO_setPortDirection(PORTD ,OUTPUT);

//	for(int i =0 ;i<8;i++)
//	{
//		DIO_setPinDirection(PORTC ,i,OUTPUT);
//	}



	while(1)
	{



		 DIO_setPortValue(PORTB , 0);
		 DIO_setPortValue(PORTC , 20);
		 DIO_setPortValue(PORTD , 0xF0);

		 _delay_ms(20);

		 if(!DIO_getPinValue(PORTA ,5))
		 {
			 _delay_ms(20);
			 if(!DIO_getPinValue(PORTA ,5))
			 {
				 DIO_setPortValue(PORTC,0x08);
			 }

			 while(!DIO_getPinValue(PORTA ,5));
		 }


//		 for(int i =0 ;i<8;i++)
//		 	{
//		 		DIO_setPinValue(PORTB ,i,OUTPUT);
//		 		_delay_ms(200);
//		 	}
//		 for(int i =0 ;i<8;i++)
//		 	{
//		 		DIO_setPinValue(PORTC ,i,OUTPUT);
//		 		_delay_ms(200);
//		 	}
//		 for(int i =0 ;i<8;i++)
//		 	{
//		 		DIO_setPinValue(PORTD ,i,OUTPUT);
//		 		_delay_ms(200);
//		 	}

	}

	return 0;
}
