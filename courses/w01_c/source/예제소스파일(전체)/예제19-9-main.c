// ���� �̸��� '����19-9-main.c'���� main.c�� �ٲ� ����ϼ���.

#include <stdio.h>

int input_data(void);      // ����� �Է��ϰ� �� ���� ��ȯ
double average(void);      // ����� ���ϴ� �Լ�
void print_data(double);   // ��� �Լ�
int cnt = 0;               // �Է��� ����� �� ����
static int tot = 0;        // �Է��� ����� ��

int main(void)
{
	double avg;            // �Է��� ����� ���

	tot = input_data();    // ����� �Է��ϰ� �� ���� ��ȯ
	avg = average();       // ��� ���
	print_data(avg);

	return 0;
}

void print_data(double avg)
{
	printf(" �Է��� ����� ���� : %d\n", cnt);
	printf(" ��ü �հ� ��� : %d, %.1lf\n", tot, avg);
}
