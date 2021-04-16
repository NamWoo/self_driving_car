#include <stdio.h>

void assign(void);                      // 함수 선언

int main(void)
{
	auto int a = 0;                     // 지역 변수 선언과 초기화, auto는 생략 가능

	assign();                           // 함수 호출
	printf("main 함수 a : %d\n", a);

	return 0;
}

void assign(void)
{
	auto int a;                         // main 함수에 있는 변수와 같은 이름의 지역 변수

	a = 10;                             // assign 함수 안에 선언된 a에 대입
	printf("assign 함수 a : %d\n", a);  // assign 함수에 선언된 a값 출력
}