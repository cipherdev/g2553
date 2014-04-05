/*
 * lab2b.c
 *
 *  Created on: Apr 6, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int lab2b(void){
	  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
	//  BCSCTL1 = CALBC1_1MHZ; //cai dat clock noi la 1MHz
	//  DCOCTL = CALDCO_1MHZ;
	  P2DIR = 0xFF;
	  P2SEL = 0;
	  P2OUT = 0;
	  while(1)
	  {
		  P2OUT |= 0xFF;
		  __delay_cycles(1000000);
		  P2OUT &=~ 0xFF;
		  __delay_cycles(1000000);
	  }
}


