#include <stdio.h>

void main(void){
	
	char ani[20];
	char why[20];
	

//	fflush(stdin);
	printf("좋아하는 이유 : ");
	fgets(why, sizeof(why), stdin);
	printf("%s", why);
	printf("좋아하는 동물 : ");
	scanf("%s", ani);
	printf("!!%s",ani);
}
