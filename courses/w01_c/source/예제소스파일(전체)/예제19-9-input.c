// ���� �̸��� '����19-9-input.c'���� input.c�� �ٲ� ����ϼ���.

#include <stdio.h>

extern int cnt;                  // main.c ������ ���� ���� cnt ����
int tot = 0;                     // ���� ���� ����

int input_data(void)
{
	int pos;                     // ��� ����

	while (1)
	{
		printf("��� �Է� : ");
		scanf("%d", &pos);       // ��� �Է�
		if (pos < 0) break;      // ������ �Է� ����
		cnt++;                   // ���� ����
		tot += pos;              // �Է°��� ���� ���� tot�� ����
	}

	return tot;                  // ���� ���� tot�� �� ��ȯ
}
