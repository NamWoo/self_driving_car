#include <stdio.h>

void print_char(char ch, int cnt); // �Լ� ����

int main(void)
{
	print_char('@', 5);            // ���ڿ� ���ڸ� �ְ� �Լ� ȣ��

	return 0;
}

void print_char(char ch, int cnt)  // �Ű������� ������ ��ȯ���� ����.
{
	int i;

	for (i = 0; i < cnt; i++)      // i�� 0���� cnt-1���� ����, cnt�� �ݺ�
	{
		printf("%c", ch);          // �Ű����� ch�� ���� ���� ���
	}
}