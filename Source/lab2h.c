/*
 * lab2h.c
 *
 *  Created on: Apr 8, 2014
 *      Author: Anh Huy
 */
#include "control.h"
int giay=0;
int phut=0;
int gio=0;
int count=0;
int i=0;
int mode=0;
int value=0x10;

int nutnhantang(int mode, int giatri){
	if(mode==1){
		giatri++;
		if(giatri>=24) giatri=0;
		__delay_cycles(300000);
		return giatri;
	}
	else if(mode==2){
		giatri++;
		if(giatri>=60) giatri=0;
		__delay_cycles(300000);
		return giatri;
	}
	else return giatri;
}
int nutnhangiam(int mode, int giatri){
	if(mode==1){
		giatri--;
		if(giatri<0) giatri=23;
		__delay_cycles(300000);
		return giatri;
	}
	else if(mode==2){
		giatri--;
		if(giatri<0) giatri=59;
		__delay_cycles(300000);
		return giatri;
	}
	else return giatri;
}
int chedo(mode){
	mode++;
	if(mode>3) mode=0;
	__delay_cycles(300000);
	return mode;
}
int lab2h(void) {
	P1DIR = 0xf0;
	P1OUT = 0x0F;
	P1REN =0x0f;

	P2SEL = 0x00;
	P2DIR = 0xFF;
	P2OUT = 0x00;
	while(1){
		if(mode==1){
			showled(gio%10,BIT5);
			showled(gio/10,0x10);
		}
		else if(mode==2){
			showled(phut%10,BIT7);
			showled(phut/10,BIT6);
			}
		else if(mode ==0){
			showled(gio%10,BIT5);
			showled(gio/10,0x10);
			showled(10,value);
			showled(phut%10,BIT7);
			showled(phut/10,BIT6);
		}
		else if(mode==3){
			showled(12,0x10);
			showled(12,BIT5);
			showled(12,BIT6);
			showled(12,BIT7);
		}
		if(++count==50){
			if(value>=BIT7) value=0x10;
			else value=value<<1;
			giay++;
			count=0;
			if(giay==60){
				giay =0;
				phut++;
				if(phut==60){
					phut=0;
					gio++;
					if(gio==24){
						gio=0;
					}
				}
			}
		}
		if(!(P1IN & 0x08)){
			mode=chedo(mode);
		}
		if(!(P1IN & 0x04)){
			if(mode==1){
				gio=nutnhantang(mode,gio);
			}else{
				phut=nutnhantang(mode,phut);
			}
		}
		if(!(P1IN & 0x02)){
			if(mode==1){
				gio=nutnhangiam(mode,gio);
			}
			else{
				phut=nutnhangiam(mode,phut);
			}
		}
	}
}
