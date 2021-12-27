/*
 * timer_registers.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Mahmoud
 */

#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

#define TCCR0_REG  *((volatile char*)(0x53))
#define TCNT0_REG  *((volatile char*)(0x52))
#define OCR0_REG   *((volatile char*)(0x5C))
#define TIMSK_REG  *((volatile char*)(0x59))
#define TIFR_REG   *((volatile char*)(0x58))


#endif /* TIMER_REGISTERS_H_ */
