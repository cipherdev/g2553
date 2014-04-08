/*
 * lab2f.c
 *
 *  Created on: Apr 7, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int lab2f(void)
{
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
		showled(i/1000,T1);
		n=i%1000;
		showled(n/100,T2);
		n=i%100;
		showled(n/10,T3);
		showled(i%10,T4);
	}
}


