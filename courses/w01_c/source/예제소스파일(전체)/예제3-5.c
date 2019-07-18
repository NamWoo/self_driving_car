#include <stdio.h>

int main(void)
{
	unsigned int a;

	a = 4294967295;      // 큰 양수 저장
	printf("%d\n", a);   // %d로 출력
	a = -1;              // 음수 저장
	printf("%u\n", a);   // %u로 출력

	return 0;
}