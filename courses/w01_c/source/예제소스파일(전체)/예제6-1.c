#include <stdio.h>

int main(void)
{
	int a = 1;              // ������ �����ϰ� ������ �ϱ� ���� 1�� �ʱ�ȭ

	while (a < 10)          // a�� 10���� �����Ƿ� ���ǽ��� ��
	{
		a = a * 2;          // a�� 2�� ���� a�� �ٽ� ����
	}
	printf("a : %d\n", a);  // a�� ���

	return 0;
}