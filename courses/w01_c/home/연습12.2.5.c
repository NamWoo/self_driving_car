#include <stdio.h>
#include <string.h>

void main(void)
{
	char ch1[80];
	char *temp;
	int i,k;
	
	printf("단어 입력 : ");
	scanf("%s", ch1);	
	printf("입력한 단어 : %s, 생략한 단어 : ", ch1);
	
	if ((k = strlen(ch1)) >= 6){	
		for (i=0; i< 5; i++){
			printf("%c", ch1[i]);
		}		
		for (i=0; i< k-5; i++){
			printf("*");
		}		
	}
}

