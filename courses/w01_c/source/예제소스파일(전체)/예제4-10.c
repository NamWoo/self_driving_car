#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;
	int res = 2;

	a += 20;          // a�� 20�� ���� ����� �ٽ� a�� ����
	res *= b + 10;    // b�� 10�� ���� ������� res�� ���ϰ� �ٽ� res�� ����

	printf("a = %d, b = %d\n", a, b);
	printf("res = %d\n", res);

	return 0;
}
