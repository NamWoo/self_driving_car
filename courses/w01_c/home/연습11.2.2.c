#include <stdio.h> 

void main(void){
	int num;
	char alpha;
	
	printf("���� �����ϴ� ���ĺ�?");
	scanf("%c", &alpha);
	
	fflush(stdin);
	printf("���� �����ϴ� ����?");
	scanf("%d", &num);
	
	
	printf("%c, ", alpha);
	printf("%d", num);
	
}
