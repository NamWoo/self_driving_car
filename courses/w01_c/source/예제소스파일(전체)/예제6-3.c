#include <stdio.h>

int main(void)
{
	int a = 1;              // ������ �����ϰ� 1�� �ʱ�ȭ

	do                      // �ݺ��� ���� ��ġ
	{
		a = a * 2;          // a�� ���� 2��� �ø���.
	} while (a < 10);       // a�� 10���� ������ 9���� �ݺ�
	printf("a : %d\n", a);  // �ݺ��� ���� �� a�� ���

	return 0;
}