#include <stdio.h>

int *sum(int a, int b);                 // int�� ������ �ּҸ� ��ȯ�ϴ� �Լ� ����

int main(void)
{
	int *p;                             // ��ȯ���� ������ ������

	p = sum(10, 20);                    // ��ȯ�� �ּҴ� p�� ����
	printf("�� ������ �� : %d\n", *p);  // p�� ����Ű�� ������ ���

	return 0;
}

int *sum(int a, int b)                  // int�� ������ �ּҸ� ��ȯ�ϴ� �Լ�
{
	static int res;                     // ���� ���� ����

	res = a + b;                        // �� ������ ���� res�� ����

	return &res;                        // ���� ���� ������ �ּ� ��ȯ
}