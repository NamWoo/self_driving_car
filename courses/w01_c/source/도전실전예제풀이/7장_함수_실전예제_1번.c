#include <stdio.h>

int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);

int main(void)
{
	int kor, eng, mat;
	int tot;
	double avg;

	printf("# �� ������ ���� �Է� : ");
	scanf("%d%d%d", &kor, &eng, &mat);
	tot = total(kor, eng, mat);
	avg = average(tot);
	print_title();
	printf("%8d%8d%8d%8d%8.1lf\n", kor, eng, mat, tot, avg);

	return 0;
}

void print_title(void)
{
	printf("\n         =====< ����ǥ >=====\n\n");
	printf("------------------------------------------\n");
	printf("    ����    ����    ����    ����    ���\n");
	printf("------------------------------------------\n");
}

double average(int tot)
{
	return (tot / 3.0);
}

int total(int kor, int eng, int mat)
{
	return (kor + eng + mat);
}