// 8�� �迭�� ���� ���� ���� 1��

#include <stdio.h>
#include <string.h>

int main(void)
{
	int score[5];
	int max, min, tot = 0;
	int max_index, min_index;
	int i;
	double avg;

	printf("5�� �ɻ������� ���� �Է� : ");
	for(i=0; i<5; i++)
	{
		scanf("%d", &score[i]);
	}

	max = min = score[0];         // ù ��° ������ �ִ밪�̰� �ּҰ��̶�� ����
	max_index = min_index = 0;    // �ִ밪�� �ּҰ��� ��ġ ���
	for(i=1; i<5; i++)
	{
		if(score[i] > max)
		{
			max = score[i];       // �� ���� ������ max���� ũ�� �ִ밪���� �Ѵ�
			max_index = i;
		}
		if(score[i] < min)
		{
			min = score[i];       // �� ���� ������ min���� ������ �ּҰ����� �Ѵ�
			min_index = i;
		}
	}

	printf("��ȿ���� : ");
	for(i=0; i<5; i++)
	{
		if((i == max_index) || (i == min_index)) continue;   // �ִ밪�̳� �ּҰ��� ����
		printf("%5d", score[i]);                             // ���� ���
		tot += score[i];                                     // ���� ����
	}
	printf("\n");

	printf("��� : %.1lf\n", tot / 3.0);    // �ִ밪�� �ּҰ��� ������ ��� ���

	return 0;
}
