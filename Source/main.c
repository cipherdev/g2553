/*
 * lab2a.c
 *
 *  Created on: Apr 5, 2014
 *      Author: Anh Huy
 */
#include "control.h"
// nhan S2 de bat tat qua lai giua D7 va D6
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;
	lab2a();
}



