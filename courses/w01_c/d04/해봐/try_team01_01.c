#include<stdio.h>

void my_strcmp(char *p1, char *p2);

void main(void){
	char a[80]="apple";
	char b[80]="Apple";


	printf("%d",strcmp(a,b));
	
//	printf("ù��° ���� ���ڿ� �Է� :\n");   	
//	gets(a);
//	
//	printf("2�� ���ڿ��� �Է��ϼ��� : \n");   
//	gets(b);
	
	my_strcmp(&a, &b);
	printf("swap �� : %s - %s\n", a, b);
}


void my_strcmp (char *p1, char *p2) // call by ref 
{	
	char temp;
	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

	



