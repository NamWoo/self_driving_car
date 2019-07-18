#include <stdio.h>

void main(void)
{
	char str[80];
	
	printf("문자열 입력 : ");
//	scanf("%s", str);
//	printf("%d",sizeof(str));
	fgets(str,sizeof(str),stdin);
	printf("첫번째단어%s",str);
//	scanf("%s", str);
//	printf("첫번째단어%s\n",str);
}

