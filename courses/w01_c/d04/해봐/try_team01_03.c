#include<stdio.h>

int my_strcmp(char *p1);

void main(void){
	char a[80];
	char b[80];
	int i, cnt=0, result;
	char *pa= a;
	
	printf("ù��° ���� ���ڿ� �Է� :\n");   	
	gets(a);
	
	printf("2�� ���ڿ��� �Է��ϼ��� : \n");   
	gets(b);
	
	result = my_strcmp(a) > my_strcmp(b) ? 1 : 0;
	
	if (result == 1)
		printf("�տ��� �� Ŀ");
	else
		printf("�ڿ��� �� Ŀ");
}
int my_strcmp(char *p1)
{
	int i, cnt;
	for(i=0; i<sizeof(p1)-1; i++)
		cnt += *p1++;
	
	printf("%d\n",cnt);

	return cnt;	
}



