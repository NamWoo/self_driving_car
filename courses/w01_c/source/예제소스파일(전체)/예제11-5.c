#include <stdio.h>

int main(void)
{
	char ch;
	int i;

	for (i = 0; i < 3; i++)  // 세 번 반복
	{
		scanf("%c", &ch);    // 문자 입력
		printf("%c", ch);    // 입력된 문자 출력
	}

	return 0;
}