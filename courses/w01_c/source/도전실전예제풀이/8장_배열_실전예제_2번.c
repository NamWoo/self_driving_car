// 8장 배열 도전 실전 예제 2번

#include <stdio.h>

int main(void)
{
	char str[80];
	int cnt = 0;
	int i;

	printf("문장 입력 : ");
	gets(str);

	for(i=0; str[i] != '\0'; i++)
	{
		if((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] += ('a'-'A');
			cnt++;
		}
	}

	printf("바뀐 문장 : ");
	puts(str);
	printf("바뀐 문자 수 : %d\n", cnt);

	return 0;
}