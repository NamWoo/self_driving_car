#include <stdio.h>

void main(void){
	
	char ani[20];
	char why[20];
	

//	fflush(stdin);
	printf("�����ϴ� ���� : ");
	fgets(why, sizeof(why), stdin);
	printf("%s", why);
	printf("�����ϴ� ���� : ");
	scanf("%s", ani);
	printf("!!%s",ani);
}
