#include <stdio.h>

int main(void)
{
	printf("%c\n", 'A');                      // 문자 상수 출력
	printf("%s\n", "A");                      // 문자열 상수 출력
	printf("%c은 %s입니다.\n", '1', "first"); // 문자와 문자열을 함께 출력

	return 0;
}