#include <stdio.h>

#define SUM(a, b) ((a) + (b))    // �� ���� ���ϴ� ��ũ�� �Լ�
#define MUL(a, b) ((a) * (b))    // �� ���� ���ϴ� ��ũ�� �Լ�

int main(void)
{
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a, b));  // a�� b�� ��
	printf("x + y = %d\n", SUM(x, y));  // x�� y�� ��
	res = 30 / MUL(2, 5);               // 30�� 2�� 5�� ������ ����
	printf("res : %d\n", res);

	return 0;
}