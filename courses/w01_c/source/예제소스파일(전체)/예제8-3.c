#include <stdio.h>

int main(void)
{
	int score[5];                   // �ټ� ������ ������ �Է��� int�� �迭 ����
	int i;                          // �ݺ� ���� ����
	int tot = 0;                    // ������ ������ ����
	double avg;                     // ����� ������ ����

	for (i = 0; i < 5; i++)         // i�� 0���� 4���� �ټ� �� �ݺ�
	{
		scanf("%d", &score[i]);     // �� �迭 ��ҿ� ���� �Է�
	}

	for (i = 0; i < 5; i++)
	{
		tot += score[i];            // ������ �����Ͽ� ���� ���
	}
	avg = tot / 5.0;                // ��� ���

	for (i = 0; i < 5; i++)
	{
		printf("%5d", score[i]);    // ���� ���
	}
	printf("\n");

	printf("��� : %.1lf\n", avg);  // ��� ���

	return 0;
}