#include<stdio.h>

void my_strcmp(char *p1, char *p2);

void main(void){
	char a[80]="apple";
	char b[80]="Apple";


	printf("%d",strcmp(a,b));
	
//	printf("첫번째 비교할 문자열 입력 :\n");   	
//	gets(a);
//	
//	printf("2번 문자열을 입력하세요 : \n");   
//	gets(b);
	
	my_strcmp(&a, &b);
	printf("swap 후 : %s - %s\n", a, b);
}


void my_strcmp (char *p1, char *p2) // call by ref 
{	
	char temp;
	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

	



