#include <stdio.h>

int main(void)
{
	int a = 1;                  // 변수를 선언하고 1로 초기화
	int i;                      // 반복 횟수를 세기 위한 변수

	for (i = 0; i < 3; i++)     // i는 0으로 초기화된 후에 3보다 작은 동안
	{                           // 하나씩 증가하면서
		a = a * 2;              // 실행문을 실행
	}
	printf("a : %d\n", a);      // for문을 빠져나오면 a값 출력

	return 0;
}
