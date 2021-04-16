#include <stdio.h>

int Get_Key_byPolling(void);

void main(void)
{
	int a=0;
	volatile unsigned int *const GPFCON=(unsigned int*)0x56000050;
	volatile unsigned int *const GPGCON=(unsigned int*)0x56000060;
	volatile unsigned int *const GPFDAT=(unsigned int*)0x56000054;
	volatile unsigned int *const GPGDAT=(unsigned int*)0x56000064;
		
	
	a=Get_Key_byPolling();
	

}

int Get_Key_byPolling(void)
{
	unsigned int a;
	GPFDAT &=~(0x80);
	GPGDAT |=(0x01);
	
	int i;
	for(i=0;i<5;i++){
		a=GPFDAT;
		a&=(0x1<<(i+2));
		a= (a>>(i+2));
		if(a==0) return i+1;
	}
	GPFDAT |=(0x80);
	GPGDAT &= ~(0x01);
	
	for(i=0;i<5;i++){
		a=GPFDAT;
		a&=(0x1<<(i+2));
		a= (a>>(i+2));
		if(a==0) return i+6;
	}
	

	return 0;
}
