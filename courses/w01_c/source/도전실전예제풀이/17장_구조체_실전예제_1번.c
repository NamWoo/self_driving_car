#include <stdio.h>

struct money_box     // 동전을 저금을 저금통 구조체
{
	int w500;        // 500원 동전의 수 저장
	int w100;        // 100원 동전의 수 저장
	int w50;         // 50원 동전의 수 저장
	int w10;         // 10원 동전의 수 저장
};
typedef struct money_box MoneyBox;  // MoneyBox로 형 재정의

void init(MoneyBox *s);    // MoneyBox 변수 초기화
void save(MoneyBox *s, int unit, int cnt);   // MoneyBox 변수에 
int total(MoneyBox *s);

int main(void)
{
	MoneyBox yuni;
	int unit, cnt, tot;

	init(&yuni);

	while (1)
	{
		printf("동전의 금액과 개수 : ");
		scanf("%d", &unit);
		if (unit <= 0) break;
		scanf("%d", &cnt);
		save(&yuni, unit, cnt);
	}

	tot = total(&yuni);
	printf("총 저금액 : %d원\n", tot);

	return 0;
}

void init(MoneyBox *s)
{
	s->w500 = s->w100 = s->w50 = s->w10 = 0;
}

void save(MoneyBox *s, int unit, int cnt)
{
	if (unit == 500) s->w500 += cnt;
	else if (unit == 100) s->w100 += cnt;
	else if (unit == 50) s->w50 += cnt;
	else if (unit == 10) s->w10 += cnt;
}

int total(MoneyBox *s)
{
	int sum = 0;

	sum += s->w500 * 500;
	sum += s->w100 * 100;
	sum += s->w50 * 50;
	sum += s->w10 * 10;

	return sum;
}
