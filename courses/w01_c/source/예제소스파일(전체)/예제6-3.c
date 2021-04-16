#include <stdio.h>

int main(void)
{
	int a = 1;              // 변수를 선언하고 1로 초기화

	do                      // 반복문 시작 위치
	{
		a = a * 2;          // a의 값을 2배로 늘린다.
	} while (a < 10);       // a가 10보다 작으면 9행을 반복
	printf("a : %d\n", a);  // 반복이 끝난 후 a값 출력

	return 0;
}