/*
 * lab2g.c
 *
 *  Created on: Apr 7, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int soog[10] = { 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 };

void show(int a, int t)
{
	P2OUT = soog[a];
	P1OUT = t;
	__delay_cycles(10000);
	P1OUT &=~ t;
}
int lab2g(void){
	P1DIR |= 0xF0;
	P1REN |= 0x04;	////PxREN = 0; Pullup/pulldown resistor disable
					////PxREN = 1; Pullup/pulldown resistor enabled
	P2DIR |= 0xFF;
	P2SEL = 0;
	P2OUT &=~ 0xFF;
	int a =0, dem =0;
		while(1){
			if(!(P1IN & 0x04)){
				if(++dem==10)
				{
					dem=0;
					a++;
					if(a == 99) a=0;
				}
				show(a/10,T1);
				show(a%10,T2);
			}
			show(a/10,T1);
			show(a%10,T2);
		}
}



