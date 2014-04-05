/*
 * lab2e.c
 *
 *  Created on: Apr 6, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int so[4]={0xA4, 0xC0, 0xF9, 0x99};
void showled(int a, int b)
{
	P2OUT = so[a];
	P1OUT = b;
	P1OUT &=~ b;
}
int lab2e(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	P1DIR |= 0xF0;
	P1OUT =0;
	P2SEL = 0;
	P2DIR |=0xFF;
	P2OUT = 0;
	while(1){
		showled(0,T1);
		showled(1,T2);
		showled(2,T3);
		showled(3,T4);
	}
}




