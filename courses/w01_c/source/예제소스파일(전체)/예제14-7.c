#include <stdio.h>

int main(void)
{
	int ary1[4] = {1, 2, 3, 4};           // 1차원 배열의 선언과 초기화
	int ary2[4] = {11, 12, 13, 14};
	int ary3[4] = {21, 22, 23, 24};
	int *pary[3] = {ary1, ary2, ary3};    // 포인터 배열에 각 배열명 초기화
	int i, j;                             // 반복 제어 변수

	for (i = 0; i < 3; i++)               // 3행 반복
	{
		for (j = 0; j < 4; j++)           // 4열 반복
		{
			printf("%5d", pary[i][j]);    // 2차원 배열처럼 출력
		}
		printf("\n");                     // 한 행을 출력한 후에 줄 바꿈
	}

	return 0;
}