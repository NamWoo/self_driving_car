#include <stdio.h>

int my_GET_SW(void);

void main(void)
{
	//rGPGDAT 8f1 rGPFDAT 7f
	//0111 1111 : 7f
	//0111 1011 : 7b GPF2 sw
//	printf("%x\n", (0x7f & 0x7b) == 0x4);
//	printf("%x\n", (0x7b & 0x7b));
//
//	printf("%x\n", (0x7f & 0x77) == 0x77);	
//	printf("%x\n", (0x77 & 0x77) == 0x77);
	
//	printf("\n");
//	printf ("%x\n",(0xff & 0x7b) == 0xff);
//	printf ("%x\n",(0x7b & 0x7b) == 0xff);

	int GPFDAT = 0xff;
	printf("GPFDAT : %x\n",GPFDAT);
	printf("%x\n", (GPFDAT & ~(0xfb))==0x04);		

	GPFDAT = 0xfb;
	printf("GPFDAT : %x\n",GPFDAT);
	printf("%x\n", (GPFDAT & ~(0xfb))==0x04);	//4 8 10 20 40
	printf("%x\n", (GPFDAT & ~(0xf7))==0x08);	//
	printf("%x\n", (GPFDAT & ~(0xef))==0x10);	//
	printf("%x\n", (GPFDAT & ~(0xdf))==0x20);	//
	printf("%x\n", (GPFDAT & ~(0xff))==0x40);	//


//	printf("%x\n", (0xff & ~(0xfb))==0x04);	
}






//	if ((rGPFDAT & 0x7b) == 0x7b)		//GPF2
//	{
//		sw = 9;
//	}
//	else if ((rGPFDAT & 0x77) == 0x77)	//GPF3
//	{
//		sw = 10;
//	}
//	else if ((rGPFDAT & 0x6f) == 0x6f)	//GPF4
//	{
//		sw = 11;
//	}
//	else if ((rGPFDAT & 0x5f) == 0x5f)	//GPF5
//	{
//		sw = 12;
//	}
//	else if ((rGPFDAT & 0x3f) == 0x3f)	//GPF6
//	{
//		sw = 13;
//	}
//	else{}
