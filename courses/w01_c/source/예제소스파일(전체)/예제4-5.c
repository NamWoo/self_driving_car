#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, c = 10;
	int res;                       // ���(result)���� ������ ����

	res = (a > b);                 // a�� b���� ũ�� �����Ƿ� ������� 0
	printf("a > b : %d\n", res);
	res = (a >= b);                // a�� b���� ũ���� �ʰ� ������ �����Ƿ� ������� 0
	printf("a >= b : %d\n", res);
	res = (a < b);                 // a�� b���� �����Ƿ� ������� 1
	printf("a < b : %d\n", res);
	res = (a <= b);                // a�� b���� �����Ƿ� ������� 1
	printf("a <= b : %d\n", res);
	res = (a <= c);                // a�� c���� ������ ������ �����Ƿ� ������� 1
	printf("a <= c : %d\n", res);
	res = (a == b);                // a�� b�� ���� �����Ƿ� ������� 0
	printf("a = = b : %d\n", res);
	res = (a != c);                // a�� c�� �����Ƿ� ������� 0
	printf("a != c : %d\n", res);

	return 0;
}