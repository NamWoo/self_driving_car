#include <stdio.h>

int main(void)
{
	char str[80];

	printf("���ڿ� �Է� : ");
	scanf("%s", str);                    // %s�� ����ϰ� �迭���� �ش�.
	printf("ù ��° �ܾ� : %s\n", str);  // �迭�� �Էµ� ���ڿ� ���
	scanf("%s", str);
	printf("���ۿ� ���� �ִ� �� ��° �ܾ� : %s\n", str);

	return 0;
}