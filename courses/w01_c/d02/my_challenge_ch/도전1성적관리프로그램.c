#include <stdio.h>

int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);

int main(void)
{
	
	int kor = 70;
	int eng = 80;
	int mat = 91;
	
	printf("�� ������ ���� �Է� : ");
	scanf("%d %d %d",&kor, &eng, &mat);
	printf("/t=====< ����ǥ >=====\n\n");
	printf("-----------------\n");
	printf("   ����   ����   ����   ����   ���\n");
	printf("-----------------\n");
//	printf("\t\t\t\t\t\t\n");
	return 0;		
}


int total(int kor, int eng, int mat)
{
	int tot;
	tot = kor + eng + mat;
	return tot;
}

double average(int tot)
{
	avg = 
	return total/3;
}

void print_title(void)
{
		
}
