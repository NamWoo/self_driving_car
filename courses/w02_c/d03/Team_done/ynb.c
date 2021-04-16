/***************************************************************
*
*	1. System Init Test 
* 
*	Created by MDS Tech. NT Div.(2Gr) (2015.10.30)
*
****************************************************************
*/

#include "2450addr.h"

volatile unsigned int *const GPFCON=(unsigned int*)0x56000050;
volatile unsigned int *const GPGCON=(unsigned int*)0x56000060;
volatile unsigned int *const GPFDAT=(unsigned int*)0x56000054;
volatile unsigned int *const GPGDAT=(unsigned int*)0x56000064;

void LED_Port_Init(void);
void LED_ON_Off(void);
void Init_Key(void);
int Get_Key_byPolling(void);

void Main()
{
	volatile int key=-1;
	int a=0;
	
	Init_Key();
	while(1){
		a=Get_Key_byPolling();
		
		if(a!=0) {
			key=a;\
			switch(key)
			{
				case 1: *GPGDAT=*GPGDAT & ~(0xf<<4); //all on
						break;
				case 2:  *GPGDAT=*GPGDAT | (0xf<<4);  
					     *GPGDAT=*GPGDAT & ~(0x8<<4);// only GPG7 on
					  	break;
				case 3: *GPGDAT=*GPGDAT | (0xf<<4);  
					    *GPGDAT=*GPGDAT & ~(0x4<<4); //only GPG6 on
						break;
				case 4: *GPGDAT=*GPGDAT | (0xf<<4);  
					    *GPGDAT=*GPGDAT & ~(0x2<<4); //only GPG5 on
						break;
				case 5: *GPGDAT=*GPGDAT | (0xf<<4);  
					    *GPGDAT=*GPGDAT & ~(0x1<<4); //only GPG4 on
						break;
				case 6: *GPGDAT=*GPGDAT & ~(0xf<<4); //all on
						break;
				case 7:  *GPGDAT=*GPGDAT | (0xf<<4);  
					     *GPGDAT=*GPGDAT & ~(0x8<<4);// only GPG7 on
					  	break;
				case 8: *GPGDAT=*GPGDAT | (0xf<<4);  
					    *GPGDAT=*GPGDAT & ~(0x4<<4); //only GPG6 on
						break;
				case 9: *GPGDAT=*GPGDAT | (0xf<<4);  
					    *GPGDAT=*GPGDAT & ~(0x2<<4); //only GPG5 on
						break;
				case 10: *GPGDAT=*GPGDAT | (0xf<<4);  
					    *GPGDAT=*GPGDAT & ~(0x1<<4); //only GPG4 on
						break;
				default : break;
			}
		}
		
	}
}

int Get_Key_byPolling(void)
{
	unsigned int a;
	*GPFDAT &=~(0x80);
	*GPGDAT |=(0x01);
	
	int i;
	for(i=0;i<5;i++){
		a=*GPFDAT;
		a&=(0x1<<(i+2));
		a= (a>>(i+2));
		if(a==0) return i+1;
	}
	*GPFDAT |=(0x80);
	*GPGDAT &= ~(0x01);
	
	for(i=0;i<5;i++){
		a=*GPFDAT;
		a&=(0x1<<(i+2));
		a= (a>>(i+2));
		if(a==0) return i+6;
	}
	

	return 0;
}


void Init_Key(void){
	*GPFCON = 0x4000;	
	*GPFDAT &= ~(0x7e);
	*GPGCON = 0x5501;
	*GPGDAT &= ~(0x0001);
}

void LED_Port_Init() 
{
  	rGPGDAT &= ~(0xf<<4);
  	rGPGCON |= (0x55<<10);
}


void LED_ON_Off()
{
  volatile int i;
  rGPGDAT |= (0xf<<4);
  for(i=0;i<0xfffff;i++){}
  rGPGDAT &= ~(0xf<<4);
  for(i=0;i<0xfffff; i++){}
}

