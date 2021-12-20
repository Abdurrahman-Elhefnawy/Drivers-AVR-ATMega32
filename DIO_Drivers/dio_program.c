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
	case PORTA:  					
		if(pinDirection == OUTPUT)
			SET_BIT(DDRA_REG,pinNumber);
		else if(pinDirection == INPUT)
			CLR_BIT(DDRA_REG,pinNumber);
		break;
	case PORTB:
		if(pinDirection == OUTPUT)
			SET_BIT(DDRB_REG,pinNumber);
		else if(pinDirection == INPUT)
			CLR_BIT(DDRB_REG,pinNumber);
		break;
	case PORTC:
		if(pinDirection == OUTPUT)
			SET_BIT(DDRC_REG,pinNumber);
		else if(pinDirection == INPUT)
			CLR_BIT(DDRC_REG,pinNumber);
		break;
	case PORTD:
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
	case PORTA:
		if(pinValue == HIGH)
			SET_BIT(PORTA_REG,pinNumber);
		else if(pinValue == LOW)
			CLR_BIT(PORTA_REG,pinNumber);
		break;
	case PORTB:
		if(pinValue == HIGH)
			SET_BIT(PORTB_REG,pinNumber);
		else if(pinValue == LOW)
			CLR_BIT(PORTB_REG,pinNumber);
		break;
	case PORTC:
		if(pinValue == HIGH)
			SET_BIT(PORTC_REG,pinNumber);
		else if(pinValue == LOW)
			CLR_BIT(PORTC_REG,pinNumber);
		break;
	case PORTD:
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
	case PORTA:
			SET_BIT(PORTA_REG,pinNumber);
		break;
	case PORTB:
			SET_BIT(PORTB_REG,pinNumber);
		break;
	case PORTC:
			SET_BIT(PORTC_REG,pinNumber);
		break;
	case PORTD:
			SET_BIT(PORTD_REG,pinNumber);
		break;
	}

}




void DIO_setPortDirection(u8 portNumber , u8 portDirection)
{
	switch(portNumber)
	{
	case PORTA:
		if(portDirection == OUTPUT)
			SET_PORT_VALUE(DDRA_REG,0xFF);
		else if(portDirection == INPUT)
			CLR_PORT(DDRA_REG);
		break;
	case PORTB:
		if(portDirection == OUTPUT)
			SET_PORT_VALUE(DDRB_REG,0xFF);
		else if(portDirection == INPUT)
			CLR_PORT(DDRB_REG);
		break;
	case PORTC:
		if(portDirection == OUTPUT)
			SET_PORT_VALUE(DDRC_REG,0xFF);
		else if(portDirection == INPUT)
			CLR_PORT(DDRC_REG);
		break;
	case PORTD:
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
	case PORTA:
		if(portValue)
			SET_PORT_VALUE(PORTA_REG,portValue);
		else if(portValue == LOW)
			CLR_PORT(PORTA_REG);
		break;
	case PORTB:
		if(portValue)
			SET_PORT_VALUE(PORTB_REG,portValue);
		else if(portValue == LOW)
			CLR_PORT(PORTB_REG);
		break;
	case PORTC:
		if(portValue)
			SET_PORT_VALUE(PORTC_REG,portValue);
		else if(portValue == LOW)
			CLR_PORT(PORTC_REG);
		break;
	case PORTD:
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
		case PORTA:
			return BIT_IS_SET(PINA_REG,pinNumber);
		case PORTB:
			return BIT_IS_SET(PINB_REG,pinNumber);
		case PORTC:
			return BIT_IS_SET(PINC_REG,pinNumber);
		case PORTD:
			return BIT_IS_SET(PIND_REG,pinNumber);
		}
return 0 ;
}
