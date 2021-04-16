/*
 * =====================================================================
 * NAME         : Led.c
 *
 * Descriptions : Main routine for S3C2440
 *
 * IDE          : GCC-4.1.0
 *
 * Modification
 *	  
 * =====================================================================
 */

#include "2450addr.h"
#include "libc.h"

//Function Declaration
void Led_Init();
void Led_Display(int data);

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

void Led_Display(int data)
{
	int i;
	
#if 1
	//** if ~ else를 사용할 경우 
	/*if(data & 0x1)		rGPGDAT &= ~(1<<4);
	else if(data & 0x3) rGPGDAT &= ~(1<<5);
	else if(data & 0x5) rGPGDAT &= ~(1<<6);
	else				rGPGDAT &= ~(1<<7);*/
	if(data<4)				rGPGDAT &= ~(0x1<<(data+4));
	else					rGPGDAT &= ~(0x1<<(data^3));

	for(i=0;i<0x1ffff;i++);
	rGPGDAT |= (0xF<<4);

#endif

#if 0	
	//** switch ~ case를 사용할 경우 
	switch(data)
	{
	case 0:				rGPGDAT &= ~(0x1<<4); break;
	case 1:				rGPGDAT &= ~(0x1<<5); break;
	case 2:				rGPGDAT &= ~(0x1<<6); break;
	case 3:				rGPGDAT &= ~(0x1<<7); break;
	case 4:				rGPGDAT |= (0x1<<4); break;
	case 5:				rGPGDAT |= (0x1<<5); break;
	case 6:				rGPGDAT |= (0x1<<6); break;
	case 7:				rGPGDAT |= (0x1<<7); break;
	}
	for(i=0;i<0x1fff1;i++);
	
#endif 

#if 0	
	//** 삼항연산자를 사용할 경우 
	(data & 0x1) ? (rGPGDAT = ~(1<<4)) : (rGPGDAT |= (1<<4));
	(data & 0x3) ? (rGPGDAT = ~(1<<5)) : (rGPGDAT |= (1<<5));
	(data & 0x5) ? (rGPGDAT = ~(1<<6)) : (rGPGDAT |= (1<<6));
	(data & 0x7) ? (rGPGDAT = ~(1<<7)) : (rGPGDAT |= (1<<7));
	
	
	for(i=0;i<0x1ffff;i++);
	rGPGDAT |= (0xF<<4);
	
	
#endif

}
