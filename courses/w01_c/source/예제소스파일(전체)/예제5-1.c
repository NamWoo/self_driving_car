#include <stdio.h>

int main(void)
{
	int a = 20;
	int b = 0;

	if (a > 10)                        // a가 10보다 크므로 조건식은 참
	{
		b = a;                         // b = a 대입문 실행
	}

	printf("a : %d, b : %d\n", a, b);  // 대입이 수행되면 두 값은 같음

	return 0;
}