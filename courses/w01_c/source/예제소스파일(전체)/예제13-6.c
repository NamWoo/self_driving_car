#include <stdio.h>

void add_ten(int a);        // �Լ� ����

int main(void)
{
	int a = 10;

	add_ten(a);             // a���� �����Ͽ� ����
	printf("a : %d\n", a);

	return 0;
}

void add_ten(int a)         // 7���� a�� �ٸ� �������� ���� ���� �Ҵ�
{
	a = a + 10;             // 15���� �Ű����� a�� 10�� ���Ѵ�.
}