#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;

	printf("��ȯ �� a�� b�� �� : %d, %d\n", a, b);
	{                                               // ��� ����
		int temp;                                   // temp ���� ����

		temp = a;
		a = b;                                      // a�� b�� 5�࿡ ����� ����
		b = temp;
	}                                               // ��� ��
	printf("��ȯ �� a�� b�� �� : %d, %d\n", a, b);

	return 0;
}