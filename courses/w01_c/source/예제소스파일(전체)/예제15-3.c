#include <stdio.h>

void print_str(char **pps, int cnt);

int main(void)
{
	char *ptr_ary[] = {"eagle", "tiger", "lion", "squirrel"}; // �ʱ�ȭ
	int count;                                     // �迭 ��� ���� ������ ����

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);  // �迭 ����� �� ���
	print_str(ptr_ary, count);                     // �迭��� �迭 ��� ���� �ְ� ȣ��

	return 0;
}

void print_str(char **pps, int cnt)               // �Ű������� 2�� ������ ���
{
	int i;

	for (i = 0; i < cnt; i++)                      // �迭 ��� ����ŭ �ݺ�
	{
		printf("%s\n", pps[i]);                    // 2�� �����͸� �迭��ó�� ���
	}
}