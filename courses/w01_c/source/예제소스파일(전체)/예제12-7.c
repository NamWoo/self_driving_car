#include <stdio.h>

int main(void)
{
	char str[80] = "apple juice";  // �迭�� ���ڿ� �ʱ�ȭ
	char *ps = "banana";           // �����Ϳ� ���ڿ� ����

	puts(str);                     // apple juice ����ϰ� �� �ٲ�
	fputs(ps, stdout);             // banana�� ���
	puts("milk");                  // banana�� �̾� milk ���

	return 0;
}