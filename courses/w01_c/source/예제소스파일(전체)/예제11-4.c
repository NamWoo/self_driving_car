#include <stdio.h>

int main(void)
{
	int ch;                    // �Է� ���ڸ� ������ ����

	ch = getchar();            // �Լ��� ��ȯ�ϴ� ���ڸ� �ٷ� ����
	printf("�Է��� ���� : ");
	printf("�Է��� ���� : %s",ch);
	putchar(ch);               // �Է��� ���� ���
	putchar('\n');             // ���๮�� ���

	return 0;
}
