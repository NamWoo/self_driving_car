#include <stdio.h>

void print_ary(int *pa);       // 함수 선언

int main(void)
{
	int ary[5] = {10, 20, 30, 40, 50};

	print_ary(ary);            // 배열명을 주고 함수 호출

	return 0;
}

void print_ary(int *pa)        // 매개변수로 포인터 선언
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%d ", pa[i]);  // pa로 배열 요소 표현식 사용
	}
}
