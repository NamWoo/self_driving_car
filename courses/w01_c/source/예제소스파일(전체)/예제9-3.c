#include <stdio.h>

int main(void)
{
	int a = 10, b = 15, tot;   // 변수 선언과 초기화
	double avg;                // 평균을 저장할 변수
	int *pa, *pb;              // 포인터 동시 선언
	int *pt = &tot;            // 포인터 선언과 초기화
	double *pg = &avg;         // double형 포인터 선언과 초기화

	pa = &a;                   // 포인터 pa에 변수 a의 주소 대입
	pb = &b;                   // 포인터 pb에 변수 b의 주소 대입

	*pt = *pa + *pb;           // a값과 b값을 더해 tot에 저장
	*pg = *pt / 2.0;           // tot값을 2로 나눈 값을 avg에 저장

	printf("두 정수의 값 : %d, %d\n", *pa, *pb);  // a값과 b값 출력
	printf("두 정수의 합 : %d\n", *pt);           // tot값 출력
	printf("두 정수의 평균 : %.1lf\n", *pg);      // avg값 출력

	return 0;
}