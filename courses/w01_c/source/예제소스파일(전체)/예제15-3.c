#include <stdio.h>

void print_str(char **pps, int cnt);

int main(void)
{
	char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"}; // 초기화
	int count;                                     // 배열 요소 수를 저장할 변수

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);  // 배열 요소의 수 계산
	print_str(ptr_ary, count);                     // 배열명과 배열 요소 수를 주고 호출

	return 0;
}

void print_str(char **pps, int cnt)               // 매개변수로 2중 포인터 사용
{
	int i;

	for (i = 0; i < cnt; i++)                      // 배열 요소 수만큼 반복
	{
		printf("%s\n", pps[i]);                    // 2중 포인터를 배열명처럼 사용
	}
}