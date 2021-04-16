#include <stdio.h>

int sum(int, int);                 // 함수 선언

int main(void)
{
	int(*fp)(int, int);            // 함수 포인터 선언
	int res;                       // 반환값을 저장할 변수

	fp = sum;                      // 함수명을 함수 포인터에 저장
	res = fp(10, 20);              // 함수 포인터로 함수 호출
	printf("result : %d\n", res);  // 반환값 출력

	return 0;
}

int sum(int a, int b)
{
	return (a + b);
}