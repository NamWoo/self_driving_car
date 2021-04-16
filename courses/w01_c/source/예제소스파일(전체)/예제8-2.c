#include <stdio.h>

int main(void)
{
	int ary1[5] = {1, 2, 3, 4, 5};               // int형 배열 초기화
	int ary2[5] = {1, 2, 3};                     // 초깃값이 적은 경우
	int ary3[] = {1, 2, 3};                      // 배열 요소 개수가 생략된 경우
	double ary4[5] = {1.0, 2.1, 3.2, 4.3, 5.4};  // double형 배열 초기화
	char ary5[5] = {'a', 'p', 'p', 'l', 'e'};    // char형 배열 초기화

	ary1[0] = 10;
	ary1[1] = 20;
	ary1[2] = 30;
	ary1[3] = 40;
	ary1[4] = 50;

	return 0;
}