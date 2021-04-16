#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *pi;               // 할당한 저장 공간을 연결할 포인터
	int size = 5;          // 한 번에 할당할 저장 공간의 크기, int형 변수 5개씩
	int cnt = 0;           // 현재 입력된 양수 개수
	int num;               // 양수를 입력할 변수
	int i;                 // 반복 제어 변수

	pi = (int *)calloc(size, sizeof(int));  // 먼저 5개의 저장 공간 할당
	while (1)
	{
		printf("양수를 입력하세요 => ");
		scanf("%d", &num);                  // 데이터 입력
		if (num <= 0) break;                // 0또는 음수이면 종료
		if (cnt < size)                     // 저장 공간이 남아 있으면
		{
			pi[cnt++] = num;                // 입력한 값 저장
		}
		else                                // 저장 공간이 부족하면
		{
			size += 5;                      // 크기를 늘려서 재할당
			pi = (int *)realloc(pi, size * sizeof(int));
			pi[cnt++] = num;                // 재할당한 공간에 값 대입
		}
	}
	for (i = 0; i < cnt; i++)
	{
		printf("%5d", pi[i]);               // 입력한 데이터 출력
	}
	free(pi);                               // 동적 할당 저장 공간 반납

	return 0;
}
