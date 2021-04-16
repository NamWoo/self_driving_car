#include <stdio.h>

int main(void)
{
	char *dessert = "apple";                     // 포인터에 문자열 초기화

	printf("오늘 후식은 %s입니다.\n", dessert);  // 문자열 출력
	dessert = "banana";                          // 새로운 문자열 대입
	printf("내일 후식은 %s입니다.\n", dessert);  // 바뀐 문자열 출력

	return 0;
}