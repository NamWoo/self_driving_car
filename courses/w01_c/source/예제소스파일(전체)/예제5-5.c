#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;

	if (a < 0)             // a�� 0���� ������
	{
		if (b > 0)         // b�� 0���� ũ�� ok ���
		{
			printf("ok");
		}
	}
	else                   // a�� 0 �̻��̸� ok ���
	{
		printf("ok");
	}

	return 0;
}