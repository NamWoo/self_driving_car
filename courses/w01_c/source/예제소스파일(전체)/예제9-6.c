#include <stdio.h>

int main(void)
{
	int a = 10;            // ���� ����� �ʱ�ȭ
	int *p = &a;           // ������ ����� ���ÿ� a�� ����Ű���� �ʱ�ȭ
	double *pd;            // double�� ������ ����Ű�� ������

	pd = p;                // ������ p���� ������ pd�� ����
	printf("%lf\n", *pd);  // pd�� ����Ű�� ������ �� ���

	return 0;
}