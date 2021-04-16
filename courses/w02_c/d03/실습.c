#include <stdio.h>

void main(void)
{
	unsigned char var = 77;
	unsigned char arr[3] = {1,3,5};
	
	arr[3] = arr[0];
	
	printf("arr[3] = %d \n", arr[3]);
	printf("var[3] = %d \n", var);
}
