/*
 * showled7seg.c
 *
 *  Created on: Apr 8, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int so[13] = { 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x7F,0xFF,0xBF };

void showled(int a, int b)
{
	P2OUT = so[a];
	P1OUT |= b;
	__delay_cycles(5000);
	P1OUT &=~ b;
}




