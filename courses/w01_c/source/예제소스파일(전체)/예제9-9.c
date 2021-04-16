#include <stdio.h>

void swap(int x, int y);           // 두 변수의 값을 바꾸는 함수 선언

int main(void)
{
	int a = 10, b = 20;            // 변수 선언과 초기화

	swap(a, b);                    // a, b의 값을 복사해서 전달
	printf("a:%d, b:%d\n", a, b);  // 변수 a, b 출력

	return 0;
}

void swap(int x, int y)            // 인수 a, b의 값을 x, y에 복사해서 저장
{
	int temp;                      // 교환을 위한 변수

	temp = x;                      // temp에 x값 저장
	x = y;                         // x에 y값 저장
	y = temp;                      // y에 temp값 저장
}