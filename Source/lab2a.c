/*
 * lab2a.c
 *
 *  Created on: Apr 5, 2014
 *      Author: Anh Huy
 */
#include "control.h"
// nhan S2 de bat tat qua lai giua D7 va D6
int lab2a(void){
	P2DIR |= 0xc0;
	P2SEL = 0;
	P2SEL2 =0;
	P2OUT &=~ 0xc0;
	P1REN |= 0x02;
	P1OUT |=0x02;
	unsigned char flag = 0;
	while(1){
		if(!(P1IN & 0x02)){
			if(flag == 0){
				flag = 1;
				P2OUT |= 0x40;
				P2OUT &=~ 0x80;
			}
			else{
				flag = 0;
				P2OUT |= 0x80;
				P2OUT &=~ 0x40;
			}
		}
	}
	return 0;
}



