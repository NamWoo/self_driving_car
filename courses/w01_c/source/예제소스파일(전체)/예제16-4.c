#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char temp[80];     // �ӽ� char �迭
	char *str[3];      // ���� �Ҵ� ������ ������ ������ �迭
	int i;             // �ݺ� ���� ����

	for (i = 0; i < 3; i++)
	{
		printf("���ڿ��� �Է��ϼ��� : ");
		gets(temp);                                 // ���ڿ� �Է�
		str[i] = (char *)malloc(strlen(temp) + 1);  // ���ڿ� ���� ���� �Ҵ�
		strcpy(str[i], temp);                       // ���� �Ҵ� ������ ���ڿ� ����
	}

	for (i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);                     // �Էµ� ���ڿ� ���
	}

	for (i = 0; i < 3; i++)
	{
		free(str[i]);                               // ���� �Ҵ� ���� ��ȯ
	}

	return 0;
}