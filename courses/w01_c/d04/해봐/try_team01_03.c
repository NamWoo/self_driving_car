#include<stdio.h>

int my_strcmp(char *p1);

void main(void){
	char a[80];
	char b[80];
	int i, cnt=0, result;
	char *pa= a;
	
	printf("첫번째 비교할 문자열 입력 :\n");   	
	gets(a);
	
	printf("2번 문자열을 입력하세요 : \n");   
	gets(b);
	
	result = my_strcmp(a) > my_strcmp(b) ? 1 : 0;
	
	if (result == 1)
		printf("앞에꺼 더 커");
	else
		printf("뒤에꺼 더 커");
}
int my_strcmp(char *p1)
{
	int i, cnt;
	for(i=0; i<sizeof(p1)-1; i++)
		cnt += *p1++;
	
	printf("%d\n",cnt);

	return cnt;	
}



