#include <stdio.h>

int main(void)
{
	int a;                                   // int�� ���� ����
	double b;                                // double�� ���� ����
	char c;                                  // char�� ���� ����

	printf("int�� ������ �ּ� : %u\n", &a);  // �ּ� �����ڷ� �ּ� ���
	printf("double�� ������ �ּ� : %u\n", &b);
	printf("char�� ������ �ּ� : %u\n", &c);

	return 0;
}