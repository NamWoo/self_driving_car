// ���� �̸��� '����19-8-sub.c'���� sub.c�� �ٲ� ����ϼ���.

#include <stdio.h>                  // printf, scanf �Լ� ����� ���� �ʿ�

void input_data(int *pa, int *pb)   // �� ���� �Է� �Լ�
{
	printf("�� ���� �Է� : ");
	scanf("%d %d", pa, pb);
}

double average(int a, int b)        // ����� ���ϴ� �Լ�
{
	int tot;
	double avg;

	tot = a + b;
	avg = tot / 2.0;

	return avg;
}
