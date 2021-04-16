#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, res;

	a + b;                                  // 연산 결과는 버려짐
	printf("%d + %d = %d\n", a, b, a + b);  // 연산 결과를 바로 출력에 사용

	res = a + b;                            // 연산 결과를 변수에 저장
	printf("%d + %d = %d\n", a, b, res);    // 저장된 연산 결과는 계속 사용

	return 0;
}