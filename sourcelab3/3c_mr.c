/*
 * lab3c.c
 *
 *  Created on: Apr 8, 2014
 *      Author: Anh Huy
 */
#include "msp430g2553.h"

int mode;
int i = 0x80, j = 0x80;

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;
	P1REN |= 0x0F;
	P1SEL = 0;
	P1OUT |= 0x0F;

	P2DIR |= 0xFF;
	P2SEL = 0;
	P2SEL2 = 0;
	P2OUT &= ~0xFF;

	P1IE |= 0x0F;
	P1IES |= 0x0F;
	_enable_interrupts();
	//_BIS_SR(LPM2_bits + GIE);

	while (1) {
		if (mode == 0) {
			//P2OUT |= 0x00;
			__delay_cycles(500000);
			P2OUT =~ i;
			i<<=1;
			if(i>BIT7) i=BIT0;

		}
		if (mode == 1) {
			P2OUT = 0x55;
			__delay_cycles(500000);
			P2OUT = 0xAA;
			__delay_cycles(500000);
		}
		if (mode == 2) {
			__delay_cycles(50000);
			P2OUT = i;
			i >>= 1;
			if (i < 0x01) i = 0x80;
			__delay_cycles(50000);
			P2OUT = 0x00;
		}
		if (mode == 3) {
			__delay_cycles(50000);
			P2OUT = i;
			i = i << 1;
			if (i > 0x80) i = 0x01;
			__delay_cycles(50000);
			P2OUT = 0x00;
		}
	}
}

#pragma vector = PORT1_VECTOR
__interrupt void Portlab() {
	if (P1IFG & 0x01) {
		mode = 0;
		P1IFG &= ~0x01;
	}
	if (P1IFG & 0x02) {
		mode = 1;
		P1IFG &= ~0x02;
	}
	if (P1IFG & 0x04) {
		mode = 2;
		P1IFG &= ~0x04;
	}
	if (P1IFG & 0x08) {
		mode = 3;
		P1IFG &= ~0x08;
	}
}
