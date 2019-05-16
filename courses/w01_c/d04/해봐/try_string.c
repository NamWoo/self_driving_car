#include<stdio.h>

void swap(char *p1, char *p2);

void main(void)
{
    char str;
    char a[80];
    char b[80];
	
	printf("1번 문자열을 입력하세요 : \n");   	
	gets(a);
//	fgets(a, sizeof(a),stdin);
	
	printf("2번 문자열을 입력하세요 : \n");   
	gets(b);
//	fgets(a, sizeof(a),stdin);
	
	printf("swap 전 : %s - %s\n", a, b);
	swap(&a, &b);
	printf("swap 후 : %s - %s\n", a, b);
	    
}
	
void swap (char *p1, char *p2) // call by ref 
{	
	char temp;
	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

