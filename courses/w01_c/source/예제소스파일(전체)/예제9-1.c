#include <stdio.h>

int main(void)
{
	int a;                                   // int형 변수 선언
	double b;                                // double형 변수 선언
	char c;                                  // char형 변수 선언

	printf("int형 변수의 주소 : %u\n", &a);  // 주소 연산자로 주소 계산
	printf("double형 변수의 주소 : %u\n", &b);
	printf("char형 변수의 주소 : %u\n", &c);

	return 0;
}