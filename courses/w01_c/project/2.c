/*
2019.05.17 week1 day5 프로젝트
//  변수선언    *완료* 
//	배열        *완료* 
//	포인터변수  *완료* 
//	구조체      *완료* 
//	함수호출    *완료* 
//	2차원배열   *완료* 
/////////////////// 1차 업로드 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct               
{
	char name[20];               
	int age;              
	int height;                  
	double weight;
	double bmi;
} Info;


void prt_init(void);					
void restart(void);

int input_member(Info **pary);            // 사람 입력 

int max_weight(Info **pary, int cnt);     // 최대 체중 회원의 배열에서 위치(index) 반환

double average_weight(Info **pary, int cnt);  // 평균 체중 반환
double average_height(Info **pary, int cnt);
double average_age(Info **pary, int cnt);
double average_bmi(Info **pary, int cnt);

int max_bmi(Info **pary, int cnt);

void chk_bmi(double check_bmi);
void print_info(Info **pary, int index);  // 회원 정보 출력
void free_ary(Info **pary, int cnt);      // 동적할당 영역 해제

int main(void)
{		
	Info *pary[200];       // 포인터 배열
	double avg_height, avg_weight, avg_age, avg_bmi;
	int max_index;		   // 최고 bmi 
	int cnt;                  // 총 입력인원 
	
	prt_init();
	cnt = input_member(pary);                // 인원 입력 후 회원 수 반환	
	
	avg_height = average_height(pary, cnt);         // 평균 체중 계산 후 반환
	avg_weight = average_weight(pary, cnt); // 평균 체중 계산 후 반환
	avg_age = average_age(pary, cnt); 
	avg_bmi = average_bmi(pary, cnt); 
	
	max_index = max_bmi(pary, cnt);       // 최고 bmi 반환

	printf("****총*입력*사람*수*%8d*********************\n", cnt);
	Sleep(300);
	printf("****평균*키*%8.1f*********************\n", avg_height);
	Sleep(300);
	printf("****평균*체중*%8.1f*********************\n", avg_weight);
	Sleep(300);
	printf("****평균*나이*%8.1f*********************\n", avg_age);
	Sleep(300);
	printf("****평균*BMI*%8.1f*********************\n", avg_bmi);
//	chk_bmi(avg_bmi);
	
	free_ary(pary, cnt);

}

// 최초 출력 값 
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
	printf("****몸무게와*키를*가지고*당신의*비만도를*알려드립니다****\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
}

int input_member(Info **pary)
{
	Info *tp;
	char name[20];            // 이름을 입력 받을 배열
	int age, height;
	double weight, bmi, temp;
	int i; // 인원수 누적변수

	for (i = 0;; i++)
	{	
		printf("****이름을 입력하세요(end 치면 총 정리)*************(1/4)\n");
		scanf("%s", name);		
		if (strcmp(name,"end")==0) break;
		printf("*********************************************************\n");
		Sleep(300);
		printf("****나이 입력하세요*********************************(2/5)\n");
		scanf("%d", &age);
		printf("*********************************************************\n");
		Sleep(300);
		printf("****키를*입력하세요*********************************(3/4)\n");
		scanf("%d", &height);
		printf("*********************************************************\n");
		Sleep(300);
		printf("****몸무게를*입력하세요*****************************(4/4)\n");
		scanf("%lf", &weight);
		printf("*********************************************************\n");
		Sleep(300);
		printf("*********************************************************\n");		
		Sleep(300);
		bmi = (weight/((height*0.01)*(height*0.01)));
		printf("****당신의*BMI는****%5.1lf*******************************\n\n\n",bmi);
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
	double tot_weight = 0;    // 전체 회원 체중
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_weight += pary[i]->weight;
	}

	return (tot_weight / cnt);
}

double average_height(Info **pary, int cnt)
{
	double tot_height = 0;    // 전체 회원 체중
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_height += pary[i]->height;
	}

	return (tot_height / cnt);
}

double average_age(Info **pary, int cnt)
{
	double tot_age = 0;    // 전체 회원 체중
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_age += pary[i]->age;
	}

	return (tot_age / cnt);
}

double average_bmi(Info **pary, int cnt)
{
	double tot_bmi = 0;    // 전체 회원 체중
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_bmi += pary[i]->weight;
	}

	return (tot_bmi / cnt);
}

int max_bmi(Info **pary, int cnt)
{
	double max = 0;               // 최고 체중
	int id_save = 0;              // 최고 체중 회원의 index
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
	if ((check_bmi < 18.5) || (check_bmi <40) ) printf("... 말 안해도 알지? 심각해\n\n\n");
	else if (check_bmi < 24.9) printf("정상이네? (18.5 - 24.9)\n\n\n");
	else if (check_bmi < 29.9) printf("과체중이야. 곧 훅간다 빨리 운동해 (25 - 29.9)\n\n\n");
	else if (check_bmi < 34.9) printf("경도 비만 (1단계 비만) : 30 - 34.9\n\n\n");
	else if (check_bmi < 39.9) printf("지금 관리 안하면 큰일 나! 중등 2단계 비만 (35 - 39.9)\n\n\n");
}

