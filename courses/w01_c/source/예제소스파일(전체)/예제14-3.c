#include <stdio.h>

int main(void)
{
	char animal[5][20];                          // 2차원 char 배열 선언
	int i;                                       // 반복 제어 변수
	int count;                                   // 행의 수를 저장할 변수

	count = sizeof(animal) / sizeof(animal[0]);  // 행의 수 계산
	for (i = 0; i < count; i++)                  // 행의 수만큼 반복
	{
		scanf("%s", animal[i]);                  // 문자열 입력
	}
	for (i = 0; i < count; i++)
	{
		printf("%s, ", animal[i]);               // 입력된 문자열 출력
	}

	return 0;
}