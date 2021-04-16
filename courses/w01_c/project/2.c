/*
2019.05.17 week1 day5 ������Ʈ
//  ��������    *�Ϸ�* 
//	�迭        *�Ϸ�* 
//	�����ͺ���  *�Ϸ�* 
//	����ü      *�Ϸ�* 
//	�Լ�ȣ��    *�Ϸ�* 
//	2�����迭   *�Ϸ�* 
/////////////////// 1�� ���ε� 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct               					//����ü ���� 
{
	char name[20];               				//�̸�, ����, Ű, ������, bmi 
	int age;              						
	int height;                  
	double weight;
	double bmi;
} Info;


void prt_init(void);							//���� �ȳ� 
//void restart(void);

int input_member(Info **pary);            		//���� ���� �Է� 

int max_weight(Info **pary, int cnt);     		//�Է� ���� �� �ִ������ �迭���� ��ġ(index) ��ȯ
int max_bmi(Info **pary, int cnt);

double average_weight(Info **pary, int cnt);  	//��� ü�� ��ȯ
double average_height(Info **pary, int cnt);	//��� Ű ��ȯ 
double average_age(Info **pary, int cnt);		//��� ���� ��ȯ 
double average_bmi(Info **pary, int cnt);		//��� bmi ��ȯ 
void prt_average(void);

void chk_bmi(double check_bmi);
void prt_info(Info **pary, int index);  		//�Է� ���� ���
void free_ary(Info **pary, int cnt);      		//�����Ҵ� ���� ����



int main(void)
{		
	Info *pary[200];       						
	double avg_height, avg_weight, avg_age, avg_bmi;
	int max_index;		   
	int cnt;                  
	
	prt_init();
	cnt = input_member(pary);                // �ο� �Է� �� ȸ�� �� ��ȯ	
	
	avg_height = average_height(pary, cnt);         // ��� ü�� ��� �� ��ȯ
	avg_weight = average_weight(pary, cnt); // ��� ü�� ��� �� ��ȯ
	avg_age = average_age(pary, cnt); 
	avg_bmi = average_bmi(pary, cnt); 
	
	max_index = max_bmi(pary, cnt);       // �ְ� bmi ��ȯ

	printf("****��*�Է�*���*��*%6d***************************\n", cnt);
	Sleep(300);
	printf("****���*Ű*********%8.1f*************************\n", avg_height);
	Sleep(300);
	printf("****���*ü��*******%8.1f*************************\n", avg_weight);
	Sleep(300);
	printf("****���*����*******%8.1f*************************\n", avg_age);
	Sleep(300);
	printf("****���*BMI********%8.1f*************************\n", avg_bmi);
//	chk_bmi(avg_bmi);
	prt_info(pary, max_index);
	free_ary(pary, cnt);

}

// ���� ��� �� 
void prt_init(void)
{		
	int i, j;
	
	for (i=0; i<5; i++)
	{
		for (j=0; j<5;j++)
		{
			if ((i==j)||(i+j==4)) printf("*");
			else printf(" ");
			Sleep(10);
		}
		printf("\n");		
	}

	printf("*********************************************************\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("****�����Կ�*Ű��*������*�����*�񸸵���*�˷��帳�ϴ�****\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
}

int input_member(Info **pary)
{
	Info *tp;
	char name[20];            // �̸��� �Է� ���� �迭
	int age, height;
	double weight, bmi, temp;
	int i; // �ο��� ��������

	for (i = 0;; i++)
	{	
		printf("****�̸��� �Է��ϼ���(end ġ�� �� ����)*************(1/4)\n");
		scanf("%s", name);		
		if (strcmp(name,"end")==0) break;
		printf("*********************************************************\n");
		Sleep(300);
		printf("****���� �Է��ϼ���*********************************(2/5)\n");
		scanf("%d", &age);
		printf("*********************************************************\n");
		Sleep(300);
		printf("****Ű��*�Է��ϼ���*********************************(3/4)\n");
		scanf("%d", &height);
		printf("*********************************************************\n");
		Sleep(300);
		printf("****�����Ը�*�Է��ϼ���*****************************(4/4)\n");
		scanf("%lf", &weight);
		printf("*********************************************************\n");
		Sleep(300);
		printf("*********************************************************\n");		
		Sleep(300);
		bmi = (weight/((height*0.01)*(height*0.01)));
		printf("****�����*BMI��****%5.1lf*******************************\n\n\n",bmi);
		chk_bmi(bmi);

		tp = (Info *)malloc(sizeof(Info));
		strcpy(tp->name, name);
		tp->age = age;
		tp->height = height;
		tp->weight = weight;
		tp->bmi = bmi;
		pary[i] = tp;
	}

	return i;
}

double average_weight(Info **pary, int cnt)
{
	double tot_weight = 0;    // ��ü ȸ�� ü��
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_weight += pary[i]->weight;
	}

	return (tot_weight / cnt);
}

double average_height(Info **pary, int cnt)
{
	double tot_height = 0;    // ��ü ȸ�� ü��
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_height += pary[i]->height;
	}

	return (tot_height / cnt);
}

double average_age(Info **pary, int cnt)
{
	double tot_age = 0;    // ��ü ȸ�� ü��
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_age += pary[i]->age;
	}

	return (tot_age / cnt);
}

double average_bmi(Info **pary, int cnt)
{
	double tot_bmi = 0;    // ��ü ȸ�� ü��
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_bmi += pary[i]->bmi;
	}

	return (tot_bmi / cnt);
}

int max_bmi(Info **pary, int cnt)
{
	double max = 0;               // �ְ� ü��
	int id_save = 0;              // �ְ� ü�� ȸ���� index
	int i;

	for (i = 0; i < cnt; i++)
	{
		if (pary[i]->bmi > max)
		{
			max = pary[i]->bmi;
			id_save = i;
		}
	}

	return id_save;
}

void free_ary(Info **pary, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		free(pary[i]);
	}
}

void chk_bmi(double check_bmi)
{
	if (check_bmi < 18.5) printf("���� .. �԰� �ٴϴ�?...?\n\n\n");
	else if (check_bmi < 24.9) printf("�����̳�? (18.5 - 24.9)\n\n\n");
	else if (check_bmi < 29.9) printf("��ü���̾�. �� �Ű��� ���� ��� (25 - 29.9)\n\n\n");
	else if (check_bmi < 34.9) printf("�浵 �� (1�ܰ� ��) : 30 - 34.9\n\n\n");
	else if (check_bmi < 39.9) printf("���� ���� ���ϸ� ū�� ��! �ߵ� 2�ܰ� �� (35 - 39.9)\n\n\n");
	else if (check_bmi < 40) printf("... �� ���ص� ����? �ɰ���\n\n\n"); //(check_bmi < 40)
}


void prt_info(Info **pary, int index)
{
	printf("> ȸ�� ��ȣ : %s\n", pary[index]->name);
	printf("> �̸� : %s\n", pary[index]->name);
	printf("> ü�� : %.1lf\n", pary[index]->weight);
}

