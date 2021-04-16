#include <stdio.h>

void swap(int *pa, int *pb);       // 두 변수의 값을 바꾸는 함수의 선언

int main(void)
{
	int a = 10, b = 20;            // 변수 선언과 초기화

	swap(&a, &b);                  // a, b의 주소를 인수로 주고 함수 호출
	printf("a:%d, b:%d\n", a, b);  // 변수 a, b 출력

	return 0;
}

void swap(int *pa, int *pb)        // 매개변수로 포인터 선언
{
	int temp;                      // 교환을 위한 임시 변수

	temp = *pa;                    // temp에 pa가 가리키는 변수의 값 저장
	*pa = *pb;                     // pa가 가리키는 변수에 pb가 가리키는 변수의 값 저장
	*pb = temp;                    // pb가 가리키는 변수에 temp값 저장
}