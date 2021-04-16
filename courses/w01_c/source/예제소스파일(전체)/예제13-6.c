#include <stdio.h>

void add_ten(int a);        // 함수 선언

int main(void)
{
	int a = 10;

	add_ten(a);             // a값을 복사하여 전달
	printf("a : %d\n", a);

	return 0;
}

void add_ten(int a)         // 7행의 a와 다른 독립적인 저장 공간 할당
{
	a = a + 10;             // 15행의 매개변수 a에 10을 더한다.
}