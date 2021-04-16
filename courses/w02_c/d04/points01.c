//#pragma pack(1)
#include <stdio.h>

//typedef struct _byte_2_t
//{
//	
//	uint8_t d1, d2;
//	
//} Byte_2_t;

void main(void)
{
	int arr[3] = {2,4,6};
	
	int *ptr1 = arr;
	
	int (*ptr2)[3] = arr;
	
	if (ptr1 = ptr2)
		printf("The same value, but different type \n");

	if ( (ptr1 + 1 ) == (ptr2 + 1))
		printf("Non executable code \n");
}
