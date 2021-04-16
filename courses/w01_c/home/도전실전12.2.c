#include <stdio.h>
#include <string.h>

void main(void)
{
	char ch[200];
	char ne[80];
	
	printf("단어 입력 : ");
	scanf("%s", ch);
	printf("현재까지의 문자열 : %s\n", ch);
	
	while(1){
		printf("단어 입력 : ");
		scanf("%s", ne);
		
		if (strcmp(ne,"end") == 0){
			break;
		} 
		
		strcat(ch, " ");
		strcat(ch, ne);		
		
		printf("현재까지의 문자열 : %s\n", ch);
	}
}
