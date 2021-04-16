#include <stdio.h>

int main(void)
{
	double apple;
	int banana;
	int orange;

	apple = 5.0 / 2.0;  // 실수와 실수의 나눗셈 연산
	banana = 5 / 2;     // 정수와 정수의 나눗셈 연산
	orange = 5 % 2;     // 정수와 정수의 나머지 연산

	printf("apple : %.1lf\n", apple);
	printf("banana : %d\n", banana);
	printf("orange : %d\n", orange);

	return 0;
}