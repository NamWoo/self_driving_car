#include <stdio.h>

int main(void)
{
	int a, b;
	int sum, sub, mul, inv;

	a = 10;        // ���� ����
	b = 20;        // ���� ����
	sum = a + b;   // ���ϱ� ���� �� ���� ����
	sub = a - b;   // ���� ���� �� ���� ����
	mul = a * b;   // ���ϱ� ���� �� ���� ����
	inv = -a;      // ���� ���� �� ���� ����

	printf("a�� �� :%d, b�� �� :%d\n", a, b);
	printf("���� : %d\n", sum);
	printf("���� : %d\n", sub);
	printf("���� : %d\n", mul);
	printf("a�� �������� : %d\n", inv);

	return 0;
}