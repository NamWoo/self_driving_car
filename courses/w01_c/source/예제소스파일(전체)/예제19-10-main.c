// ���� �̸��� '����19-10-main.c'���� main.c�� �ٲ� ����ϼ���.

#include <stdio.h>
#include "point.h"                       // Point ����ü ����
#include "line.h"                        // Line ����ü ����

int main(void)
{
	Line a = { {1, 2}, {5, 6} };         // Line ����ü ���� �ʱ�ȭ
	Point b;                             // ��� ���� ��ǥ ����

	b.x = (a.first.x + a.second.x) / 2;  // ��� ���� x��ǥ ���
	b.y = (a.first.y + a.second.y) / 2;  // ��� ���� y��ǥ ���
	printf("���� ��� ���� ��ǥ : (%d, %d)\n", b.x, b.y);

	return 0;
}
