#include <stdio.h>

int main(void)
{
	int a = 10;

	if (a >= 0)
	{
		a = 1;       // a�� 0���� ũ�ų� ������ a�� 1 ����
	}
	else
	{
		a = -1;      // a�� 0���� ������ a�� -1 ����
	}

	printf("a : %d\n", a);

	return 0;
}