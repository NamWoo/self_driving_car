#include <stdio.h>
#include <string.h>                           // strlen �Լ� ����� ���� ��� ���� ����

int main(void)
{
	char str1[80], str2[80];                  // �� ���ڿ��� �Է��� �迭
	char *resp;                               // ���ڿ��� �� �迭�� ������ ������

	printf("2���� ���� �̸� �Է� : ");
	scanf("%s%s", str1, str2);                // 2���� ���ڿ� �Է�
	if (strlen(str1) > strlen(str2))          // �迭�� �Էµ� ���ڿ��� ���� ��
		resp = str1;                          // ù ��° �迭�� �� ��� ����
	else
		resp = str2;                          // �� ��° �迭�� �� ��� ����
	printf("�̸��� �� ������ : %s\n", resp);  // ���õ� �迭�� ���ڿ� ���

	return 0;
}