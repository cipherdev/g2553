/*
 * lab2e.c
 *
 *  Created on: Apr 6, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int lab2e(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	P1DIR |= 0xF0;
	P1OUT =0;
	P2SEL = 0;
	P2DIR |=0xFF;
	P2OUT = 0;
	while(1){
		showled(2,T1);
		showled(0,T2);
		showled(1,T3);
		showled(4,T4);
	}
}




