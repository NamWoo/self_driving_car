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

typedef struct               					//구조체 선언 
{
	char name[20];               				//이름, 나이, 키, 몸무게, bmi 
	int age;              						
	int height;                  
	double weight;
	double bmi;
} Info;


void prt_init(void);							//최초 안내 
//void restart(void);

int input_member(Info **pary);            		//개인 정보 입력 

int max_weight(Info **pary, int cnt);     		//입력 정보 중 최대몸무게 배열에서 위치(index) 반환
int max_bmi(Info **pary, int cnt);				//입력 정보 중 최대bmi 배열에서 위치(index) 반환

double average_weight(Info **pary, int cnt);  	//평균 체중 반환
double average_height(Info **pary, int cnt);	//평균 키 반환 
double average_age(Info **pary, int cnt);		//평균 나이 반환 
double average_bmi(Info **pary, int cnt);		//평균 bmi 반환 
void prt_average(Info **pary, int cnt);			//평균 반환값 출력 

void chk_bmi(double check_bmi);
void prt_info(Info **pary, int index);  		//입력 정보 출력
void prt_list(Info **pary, int index);  		//입력 정보 출력
void free_ary(Info **pary, int cnt);      		//동적할당 영역 해제



int main(void)
{		
	Info *pary[200];       						

	int max_index;		   
	int cnt;                  
	
	prt_init();									//최초 안내문 출력 
	cnt = input_member(pary);                	//입력 정보 인원 수 반환		
	prt_average(pary, cnt);						//입력 정보 평균 값 출력 

	max_index = max_bmi(pary, cnt);       		//최고 bmi index 반환
	prt_info(pary, max_index);					//index 정보 선택 출력 
	prt_list(pary, cnt);						//index 전체 정보 출력 
		
	free_ary(pary, cnt);
}

// 최초 출력 값 
void prt_init(void)								//안내문 꾸미기 
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
	printf("****항상 같은 일상에 지쳐가고 있진 않나요?***************\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("****몸무게와*키를*가지고*당신의*비만도를*알려드릴테니****\n");
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("****스트레스를 운동으로 풀어봅시다.**********************\n");
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
		tot_bmi += pary[i]->bmi;
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
	if (check_bmi < 18.5) printf("밥은 .. 먹고 다니니?...좀 더 먹어..\n\n\n");
	else if (check_bmi < 24.9) printf("정상이네? 지금 유지 안하면 훅간다?(18.5 - 24.9)\n\n\n");
	else if (check_bmi < 29.9) printf("과체중이야. 늦기전에 빨리 운동해 (25 - 29.9)\n\n\n");
	else if (check_bmi < 34.9) printf("경도 비만 (1단계 비만) 비만! 비이~만~~! : 30 - 34.9\n\n\n");
	else if (check_bmi < 39.9) printf("중도 비만.. 어쩌려고 그래.. (중등 2단계 비만) (35 - 39.9)\n\n\n");
	else if (check_bmi < 40) printf("... 말 안해도 알지? 심각해\n\n\n"); //(check_bmi < 40)
	else printf("키랑 몸무게 제대로 입력 한 거 맞어?");
}


void prt_info(Info **pary, int index)
{
	printf("****최대*체중*******%8.1f*****************************\n", pary[index]->weight);
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300); 
	printf("****최대*BMI********%8.1f*****************************\n", pary[index]->bmi);
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
}


void prt_average(Info **pary, int cnt)
{
	double avg_height, avg_weight, avg_age, avg_bmi;
	
	avg_height = average_height(pary, cnt);         	// 평균 체중 계산 후 반환
	avg_weight = average_weight(pary, cnt);				// 평균 체중 계산 후 반환
	avg_age = average_age(pary, cnt); 
	avg_bmi = average_bmi(pary, cnt);
	
	printf("*********************************************************\n");		
	Sleep(300);
	printf("*********************************************************\n");
	Sleep(300);
	printf("****총*입력*사람*수*%6d*******************************\n", cnt);
	Sleep(300);
	printf("****평균*키*********%8.1f*****************************\n", avg_height);
	Sleep(300);
	printf("****평균*체중*******%8.1f*****************************\n", avg_weight);
	Sleep(300);
	printf("****평균*나이*******%8.1f*****************************\n", avg_age);
	Sleep(300);
	printf("****평균*BMI********%8.1f*****************************\n", avg_bmi);
	Sleep(300);
	printf("*********************************************************\n");		
	Sleep(300);
}

void prt_list(Info **pary, int cnt)
{
	int i; 
	
	printf("****%-4s %8s   %8s    %8s  %8s\n", "번호", "이름", "키(cm)", "체중(kg)", "BMI");
	Sleep(300);
	for (i=0; i<cnt; i++)
	{		
		printf("****%4d %8s %8d   %8.1f      %8.1f\n", i+1, pary[i]->name, pary[i]->height, pary[i]->weight, pary[i]->bmi);
		Sleep(300);
	}
	printf("*********************************************************\n");
	Sleep(300);
	printf("****항상 같은 일상에 지쳐갈 때 운동으로 전환을 해봅시다**\n");
	Sleep(300);
	printf("*********************************************************\n");
}

