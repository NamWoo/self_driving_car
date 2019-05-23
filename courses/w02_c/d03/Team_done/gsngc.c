/***************************************************************
*
*	1. System Init Test 
* 
*	Created by MDS Tech. NT Div.(2Gr) (2015.10.30)
*
****************************************************************
*/

#include "2450addr.h"

void LED_Port_Init(void);
void LED_ON(void);
void LED_Off(void);


void Keypad_Init(void);


void Main()
{
	LED_Port_Init();

	Keypad_Init();

	while(1)
	{

		/*
		while(rGPFDAT!=0x7c)
		{
			LED_OFF();

			if(rGPFDAT==0x7c) break;
		}
		*/
	
		if((rGPFDAT&0x04)!=0x04)
			rGPGDAT &= ~(0x1<<4);
		else
			LED_OFF();

		if((rGPFDAT&0x08)!=0x08)
			rGPGDAT &= ~(0x1<<4);
		else
			LED_OFF();

		if((rGPFDAT&0x10)!=0x10)
			rGPGDAT &= ~(0x1<<4);
		else
			LED_OFF();

		if((rGPFDAT&0x20)!=0x20)
			rGPGDAT &= ~(0x1<<4);
		else
			LED_OFF();

		if((rGPFDAT&0x40)!=0x40)
			LED_ON();
		else
			LED_OFF();
	}
}

void LED_Port_Init() 
{
	rGPGDAT &= ~(0xf<<4);
	rGPGCON |= (0x55<<10);
}


void LED_ON()
{
	volatile int i;
	rGPGDAT &= ~(0xf<<4);
//	for(i=0;i<0xfffff; i++){}
}

void LED_OFF()
{
	volatile int i;
	rGPGDAT |= (0xf<<4);
//	for(i=0;i<0xfffff;i++){}
}

void Keypad_Init(void)
{
	rGPFDAT = (0x7c);

//	rGPFDAT |= (0x1f<<2);
	rGPFCON &= ~(0x3ff<<4);

//	rGPFDAT &= ~(0x1<<7);
	rGPFCON &= ~(0x1<<15);
	rGPFCON |= (0x1<<14);

	rGPGDAT &= ~(0x1);
	rGPGCON &= ~(0x1<<1);
	rGPGCON |= (0x1);
}



