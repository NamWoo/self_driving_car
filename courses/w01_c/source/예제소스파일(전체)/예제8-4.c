#include <stdio.h>

int main(void)
{
	int score[5];
	int i;
	int tot = 0;
	double avg;
	int cnt;                                 // �迭 ��� ���� ������ ����
	 
	cnt = sizeof(score) / sizeof(score[0]);  // �迭 ��� �� ���

	for (i = 0; i < cnt; i++)                // 11�࿡�� ����� cnt��ŭ �ݺ�
	{
		scanf("%d", &score[i]);
	}

	for (i = 0; i < cnt; i++)                // 11�࿡�� ����� cnt��ŭ �ݺ�
	{
		tot += score[i];
	}
	avg = tot / (double)cnt;                 // ������ cnt�� ������ ��� ���

	for (i = 0; i < cnt; i++)                // 11�࿡�� ����� cnt��ŭ �ݺ�
	{
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("��� : %.1lf\n", avg);

	return 0;
}