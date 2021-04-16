#include <stdio.h>

#pragma pack(push, 1)  // 바이트 얼라인먼트를 1로 바꿈

typedef struct
{
	char ch;
	int in;
} Sample1;

#pragma pack(pop)      // 바꾸기 전의 바이트 얼라인먼트 적용

typedef struct
{
	char ch;
	int in;
} Sample2;

int main(void)
{
	printf("Sample1 구조체의 크기 : %d바이트\n", sizeof(Sample1));
	printf("Sample2 구조체의 크기 : %d바이트\n", sizeof(Sample2));

	return 0;
}