/***************************************************************
*
*	1. System Init Test 
* 
*	Created by MDS Tech. NT Div.(2Gr) (2015.10.30)
*
****************************************************************
*/

#include "2450addr.h"
//#include "libc.h"
void Led_Init(void);
void LED_Port_Init(void);
//void LED_ON_Off(void);
void Key_Port_Init(void);
//int Key_Get_Pressed(void);
int Key_Get_Pressed_my(void);


void Main()
{
//	int sw_num;
//LED_Port_Init
//	Led_Init();
//	rGPGDAT &= ~(0xf<<4);	//4 LED, 0 clear 
//	rGPGCON |= (0x55<<8);	//OUT mode 01 
//
////KEY_Port_Init	
//	rGPFDAT &= ~(0x3f<<2);	//GPFDAT[1:3] = 0, input mode
//	rGPFUDP &= ~(0x3ff <<4);//GPFUDP[2:6] = pull up-down disable
//	rGPFUDP |= (0x2aa <<4);	//GPFUDP[2:6] = pull up enable
//	rGPFCON &= ~(0x3ff <<4);//GPFCON[2:6} = 0, input

//	Key_Port_Init();

	//LED Init
	// 	
	rGPGDAT |= (0xf<<4);	//set (=OFF)  GPG4:GPG5:GPG6:GPG7
	rGPGCON |= (0x55<<8);	//SET OUTPUT mode GPIO 4:5:6:7
		
	//KEY Init
	//GPF7, GPG0 Output mode
	
	rGPFDAT &= ~(0x3f<<2);	//GPFDAT[1:3] = 0, input mode
	rGPFUDP &= ~(0x3ff <<4);//GPFUDP[2:6] = pull up-down disable
	rGPFUDP |= (0x2aa <<4);	//GPFUDP[2:6] = pull up enable
	rGPFCON &= ~(0x3ff <<4);//GPFCON[2:6} = 0, input

//	rGPFDAT |= (0x1<<7);	//GPFDAT[3] = 10 ???????
//	rGPGDAT |= 0x1;			//GPGDAT[0] = 01 output mode
	
	//OUTPUT mode 
//	rGPFCON &= ~(0x3<<14);	//GPFCON[7] = 00 input
//	rGPGCON &= ~0x3;		//GPGCON[0] = 00 input
	rGPFCON |= (0x1<<14);	//GPFCON[7] = 01 Output
	rGPGCON |= 0x1;			//GPGCON[0] = 01 Output


	while(1){

		sw_num = Key_Get_Pressed_my();

		if (sw_num ==1){
			rGPGDAT |= 0xf0;	
		}
	}
	




//	while(1)
//	{
//		Key_Get_Pressed();
//	}	
//
//	if GPF2+ GPF7-  switch on GPF7+
//	GPF 23456 GPF7
//	GPF 23456 GPG0
	

}

//void Switch_Init()
//{
//  rGPFDAT &= 0x00000000;
//  rGPFCON &= 0x00000000;
//}

int Key_Get_Pressed_my(void)
{
	rGPFCON |= (0x1<<13);
//	rGPFDAT |= 
	if ((rGPFDAT & 0x4) == 0x00) return 1;
	else return 0;

	
}



void LED_Port_Init() 
{
  rGPGDAT &= ~(0xf<<4);
  rGPGCON |= (0x55<<8);
}


void LED_ON_Off()
{
  volatile int i;
  rGPGDAT |= (0xf<<4);
  for(i=0;i<0xfffff;i++){}
  rGPGDAT &= ~(0xf<<4);
  for(i=0;i<0xfffff; i++){}
}


//Function
void Key_Port_Init(void)
{
	/* GPFCON -Input Mode GPF[2:6] */
	/* YOUR CODE HERE */
	
    rGPFDAT &= ~(0x3f<<2);	//GPFDAT[1:3] = 0, input mode
	rGPFUDP &= ~(0x3ff <<4);//GPFUDP[2:6] = pull up-down disable
	rGPFUDP |= (0x2aa <<4);	//GPFUDP[2:6] = pull up enable
	rGPFCON &= ~(0x3ff <<4);//GPFCON[2:6} = 0, input	

	/* GPFCON, GPGCON - outputmode GPF7, GPG0 */
	/* YOUR CODE HERE */	
	rGPFDAT |= (0x1<<7);	//GPFDAT[3] =  10 ???????
	rGPGDAT |= 0x1;			//GPGDAT[0] = 01 output mode

	rGPFCON &= ~(0x3<<14);	//GPFCON[7] = 00 input
	rGPGCON &= ~0x3;		//GPGCON[0] = 00 input
	rGPFCON |= (0x1<<14);	//GPFCON[7] = 01 Output
	rGPGCON |= 0x1;			//GPGCON[0] = 01 Output

}


int Key_Get_Pressed()
{
	int i,j, keyval;
	int arr[4]={4,5,6,7};	
	/* YOUR CODE HERE */
	for(i=0; i<2; i++)
	{	
		rGPFDAT |= 0x1<<7;
		rGPGDAT |= 0x1<<0;
		(i==1)?(rGPGDAT &= ~0x1):(rGPFDAT &= ~(0x1<<7));

		keyval = (~(rGPFDAT>>2) & 0xF);
		/* TO DO : 입력된 키값을 확인하여 리턴하는 switch case문을 작성하시오 */

		switch(keyval)
		{
			case 1: 
				rGPGDAT &= ~(0x1<<4); 
				for(i=0;i<0xffff;i++);
				break;
			case 2: 
				rGPGDAT &= ~(0x1<<5); 
				for(i=0;i<0xffff;i++);
				break;
			case 4: 
				rGPGDAT &= ~(0x1<<6); 
				for(i=0;i<0xffff;i++);
				break;
			case 8: 
				rGPGDAT &= ~(0x1<<7); 
				for(i=0;i<0xffff;i++);
				break;
			default:
				rGPGDAT |= (0xf<<4);
		}
		
		//Array ver
		for(j=0; j<4;)
		{
			if(keyval & 0x1)
			{
				rGPGDAT &= ~( 0x1<< arr[j] );
				for(i=0;i<0xffff;i++);
			}
			else
			{
				j++;
				keyval >> 1;
			}
		}

/*
		for(i=0; i<2; i++)
		{
			rGPGDAT |= 0x1 <<7;
			rGPGDAT |= 0x1 <<0;
			(i==1`)?(rGPGDAT &= !0x1):
			*/
	}

	return 0;

}



void Led_Init()
{
	/* TO DO : Init GPIO port connected to LED 
	 * LED1:LED2:LED3:LED4 = GPG4:GPG5:GPG6:GPG7 */
	/*rGPGDAT |= (0xf<<4); 		//set (=OFF)  GPG4:GPG5:GPG6:GPG7
	rGPGCON &= ~(0xff<<8);		//SET INPUT mode  GPIO 4:5:6:7
	rGPGCON |= (0x55<<8);		//SET OUTPUT mode GPIO 4:5:6:7*/

	rGPGDAT |= (0xf << 4);
	rGPGCON &= ~(0xff << 8);
	rGPGCON |= (0x55 << 8);
		
}


