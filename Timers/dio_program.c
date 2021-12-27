/*
 * dio_program.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Abdurrahman Mohamed
 */
#include"dio_interface.h"


void DIO_setPinDirection(u8 portNumber , u8 pinNumber, u8 pinDirection)
{
	switch(portNumber)
	{
	case PORT_A:
		if(pinDirection == OUTPUT)
			SET_BIT(DDRA_REG,pinNumber);
		else if(pinDirection == INPUT)
			CLR_BIT(DDRA_REG,pinNumber);
		break;
	case PORT_B:
		if(pinDirection == OUTPUT)
			SET_BIT(DDRB_REG,pinNumber);
		else if(pinDirection == INPUT)
			CLR_BIT(DDRB_REG,pinNumber);
		break;
	case PORT_C:
		if(pinDirection == OUTPUT)
			SET_BIT(DDRC_REG,pinNumber);
		else if(pinDirection == INPUT)
			CLR_BIT(DDRC_REG,pinNumber);
		break;
	case PORT_D:
		if(pinDirection == OUTPUT)
			SET_BIT(DDRD_REG,pinNumber);
		else if(pinDirection == INPUT)
			CLR_BIT(DDRD_REG,pinNumber);
		break;
	}
}



void DIO_setPinValue(u8 portNumber , u8 pinNumber , u8 pinValue)
{
	switch(portNumber)
	{
	case PORT_A:
		if(pinValue == HIGH)
			SET_BIT(PORTA_REG,pinNumber);
		else if(pinValue == LOW)
			CLR_BIT(PORTA_REG,pinNumber);
		break;
	case PORT_B:
		if(pinValue == HIGH)
			SET_BIT(PORTB_REG,pinNumber);
		else if(pinValue == LOW)
			CLR_BIT(PORTB_REG,pinNumber);
		break;
	case PORT_C:
		if(pinValue == HIGH)
			SET_BIT(PORTC_REG,pinNumber);
		else if(pinValue == LOW)
			CLR_BIT(PORTC_REG,pinNumber);
		break;
	case PORT_D:
		if(pinValue == HIGH)
			SET_BIT(PORTD_REG,pinNumber);
		else if(pinValue == LOW)
			CLR_BIT(PORTD_REG,pinNumber);
		break;
	}

}


void DIO_setInternalPullUp(u8 portNumber , u8 pinNumber)
{
	switch(portNumber)
	{
	case PORT_A:
			SET_BIT(PORTA_REG,pinNumber);
		break;
	case PORT_B:
			SET_BIT(PORTB_REG,pinNumber);
		break;
	case PORT_C:
			SET_BIT(PORTC_REG,pinNumber);
		break;
	case PORT_D:
			SET_BIT(PORTD_REG,pinNumber);
		break;
	}

}




void DIO_setPortDirection(u8 portNumber , u8 portDirection)
{
	switch(portNumber)
	{
	case PORT_A:
		if(portDirection == OUTPUT)
			SET_PORT_VALUE(DDRA_REG,0xFF);
		else if(portDirection == INPUT)
			CLR_PORT(DDRA_REG);
		break;
	case PORT_B:
		if(portDirection == OUTPUT)
			SET_PORT_VALUE(DDRB_REG,0xFF);
		else if(portDirection == INPUT)
			CLR_PORT(DDRB_REG);
		break;
	case PORT_C:
		if(portDirection == OUTPUT)
			SET_PORT_VALUE(DDRC_REG,0xFF);
		else if(portDirection == INPUT)
			CLR_PORT(DDRC_REG);
		break;
	case PORT_D:
		if(portDirection == OUTPUT)
			SET_PORT_VALUE(DDRD_REG,0xFF);
		else if(portDirection == INPUT)
			CLR_PORT(DDRD_REG);
		break;
	}
}



void DIO_setPortValue(u8 portNumber , u8 portValue)
{
	switch(portNumber)
	{
	case PORT_A:
		if(portValue)
			SET_PORT_VALUE(PORTA_REG,portValue);
		else if(portValue == LOW)
			CLR_PORT(PORTA_REG);
		break;
	case PORT_B:
		if(portValue)
			SET_PORT_VALUE(PORTB_REG,portValue);
		else if(portValue == LOW)
			CLR_PORT(PORTB_REG);
		break;
	case PORT_C:
		if(portValue)
			SET_PORT_VALUE(PORTC_REG,portValue);
		else if(portValue == LOW)
			CLR_PORT(PORTC_REG);
		break;
	case PORT_D:
		if(portValue)
			SET_PORT_VALUE(PORTD_REG,portValue);
		else if(portValue == LOW)
			CLR_PORT(PORTD_REG);
		break;
	}
}



u8 DIO_getPinValue(u8 portNumber , u8 pinNumber )
{
	switch(portNumber)
		{
		case PORT_A:
			return BIT_IS_SET(PINA_REG,pinNumber);
		case PORT_B:
			return BIT_IS_SET(PINB_REG,pinNumber);
		case PORT_C:
			return BIT_IS_SET(PINC_REG,pinNumber);
		case PORT_D:
			return BIT_IS_SET(PIND_REG,pinNumber);
		}
return 0 ;
}
