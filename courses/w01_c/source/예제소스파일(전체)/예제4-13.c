#include <stdio.h>

int main(void)
{
	int a = 10;   // 비트열 00000000 00000000 00000000 00001010
	int b = 12;   // 비트열 00000000 00000000 00000000 00001100

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a << 1 : %d\n", a << 1);
	printf("a >> 2 : %d\n", a >> 2);

	return 0;
}