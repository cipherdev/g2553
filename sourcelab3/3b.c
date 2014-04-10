/*
 * lab3b.c
 *
 *  Created on: Apr 8, 2014
 *      Author: Anh Huy
 */
#include "msp430g2553.h"

int so[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
int i = 0;
void showled(int a, int b) {
	P2OUT = so[a];
	P1OUT |= b;
	__delay_cycles(5000);
	P1OUT &= ~b;
}

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;
	P2DIR |= 0xFF;
	P2SEL = 0;
	P2SEL2 = 0;
	P2OUT &= ~0xFF;

	P1DIR |= 0xF0;
	P1REN |= 0x08;
	P1OUT |= 0x0F;

	P1IE |= 0x08;
	P1IES |= 0x08;
	//P1IFG |= 0x08;
	_enable_interrupts();

	while (1) {
		showled(i / 10, BIT6);
		showled(i % 10, BIT7);
	}
}
#pragma vector = PORT1_VECTOR
__interrupt void Portlab() {
	++i;
	if (i == 100)
		i = 0;
	P1IFG &= ~0x08;
}
