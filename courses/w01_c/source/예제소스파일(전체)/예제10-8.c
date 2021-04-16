#include <stdio.h>

void input_ary(double *pa, int size);
double find_max(double *pa, int size);

int main(void)
{
	double ary[5];
	double max;                               // �ִ��� ������ ����

	int size = sizeof(ary) / sizeof(ary[0]);  // �迭 ��� �� ���
	input_ary(ary, size);                     // �迭�� �� �Է�
	max = find_max(ary, size);                // �迭�� �ִ� ��ȯ
	printf("�迭�� �ִ� : %.1lf\n", max);

	return 0;
}

void input_ary(double *pa, int size)          // double �����͸� �Ű������� ����
{
	int i;

	printf("%d���� �Ǽ��� �Է� : ", size);
	for (i = 0; i < size; i++)                // size�� ���� ���� �ݺ� Ƚ�� ����
	{
		scanf("%lf", pa + i);                 // &pa[i]�� ����, �Է��� �迭 ����� �ּҸ� ����
	}
}

double find_max(double *pa, int size)
{
	double max;
	int i;

	max = pa[0];                              // ù ��° �迭 ����� ���� �ִ����� ����
	for (i = 1; i < size; i++)                // �� ��° �迭 ��Һ��� max�� ��
	{
		if (pa[i] > max) max = pa[i];         // ���ο� �迭 ����� ���� max���� ũ�� ����
	}

	return max;                               // �ִ� ��ȯ
}
