#include <stdio.h>

int main(void)
{
	int ary[5];

	printf("ary�� �� : %u\n", ary);      // �ּҷμ��� �迭���� ��
	printf("ary�� �ּ� : %u\n", &ary);   // �迭�� �ּ�
	printf("ary + 1 : %u\n", ary + 1);
	printf("&ary + 1 : %u\n", &ary + 1);

	return 0;
}