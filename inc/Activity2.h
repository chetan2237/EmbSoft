/*
 */
#ifndef __ACTIVITY2_H_
#define __ACTIVITY2_H_





#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>

void InitADC();

uint16_t ReadADC(uint8_t ch);
#endif /** __Activity2_H_ */