#include <stdio.h>

int get_pos(void);                 // �Լ� ����

int main(void)
{
	int res;

	res = get_pos();               // �Լ� ȣ��, ��ȯ���� res�� ����
	printf("��ȯ�� : %d\n", res);  // ��ȯ�� ���

	return 0;
}

int get_pos(void)                  // �Ű������� ���� ��ȯ���� �ִ�.
{
	int pos;                       // Ű���� �Է°��� ������ ����

	printf("��� �Է� : ");        // �Է� �ȳ� �޽���
	scanf("%d", &pos);             // Ű���� �Է�

	return pos;                    // �Է��� �� ��ȯ
}