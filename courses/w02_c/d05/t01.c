#include <stdio.h>

void main(void)
{
	
	int	sel;
	sel -= '0';

//	printf("%x\n",((1<<1) | (0)));	//2
	printf("sel %x\n", sel);			//ffffffd0
	printf("sel*4 %x\n", sel*4);			//ffffff40
	printf("~(0x7<<(sel*4)) %x\n",~(0x7<<(sel*4)));	//fffffff8	
	printf("(0x3<<(sel*4) %x\n",(0x3<<(sel*4)));	//3
	
}

