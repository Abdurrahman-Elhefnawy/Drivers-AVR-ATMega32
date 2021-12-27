/*
 * dio_interface.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Abdurrahman Mohamed
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include"bit_math.h"
#include"dio_registers.h"
#include "std_types.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define TRUE 1
#define FALSE 0

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void DIO_setPinDirection(u8 portNumber , u8 pinNumber , u8 pinDirection);

void DIO_setPinDirection(u8 portNumber , u8 pinNumber , u8 pinDirection);

void DIO_setInternalPullUp(u8 portNumber , u8 pinNumber);

void DIO_setPortDirection(u8 portNumber , u8 portDirection);

void DIO_setPortValue(u8 portNumber , u8 portValue);

u8 DIO_getPinValue(u8 portNumber , u8 pinNumber );

#endif /* DIO_INTERFACE_H_ */
