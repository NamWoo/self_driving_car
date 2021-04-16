#include <stdio.h>

int main(void)
{
	int a, b;
	int sum, sub, mul, inv;

	a = 10;        // 대입 연산
	b = 20;        // 대입 연산
	sum = a + b;   // 더하기 연산 후 대입 연산
	sub = a - b;   // 빼기 연산 후 대입 연산
	mul = a * b;   // 곱하기 연산 후 대입 연산
	inv = -a;      // 음수 연산 후 대입 연산

	printf("a의 값 :%d, b의 값 :%d\n", a, b);
	printf("덧셈 : %d\n", sum);
	printf("뺄셈 : %d\n", sub);
	printf("곱셈 : %d\n", mul);
	printf("a의 음수연산 : %d\n", inv);

	return 0;
}