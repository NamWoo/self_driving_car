#include <stdio.h>

int main(void)
{
	int ch;              // �Է��� ���ڸ� ������ ����

	while (1)
	{
		ch = getchar();  // Ű���忡�� ���� �Է�
		if (ch == EOF)   // Ctrl + Z�� �Է� ����
		{
			break;
		}
		putchar(ch);     // ȭ�鿡 ���� ���
	}

	return 0;
}