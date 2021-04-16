// 파일 이름을 '예제19-8-sub.c'에서 sub.c로 바꿔 사용하세요.

#include <stdio.h>                  // printf, scanf 함수 사용을 위해 필요

void input_data(int *pa, int *pb)   // 두 정수 입력 함수
{
	printf("두 정수 입력 : ");
	scanf("%d %d", pa, pb);
}

double average(int a, int b)        // 평균을 구하는 함수
{
	int tot;
	double avg;

	tot = a + b;
	avg = tot / 2.0;

	return avg;
}
