#include<stdio.h>

int my_strcmp(char *p1);

void main(void){
	char a[]="apple";
	char b[]="Apple";
	int i, cnt=0, result;
	char *pa= a;
	
//	for(i=0; i<sizeof(a)-1; i++)
//	{
//		printf("%d\n",*pa++);
//		cnt += *pa++;		
//	}
//	printf("%d",cnt);	
	
	result = my_strcmp(a) > my_strcmp(b) ? 1 : 0;
	
//	* `b = (a > 15) ? a+1 : a-1;`
//	* `(a > 15)? (b = a+1):(b = a-1);`
	
	if (result == 1 )
		printf("�տ��� �� Ŀ");
	else
		printf("�ڿ��� �� Ŀ");
 


	
//	printf("%d", my_strcmp(b));
//	printf("%d", a);
	
//	printf("ù��° ���� ���ڿ� �Է� :\n");   	
//	gets(a);
//	
//	printf("2�� ���ڿ��� �Է��ϼ��� : \n");   
//	gets(b);
	
//	my_strcmp(&a, &b);
//	printf("swap �� : %s - %s\n", a, b);
}
int my_strcmp(char *p1)
{
	int i,cnt;
	for(i=0; i<sizeof(p1)-1; i++)
	{
//		printf("%d\n",*p1++);
		cnt += *p1++;		
	}
//	printf("%d",cnt);
	return cnt;	
}



