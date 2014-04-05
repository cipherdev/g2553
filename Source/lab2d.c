/*
 * lab2d.c
 *
 *  Created on: Apr 6, 2014
 *      Author: Anh Huy
 */
#include "control.h"

int lab2d(void){
	P2DIR |= 0xFF;
	P2SEL =0;
	int i = 0x01;
	char flag= 0;
	while(1)
	{
		__delay_cycles(100000);
		P2OUT = i;
		if(flag == 0){
			i = i <<1;	// i<<=1
			if(i == 0x80)
			{
				flag =1;
			}
		}
		else{
			i = i >>1;	// i>>=1
			if(i == 0x01)flag =0;
			}
	}
}



