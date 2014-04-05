/*
 * lab2c.c
 *
 *  Created on: Apr 6, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int lab2c(void){
	P2DIR |= 0xFF;
	P2SEL = 0;
	P2OUT &=~ 0xFF;
	while(1)
	{
		P2OUT |= 0x55;
		P2OUT &=~ 0xAA;
		__delay_cycles(500000);
		P2OUT |= 0xAA;
		P2OUT &=~ 0x55;
		__delay_cycles(500000);
	}
}




