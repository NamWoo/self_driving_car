#include <stdio.h>

int main(void)
{
	int a = 5, b = 5;
	int pre, post;

	pre = (++a) * 3;     // ������ ���� ������
	post = (b++) * 3;    // ������ ���� ������

	printf("�ʱ갪 a = %d, b = %d\n", a, b);
	printf("������: (+ +a) * 3 = %d, ������: (b + +) * 3 = %d\n", pre, post);

	return 0;
}