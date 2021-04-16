#include <stdio.h>

int main(void)
{
	int a = 10;
	double b = 3.4;

	printf("int형 변수의 크기 : %d\n", sizeof (a));
	printf("double형 변수의 크기 : %d\n", sizeof (b));
	printf("정수형 상수의 크기 : %d\n", sizeof (10));
	printf("수식의 결과값의 크기 : %d\n", sizeof (1.5 + 3.4));
	printf("char 자료형의 크기 : %d\n", sizeof (char));

	return 0;
}