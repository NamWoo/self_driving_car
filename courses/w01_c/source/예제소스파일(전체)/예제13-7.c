#include <stdio.h>

void add_ten(int *p);       // �Ű������� ������ ����

int main(void)
{
	int a = 10;

	add_ten(&a);            // a�� �ּҸ� �μ��� �ش�.
	printf("a : %d\n", a);  // ������ a�� ���

	return 0;
}

void add_ten(int *p)        // ������ p�� a�� �ּҸ� �޴´�.
{
	*p = *p + 10;           // ������ p�� ����Ű�� ������ �� 10 ����
}