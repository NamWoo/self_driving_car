#include <stdio.h>

int main(void)
{
	int a;       // 9행에서 대입 연산으로 초기화
	int b = 20;  // 변수 선언과 동시에 초기화
	int c;       // 초기화하지 않음

	a = 10;      // a에 10 대입, 초기화
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("c:%d\n", c);

	return 0;
}