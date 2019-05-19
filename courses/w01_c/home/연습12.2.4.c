#include <stdio.h>
#include <string.h>

void main(void)
{
	char ch1[80], ch2[80];
	char *reap1, *reap2;
	
	printf("두 단어 입력 : ");
	scanf("%s%s", ch1, ch2);
	
//	printf("%s\n",ch1);
//	printf("%s\n",ch2);
	if (strlen(ch1) > strlen(ch2))
		reap1 = ch1;
	else if (strlen(ch2) > strlen(ch1))
		reap1 = ch2;
	
	if (strcmp(ch1, ch2) == -1)
		reap2 = ch1;
	else if (strcmp(ch1, ch2) == 1)
		reap2 = ch2;
	else if (strcmp(ch1, ch2) == 0){
	}
		
	printf("길이가 긴 단어 : %s\n",reap1);
	printf("사전에 먼저 나오는 단어 : %s\n",reap2);
}
