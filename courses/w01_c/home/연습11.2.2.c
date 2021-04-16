#include <stdio.h> 

void main(void){
	int num;
	char alpha;
	
	printf("가장 좋아하는 알파벳?");
	scanf("%c", &alpha);
	
	fflush(stdin);
	printf("가장 좋아하는 숫자?");
	scanf("%d", &num);
	
	
	printf("%c, ", alpha);
	printf("%d", num);
	
}
