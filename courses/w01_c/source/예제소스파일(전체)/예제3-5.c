#include <stdio.h>

int main(void)
{
	unsigned int a;

	a = 4294967295;      // ū ��� ����
	printf("%d\n", a);   // %d�� ���
	a = -1;              // ���� ����
	printf("%u\n", a);   // %u�� ���

	return 0;
}