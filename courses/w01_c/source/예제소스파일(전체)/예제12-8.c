#include <stdio.h>
#include <string.h>                      // strcpy �Լ��� ����ϱ� ���� ��Ŭ�����

int main(void)
{
	char str1[80] = "strawberry";        // char �迭�� ���ڿ� �ʱ�ȭ
	char str2[80] = "apple";             // char �迭�� ���ڿ� �ʱ�ȭ
	char *ps1 = "banana";                // �����ͷ� ���ڿ� ��� ����
	char *ps2 = str2;                    // �����ͷ� �迭 ����

	printf("���� ���ڿ� : %s\n", str1);
	strcpy(str1, str2);                  // �ٸ� char �迭�� ���ڿ� ����
	printf("�ٲ� ���ڿ� : %s\n", str1);

	strcpy(str1, ps1);                   // ���ڿ� ����� ������ ������ ���
	printf("�ٲ� ���ڿ� : %s\n", str1);

	strcpy(str1, ps2);                   // �迭�� ������ ������ ���
	printf("�ٲ� ���ڿ� : %s\n", str1);

	strcpy(str1, "banana");              // ���ڿ� ��� ���
	printf("�ٲ� ���ڿ� : %s\n", str1);

	return 0;
}