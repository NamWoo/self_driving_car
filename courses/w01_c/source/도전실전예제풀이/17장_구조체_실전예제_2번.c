#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num;                  // ȸ�� ��ȣ
	char name[20];            // �̸�
	double weight;            // ü��
} Fitness;

int input_member(Fitness **pary);            // ��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness **pary, int cnt);  // ��� ü�� ��ȯ
int max_weight(Fitness **pary, int cnt);     // �ִ� ü�� ȸ���� �迭���� ��ġ(index) ��ȯ
void print_info(Fitness **pary, int index);  // ȸ�� ���� ���
void free_ary(Fitness **pary, int cnt);      // �����Ҵ� ���� ����

int main(void)
{
	Fitness *pary[100];       // ������ �迭
	double avg;               // ��ü ȸ���� ��� ü��
	int max_index;            // �ְ� ü��
	int cnt;                  // �� ��� ȸ����

	cnt = input_member(pary);                // ȸ�� ��� �� ȸ�� �� ��ȯ
	avg = average_weight(pary, cnt);         // ��� ü�� ��� �� ��ȯ
	max_index = max_weight(pary, cnt);       // �ְ� ü�� ��ȯ

	printf("# �� ȸ�� �� : %d\n", cnt);
	printf("# ��� ü�� : %.1lf\n", avg);
	printf("# ü���� ���� ���ſ� ȸ����?\n");
	print_info(pary, max_index);

	free_ary(pary, cnt);
	return 0;
}

int input_member(Fitness **pary)
{
	Fitness *tp;
	char name[20];            // �̸��� �Է� ���� �迭
	double weight;            // ü���� �Է� ���� ����
	int id;                   // ȸ����ȣ�� �Է� ���� ����
	int i;                    // �ο��� ��������

	for (i = 0;; i++)
	{
		printf("> ȸ�� ��ȣ : ");
		scanf("%d", &id);
		if (id < 0) break;

		printf("> �̸� �Է� : ");
		scanf("%s", name);
		printf("> ü�� �Է� : ");
		scanf("%lf", &weight);

		tp = (Fitness *)malloc(sizeof(Fitness));  // �����Ҵ�
		tp->num = id;
		strcpy(tp->name, name);
		tp->weight = weight;
		pary[i] = tp;
	}

	return i;
}

double average_weight(Fitness **pary, int cnt)
{
	double tot_weight = 0;    // ��ü ȸ�� ü��
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_weight += pary[i]->weight;
	}

	return (tot_weight / cnt);
}

int max_weight(Fitness **pary, int cnt)
{
	double max = 0;               // �ְ� ü��
	int id_save = 0;              // �ְ� ü�� ȸ���� index
	int i;

	for (i = 0; i < cnt; i++)
	{
		if (pary[i]->weight > max)
		{
			max = pary[i]->weight;
			id_save = i;
		}
	}

	return id_save;
}

void print_info(Fitness **pary, int index)
{
	printf("> ȸ�� ��ȣ : %d\n", pary[index]->num);
	printf("> �̸� : %s\n", pary[index]->name);
	printf("> ü�� : %.1lf\n", pary[index]->weight);
}

void free_ary(Fitness **pary, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		free(pary[i]);
	}
}