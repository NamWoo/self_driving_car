#include <stdio.h>

int main(void)
{
	int a = 0, b = 0;

	if (a > 0)              // a�� 0���� ũ�� b�� 1 ����
	{
		b = 1;
	}
	else if (a == 0)        // a�� 0�̸� b�� 2 ����
	{
		b = 2;
	}
	else                    // a�� 0���� ũ�� �ʰ� 0�� �ƴϸ� b�� 3 ����
	{
		b = 3;
	}

	printf("b : %d\n", b);  // if������ ������ b�� ���

	return 0;
}