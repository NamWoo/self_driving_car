#include <stdio.h>

typedef union
{
	int ea;                             // 개수
	double kg;                          // 키로그램
	double liter;                       // 리터
} Unit;                                 // Unit 공용체형 재정의

typedef struct
{
	char name[20];                      // 당첨자 이름
	enum { EGG = 1, MILK, MEAT } kind;  // 상품 종류, 열거형 멤버
	Unit amount;                        // 지급양, 공용체 멤버
} Gift;                                 // Gift 구조체 재정의

void print_list(Gift a);

int main(void)
{
	Gift list[5];                       // 5명 경품 지급 명단
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("이름 입력 : ");
		scanf("%s", list[i].name);
		printf("품목 선택(1.계란, 2.우유, 3.고기) : ");
		scanf("%d", &list[i].kind);    // 품목 선택

		switch (list[i].kind)          // 선택 품목에 따라 지급 단위 결정
		{
		case EGG: list[i].amount.ea = 30; break;
		case MILK: list[i].amount.liter = 4.5; break;
		case MEAT: list[i].amount.kg = 0.6; break;
		}
	}
	printf("# 세 번째 경품 당첨자...\n");
	print_list(list[2]);

	return 0;
}

void print_list(Gift a)
{
	printf(" 이름 : %s, 선택 품목 : ", a.name);
	switch (a.kind)                    // 선택 품목에 따라 출력
	{
	case EGG: printf("계란 %d개\n", a.amount.ea); break;
	case MILK: printf("우유 %.1lf리터\n", a.amount.liter); break;
	case MEAT: printf("고기 %.1lfkg\n", a.amount.kg); break;
	}
}