#include <stdio.h>

int main(void)
{
	char str[80];

	printf("������ ���Ե� ���ڿ� �Է� : ");
	fgets(str, sizeof(str), stdin);             // ���ڿ� �Է�
	printf("�Էµ� ���ڿ��� %s�Դϴ�\n", str);  // ���ڿ� ���

	return 0;
}