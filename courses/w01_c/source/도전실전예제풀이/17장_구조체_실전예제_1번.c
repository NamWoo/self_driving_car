#include <stdio.h>

struct money_box     // ������ ������ ������ ����ü
{
	int w500;        // 500�� ������ �� ����
	int w100;        // 100�� ������ �� ����
	int w50;         // 50�� ������ �� ����
	int w10;         // 10�� ������ �� ����
};
typedef struct money_box MoneyBox;  // MoneyBox�� �� ������

void init(MoneyBox *s);    // MoneyBox ���� �ʱ�ȭ
void save(MoneyBox *s, int unit, int cnt);   // MoneyBox ������ 
int total(MoneyBox *s);

int main(void)
{
	MoneyBox yuni;
	int unit, cnt, tot;

	init(&yuni);

	while (1)
	{
		printf("������ �ݾװ� ���� : ");
		scanf("%d", &unit);
		if (unit <= 0) break;
		scanf("%d", &cnt);
		save(&yuni, unit, cnt);
	}

	tot = total(&yuni);
	printf("�� ���ݾ� : %d��\n", tot);

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
