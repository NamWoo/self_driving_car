#include <stdio.h>

void fruit(void);      // 함수 선언

int main(void)
{
	fruit();           // 함수 호출

	return 0;
}

void fruit(void)       // 재귀호출 함수 정의
{
	printf("apple\n");

	fruit();           // 자신을 다시 호출
}