#include <stdio.h>

int main(void)
{
	int a = 20;
	int b = 0;

	if (a > 10)                        // a�� 10���� ũ�Ƿ� ���ǽ��� ��
	{
		b = a;                         // b = a ���Թ� ����
	}

	printf("a : %d, b : %d\n", a, b);  // ������ ����Ǹ� �� ���� ����

	return 0;
}