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
int max_bmi(Info **pary, int cnt);				//�Է� ���� �� �ִ�bmi �迭���� ��ġ(index) ��ȯ

double average_weight(Info **pary, int cnt);  	//��� ü�� ��ȯ
double average_height(Info **pary, int cnt);	//��� Ű ��ȯ 
double average_age(Info **pary, int cnt);		//��� ���� ��ȯ 
double average_bmi(Info **pary, int cnt);		//��� bmi ��ȯ 
void prt_average(Info **pary, int cnt);			//��� ��ȯ�� ��� 

void chk_bmi(double check_bmi);
void prt_info(Info **pary, int index);  		//�Է� ���� ���
void prt_list(Info **pary, int index);  		//�Է� ���� ���
void free_ary(Info **pary, int cnt);      		//�����Ҵ� ���� ����



int main(void)
{		
	Info *pary[200];       						

	int max_index;		   
	int cnt;                  
	
	prt_init();									//���� �ȳ��� ��� 
	cnt = input_member(pary);                	//�Է� ���� �ο� �� ��ȯ		
	prt_average(pary, cnt);						//�Է� ���� ��� �� ��� 

	max_index = max_bmi(pary, cnt);       		//�ְ� bmi index ��ȯ
	prt_info(pary, max_index);					//index ���� ���� ��� 
	prt_list(pary, cnt);						//index ��ü ���� ��� 
		
	free_ary(pary, cnt);
}

// ���� ��� �� 
void prt_init(void)								//�ȳ��� �ٹ̱� 
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
	
	for (i=0; i<57; i++)
	{
		printf("*");
		Sleep(25);
	}
	printf("\n");
	printf("*********************************************************\n");
	Sleep(300);
	printf("****�׻� ���� �ϻ� ���İ��� ���� �ʳ���?***************\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("****�����Կ�*Ű��*������*�����*�񸸵���*�˷��帱�״�****\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("****��Ʈ������ ����� Ǯ��ô�.**********************\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
}

int input_member(Info **pary)
{
	Info *tp;
	char name[20];            
	int age, height;
	double weight, bmi, temp;
	int i; 

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
	if (check_bmi < 18.5) printf("���� .. �԰� �ٴϳ���?...�� �� �弼��...\n\n\n");
	else if (check_bmi < 24.9) printf("�����̳�? ���� ���� ���ϸ� �׷��� �Ű��°� ����?(18.5 - 24.9)\n\n\n");
	else if (check_bmi < 29.9) printf("��ü��... �ʾ��� �� �̹� �����ſ���. ���� � �����ϼ��� (25 - 29.9)\n\n\n");
	else if (check_bmi < 34.9) printf("�浵 �� (1�ܰ� ��) ��! ����~��~~! : 30 - 34.9\n\n\n");
	else if (check_bmi < 39.9) printf("�ߵ� ��.. ��¼���� �׷���.. (�ߵ� 2�ܰ� ��) (35 - 39.9)\n\n\n");
	else if (check_bmi < 40) printf("... �� ���ص� ������? �ɰ��Ѱ�?\n\n\n"); //(check_bmi < 40)
	else printf("Ű�� ������ ����� �Է� �� �� �³��� �ٽ�!?");
}


void prt_info(Info **pary, int index)
{
	printf("****�ִ�*ü��*******%8.1f*****************************\n", pary[index]->weight);
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300); 
	printf("****�ִ�*BMI********%8.1f*****************************\n", pary[index]->bmi);
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
}


void prt_average(Info **pary, int cnt)
{
	double avg_height, avg_weight, avg_age, avg_bmi;
	
	avg_height = average_height(pary, cnt);         	// ��� ü�� ��� �� ��ȯ
	avg_weight = average_weight(pary, cnt);				// ��� ü�� ��� �� ��ȯ
	avg_age = average_age(pary, cnt); 
	avg_bmi = average_bmi(pary, cnt);
	
	printf("*********************************************************\n");		
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("****��*�Է�*���*��*%6d*******************************\n", cnt);
	Sleep(300);
	printf("****���*Ű*********%8.1f*****************************\n", avg_height);
	Sleep(300);
	printf("****���*ü��*******%8.1f*****************************\n", avg_weight);
	Sleep(300);
	printf("****���*����*******%8.1f*****************************\n", avg_age);
	Sleep(300);
	printf("****���*BMI********%8.1f*****************************\n", avg_bmi);
	Sleep(300);
	printf("*********************************************************\n");		
	Sleep(300);
}

void prt_list(Info **pary, int cnt)
{
	int i; 
	printf("****%-4s%10s%10s%12s%10s\n", "��ȣ", "�̸�", "Ű(cm)", "ü��(kg)", "BMI");
	Sleep(300);
	printf("----------------------------------------------------------\n");	
	Sleep(300);
	for (i=0; i<cnt; i++)
	{		
		printf("****%4d%10s%10d%12.1f%10.1f\n", i+1, pary[i]->name, pary[i]->height, pary[i]->weight, pary[i]->bmi);	
		Sleep(300);
	}
	printf("*********************************************************\n");
	Sleep(300);
	printf("****�׻� ���� �ϻ� ���İ� �� ����� ��ȯ�� �غ��ô�**\n");
	Sleep(300);
	printf("*********************************************************\n");
}

