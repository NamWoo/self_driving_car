#include <stdio.h>

void add_ten(int *p);       // 매개변수로 포인터 선언

int main(void)
{
	int a = 10;

	add_ten(&a);            // a의 주소를 인수로 준다.
	printf("a : %d\n", a);  // 증가된 a값 출력

	return 0;
}

void add_ten(int *p)        // 포인터 p가 a의 주소를 받는다.
{
	*p = *p + 10;           // 포인터 p가 가리키는 변수의 값 10 증가
}