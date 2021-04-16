#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num;                  // 회원 번호
	char name[20];            // 이름
	double weight;            // 체중
} Fitness;

int input_member(Fitness **pary);            // 전체 등록 회원 수 반환
double average_weight(Fitness **pary, int cnt);  // 평균 체중 반환
int max_weight(Fitness **pary, int cnt);     // 최대 체중 회원의 배열에서 위치(index) 반환
void print_info(Fitness **pary, int index);  // 회원 정보 출력
void free_ary(Fitness **pary, int cnt);      // 동적할당 영역 해제

int main(void)
{
	Fitness *pary[100];       // 포인터 배열
	double avg;               // 전체 회원의 평균 체중
	int max_index;            // 최고 체중
	int cnt;                  // 총 등록 회원수

	cnt = input_member(pary);                // 회원 등록 후 회원 수 반환
	avg = average_weight(pary, cnt);         // 평균 체중 계산 후 반환
	max_index = max_weight(pary, cnt);       // 최고 체중 반환

	printf("# 총 회원 수 : %d\n", cnt);
	printf("# 평균 체중 : %.1lf\n", avg);
	printf("# 체중이 가장 무거운 회원은?\n");
	print_info(pary, max_index);

	free_ary(pary, cnt);
	return 0;
}

int input_member(Fitness **pary)
{
	Fitness *tp;
	char name[20];            // 이름을 입력 받을 배열
	double weight;            // 체중을 입력 받을 변수
	int id;                   // 회원번호를 입력 받을 변수
	int i;                    // 인원수 누적변수

	for (i = 0;; i++)
	{
		printf("> 회원 번호 : ");
		scanf("%d", &id);
		if (id < 0) break;

		printf("> 이름 입력 : ");
		scanf("%s", name);
		printf("> 체중 입력 : ");
		scanf("%lf", &weight);

		tp = (Fitness *)malloc(sizeof(Fitness));  // 동적할당
		tp->num = id;
		strcpy(tp->name, name);
		tp->weight = weight;
		pary[i] = tp;
	}

	return i;
}

double average_weight(Fitness **pary, int cnt)
{
	double tot_weight = 0;    // 전체 회원 체중
	int i;

	for (i = 0; i < cnt; i++)
	{
		tot_weight += pary[i]->weight;
	}

	return (tot_weight / cnt);
}

int max_weight(Fitness **pary, int cnt)
{
	double max = 0;               // 최고 체중
	int id_save = 0;              // 최고 체중 회원의 index
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
	printf("> 회원 번호 : %d\n", pary[index]->num);
	printf("> 이름 : %s\n", pary[index]->name);
	printf("> 체중 : %.1lf\n", pary[index]->weight);
}

void free_ary(Fitness **pary, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		free(pary[i]);
	}
}