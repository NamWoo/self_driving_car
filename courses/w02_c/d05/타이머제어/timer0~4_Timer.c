#include "2450addr.h"
#include "option.h"
#include "libc.h"

//Function Declaration
void my_Timer_Init(int sel);
void my_Timer_delay(int sel);


void my_Timer_Init(int sel)
{
	/* 
	* TO DO :	Timer0 Init 
	* Prescaler value : 255, dead zone length = 0
	* Divider value : 1/16, no DMA mode
	* New frequency : (PCLK/(Prescaler value+1))*Divider value = (66Mhz/(256))*(1/16)
	*				= 16.113Khz(16113Hz)
	*/
	sel -= '0';		//48	//2  48-1
	
	rTCFG0=0xffff;	//prescaler0,1 
	
	rTCFG1 &= ~(0x7<<(sel*4));		
	rTCFG1 |= (0x3<<(sel*4));
	
//	printf("%x\n",((1<<1) | (0)));	//2
//	printf("%x\n", sel);			//ffffffd0
//	printf("%x\n", sel*4);			//ffffff40
//	printf("%x\n",~(0x7<<(sel*4)));	//fffffff8	
//	printf("%x\n",(0x3<<(sel*4)));	//3
	
	
			
	/* TO DO :   TCON설정 :Dead zone disable,  auto reload on, output inverter off
	*  manual update no operation, timer0 stop, TCNTB0=0, TCMPB0 =0
	*/
	(*(volatile unsigned *)(0x5100000C+(sel*12))) = 0;
	
	if(sel!=4)
		(*(volatile unsigned *)(0x51000010+(sel*12))) = 0;	
		
	switch(sel)
	{
		case 0:
			rTCNTB0 = 16.113*10;
			rTCON |= (0x1<<3);	
			rTCON |= (1<<1) | (0x0<<0);
			rTCON &= ~(1<<1);
			rTCON |= (0x1<<0);
			break;
		case 1:
			rTCNTB1 = 16.113*100;			
			rTCON |= (0x1<<11);	
			rTCON |= (1<<9) | (0x0<<8);
			rTCON &= ~(1<<9);
			rTCON |= (0x1<<8);
			break;	
		case 2:
			rTCNTB2 = 16.113*500;			
			rTCON |= (0x1<<15);	
			rTCON |= (1<<13) | (0x0<<12);
			rTCON &= ~(1<<13);
			rTCON |= (0x1<<12);
			break;
		case 3:
			rTCNTB3 = 16.113*1000;
			rTCON |= (0x1<<19);				
			rTCON |= (1<<17) | (0x0<<16);
			rTCON &= ~(1<<17);
			rTCON |= (0x1<<16);
			break;	
		case 4:
			rTCNTB4 = 16.113*2000;
			rTCON |= (0x1<<22);				
			rTCON |= (1<<21) | (0x0<<20);
			rTCON &= ~(1<<21);
			rTCON |= (0x1<<20);
			break;	
		default:
			break;
							
	}
	
}

void my_Timer_delay(int sel)
{
	/*  TO DO :
	* 1) TCNTB0설정 : 넘겨받는 data의 단위는 msec이다.
	*                  따라서 msec가 그대로 TCNTB0값으로 설정될 수는 없다.
	* 2) manual update후에  timer0를 start시킨다. 
	* 	 note : The bit has to be cleared at next writing.
	* 3) TCNTO0값이 0이 될때까지 기다린다. 	
	*/
	/* YOUR CODE HERE */	

	sel -= '0';
	if(sel != 4)
		while((*(volatile unsigned *)(0x51000014+(sel*12))));
	else
		while(rTCNTO4);

}

