/*
 * showled7seg.c
 *
 *  Created on: Apr 8, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int so[10] = { 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 };

void showled(int a, int b)
{
	P2OUT = so[a];
	P1OUT = b;
	__delay_cycles(5000);
	P1OUT &=~ b;
}




