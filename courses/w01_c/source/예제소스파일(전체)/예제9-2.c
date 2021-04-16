#include <stdio.h>

int main(void)
{
	int a;                                    // 일반 변수 선언
	int *pa;                                  // 포인터 선언

	pa = &a;                                  // 포인터에 a의 주소 대입
	*pa = 10;                                 // 포인터로 변수 a에 10 대입

	printf("포인터로 a값 출력 : %d\n", *pa);
	printf("변수명으로 a값 출력 : %d\n", a);  // 변수 a값 출력

	return 0;
}