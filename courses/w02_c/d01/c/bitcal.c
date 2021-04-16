#include <stdio.h>

void main(void)
{
	
	unsigned char data1 = 0xad;
	printf("%x\n", 0xad);
	
	
//	data1 = data1 ^ 0x18;
//	data1 ^= 0x18;
	data1 ^= 0x1 << 3;
	
	printf("%x\n", data1);
}
