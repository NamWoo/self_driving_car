#include <stdio.h>

int main(void)
{
	int a = 10, b = 5;
	int res;

	res = a / b * 2;            // �켱������ �����Ƿ� ���ʺ��� ���ʷ� ����
	printf("res = %d\n", res);
	res = ++a * 3;              // a�� ���� 1������Ű�� 3�� ���Ѵ�.
	printf("res = %d\n", res);
	res = a > b && a != 5;      // a > b�� ����� a != 5�� ����� && ����
	printf("res = %d\n", res);
	res = a % 3 == 0;           // a % 3�� ���� 0�� ������ Ȯ��
	printf("res = %d\n", res);

	return 0;
}