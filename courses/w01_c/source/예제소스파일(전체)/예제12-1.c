#include <stdio.h>

int main(void)
{
	printf("�ּҰ� : %p\n", "mango");               // �ּҰ� ���
	printf("ù ��° ���� : %c\n", *"mango");        // �������� ����
	printf("�� ��° ���� : %c\n", *("mango" + 1));  // ������ �����
	printf("�� ��° ���� : %c\n", "mango"[2]);      // �迭 ǥ����

	return 0;
}