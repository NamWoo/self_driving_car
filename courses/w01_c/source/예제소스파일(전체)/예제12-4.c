#include <stdio.h>

int main(void)
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets(str);                                  // 배열명으로 주고 함수 호출
	printf("입력한 문자열은 %s입니다.", str);

	return 0;
}