// ���� �̸��� '����19-8-main.c'���� main.c�� �ٲ� ����ϼ���.

#include <stdio.h>

void input_data(int *, int *);       // �� ������ �Է��ϴ� �Լ� ����
double average(int, int);            // ����� ���ϴ� �Լ� ����

int main(void)
{
	int a, b;
	double avg;

	input_data(&a, &b);                              // �� ���� �Է�
	avg = average(a, b);                             // ��� ���
	printf("%d�� %d�� ��� : %.1lf\n", a, b, avg);   // �Է°��� ��� ���

	return 0;
}
