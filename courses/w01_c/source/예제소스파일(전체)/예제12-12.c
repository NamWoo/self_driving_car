#include <stdio.h>
#include <string.h>            // strcat, strncat �Լ� ����� ���� ��� ���� ����

int main(void)
{
	char str[80] = "straw";    // ���ڿ� �ʱ�ȭ

	strcat(str, "berry");      // str �迭�� ���ڿ� ���̱�
	printf("%s\n", str);
	strncat(str, "piece", 3);  // str �迭�� 3���� ���� ���̱�
	printf("%s\n", str);

	return 0;
}