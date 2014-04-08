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
		__delay_cycles(500000); // MSP430 chay voi tan so xung clock noi là (a)Mhz(a=1,2,4,8,16 ...)
								// thi lenh _delay_cycles(1000000); >>> 1000000/(a*10^6) giayy >>> delay 1s
		P2OUT |= 0xAA;
		P2OUT &=~ 0x55;
		__delay_cycles(500000);
	}
}




