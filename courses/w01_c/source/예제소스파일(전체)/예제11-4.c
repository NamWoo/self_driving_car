#include <stdio.h>

int main(void)
{
	int ch;                    // 입력 문자를 저장할 변수

	ch = getchar();            // 함수가 반환하는 문자를 바로 저장
	printf("입력한 문자 : ");
	putchar(ch);               // 입력한 문자 출력
	putchar('\n');             // 개행문자 출력

	return 0;
}