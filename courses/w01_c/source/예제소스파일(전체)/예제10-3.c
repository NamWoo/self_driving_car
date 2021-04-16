#include <stdio.h>

int main(void)
{
	int ary[3];                // 배열 선언
	int *pa = ary;             // 포인터에 배열명 저장
	int i;                     // 반복 제어 변수

	*pa = 10;                  // 첫 번째 배열 요소에 10 대입
	*(pa + 1) = 20;            // 두 번째 배열 요소에 20 대입
	pa[2] = pa[0] + pa[1];     // 대괄호를 써서 pa를 배열명처럼 사용

	for (i = 0; i < 3; i++)
	{
		printf("%5d", pa[i]);  // 포인터로 모든 배열 요소 출력
	}

	return 0;
}