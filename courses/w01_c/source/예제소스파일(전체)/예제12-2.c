#include <stdio.h>

int main(void)
{
	char *dessert = "apple";                     // �����Ϳ� ���ڿ� �ʱ�ȭ

	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);  // ���ڿ� ���
	dessert = "banana";                          // ���ο� ���ڿ� ����
	printf("���� �Ľ��� %s�Դϴ�.\n", dessert);  // �ٲ� ���ڿ� ���

	return 0;
}