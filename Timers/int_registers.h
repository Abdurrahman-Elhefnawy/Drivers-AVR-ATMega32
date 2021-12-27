/*
 * int_registers.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Mahmoud
 */

#ifndef INT_REGISTERS_H_
#define INT_REGISTERS_H_


/*Interrupt registers addresses*/
#define STATUS_REG *((volatile char*)0x5F)
#define GICR_REG *((volatile char*)0x5B)
#define MCUCR_REG *((volatile char*)0x55)


#endif /* INT_REGISTERS_H_ */
