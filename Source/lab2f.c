/*
 * lab2f.c
 *
 *  Created on: Apr 7, 2014
 *      Author: Anh
 */
#include "control.h"

int sog[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void outleb(int a, int leb)
{
	P2OUT = sog[a];
	P1OUT = leb;
	__delay_cycles(5000);
	P1OUT &=~leb;
}
int lab2f(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	P1DIR = 0xF0;
	P2DIR |= 0xFF;
	P2SEL = 0;
	P2OUT = 0x00;
	int i=0,dem=0,n;
	while(1){
		if(++dem==10)
		{
			dem=0;
			i++;
			if(i == 9999){
				i=0;
			}
		}
		outleb(i/1000,T1);
		n=i%1000;
		outleb(n/100,T2);
		n=i%100;
		outleb(n/10,T3);
		outleb(i%10,T4);
	}
}


