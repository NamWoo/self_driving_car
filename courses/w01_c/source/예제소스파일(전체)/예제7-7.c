#include <stdio.h>

void fruit(int n);

int main(void)
{
	fruit(1);            // ó�� ȣ���ϹǷ� 1�� �μ��� �ش�.

	return 0;
}

void fruit(int n)        // ȣ�� Ƚ���� �Ű������� ����
{
	printf("apple\n");
	if (n == 3) return;  // ȣ�� Ƚ���� 3�̸� ��ȯ�ϰ� ������.
	fruit(n + 1);        // ��ȣ���� �� ȣ�� Ƚ���� 1 ����
	printf("jam\n");
}