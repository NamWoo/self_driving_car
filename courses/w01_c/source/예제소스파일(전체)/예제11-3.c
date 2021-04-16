#include <stdio.h>

int main(void)
{
	char ch1, ch2;

	scanf("%c %c", &ch1, &ch2);   // 두 개의 문자 연속 입력
	printf("[%c %c]", ch1, ch2);  // 입력된 문자 출력

	return 0;
}