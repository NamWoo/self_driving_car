#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[800] = {0};   // 문자열을 이어붙일 배열, 널 문자로 초기화
	char temp[20];

	while(1)
	{
		printf("단어 입력 : ");
		scanf("%s", temp);
		if(strcmp(temp, "end") == 0) break;

		strcat(str, temp);
		printf("현재까지의 문자열 : %s\n", str);
		strcat(str, " ");
	}

	return 0;
}
