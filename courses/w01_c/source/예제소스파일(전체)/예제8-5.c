#include <stdio.h>

int main(void)
{
	char str[80] = "applejam";             // ���ڿ� �ʱ�ȭ

	printf("���� ���ڿ� : %s\n", str);     // �ʱ�ȭ ���ڿ� ���
	printf("���ڿ� �Է� : ");
	scanf("%s", str);                      // ���ο� ���ڿ� �Է�
	printf("�Է� �� ���ڿ� : %s\n", str);  // �Էµ� ���ڿ� ���

	return 0;
}