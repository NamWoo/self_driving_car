#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num;                  // �й�
	char name[20];            // �̸�
	int kor, eng, mat;        // 3���� ����
	int tot;                  // ����
	double avg;               // ���
	char grade;               // ����
} Student;

void input_data(Student *pary);
void calc_data(Student *pary);
void sort_data(Student *pary);
void print_data(Student *pary);

int main(void)
{
	Student ary[5];           // 5�� �л��� ����

	input_data(ary);          // �й�, �̸�, 3���� ���� �Է�
	calc_data(ary);           // ����, ���, ���� ���

	printf("# ���� �� ������...\n");
	print_data(ary);          // ���� �� ���
	sort_data(ary);           // ���� ������ �������� ����
	printf("\n# ���� �� ������...\n");
	print_data(ary);          // ���� �� ���

	return 0;
}

void input_data(Student *pary)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("> �й� : ");
		scanf("%d", &pary->num);
		printf("> �̸� : ");
		scanf("%s", pary->name);
		printf("> ����, ����, ���� ���� : ");
		scanf("%d%d%d", &pary->kor, &pary->eng, &pary->mat);
		pary++;
	}
}

void calc_data(Student *pary)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		pary->tot = pary->kor + pary->eng + pary->mat;
		pary->avg = pary->tot / 3.0;
		if (pary->avg >= 90.0) pary->grade = 'A';
		else if (pary->avg >= 80.0) pary->grade = 'B';
		else if (pary->avg >= 70.0) pary->grade = 'C';
		else pary->grade = 'F';
		pary++;
	}
}

void sort_data(Student *pary)
{
	Student temp;
	int i, j;
	int max;

	for(i = 0; i < 4; i++)
	{
		max = i;
		for(j = i + 1; j < 5; j++)
		{
			if(pary[max].tot < pary[j].tot)
			{
				max = j;
			}
		}
		if(max != i)
		{
			temp = pary[max];
			pary[max] = pary[i];
			pary[i] = temp;
		}
	}
}

void print_data(Student *pary)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("%5d%7s%5d%5d%5d%5d%7.1lf%5c\n", 
			pary->num, pary->name, pary->kor, pary->eng, 
			pary->mat, pary->tot, pary->avg, pary->grade);
		pary++;
	}
}
