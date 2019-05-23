#pragma pack(1)
#include <stdint.h>s

typedef struct _byte_2_t
{
	
	uint8_t d1, d2;
	
} Byte_2_t;

void main()
{
	uint32_t arr[3][2];
	Byte_2_t (*ptr)[4] = arr;
	
	*(uint32_t *)ptr[1] = 0xa5a5a5a5;
	printf("%#x \n", arr[1][0]);
}
