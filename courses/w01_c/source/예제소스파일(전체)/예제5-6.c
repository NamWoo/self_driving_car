#include <stdio.h>

int main(void)
{
	int rank = 2, m = 0;

	switch (rank)      // rank�� ���� ������ Ȯ��
	{
	case 1:            // rank�� 1�̸�
		m = 300;       // m = 300�� �����ϰ�
		break;         // ����� ��� 23������ �̵�
	case 2:            // rank�� 2��
		m = 200;       // m = 200�� �����ϰ�
		break;         // ����� ��� 23������ �̵�
	case 3:            // rank�� 3�̸�
		m = 100;       // m = 100�� �����ϰ�
		break;         // ����� ��� 23������ �̵�
	default:           // rank�� ��ġ�ϴ� case�� ���� ������
		m = 10;        // m = 10�� �����ϰ�
		break;         // ����� ��� 23������ �̵�
	}

	printf("m : %d\n", m);

	return 0;
}