#include <stdio.h>

int main(void)
{
	FILE *fp;                                   // ���� ������

	fp = fopen("a.txt", "r");                   // a.txt ������ �б� �������� ����
	if (fp == NULL)                             // fp�� �������͸� ���� ���� ����
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");  // �ȳ� �޽��� ���
		return 1;                               // ���α׷� ����
	}
	printf("������ ���Ƚ��ϴ�.\n");
	fclose(fp);                                 // ���� �ݱ�

	return 0;
}