#include <stdio.h>

int main(void)
{
	char str[80] = "applejam";             // 문자열 초기화

	printf("최초 문자열 : %s\n", str);     // 초기화 문자열 출력
	printf("문자열 입력 : ");
	scanf("%s", str);                      // 새로운 문자열 입력
	printf("입력 후 문자열 : %s\n", str);  // 입력된 문자열 출력

	return 0;
}