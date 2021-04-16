#include <stdio.h>

enum { AM, PM };

void set(int h, int m);  // ���� �ð��� ���� �����ϴ� �Լ�
void show(void);         // �ð��� ���� ȭ�鿡 ����ϴ� �Լ�
void move(void);         // �� �� ȣ��� ������ 1�о� �ð� ����

int hour, min, apm;


int main(void)
{
	int hour, min;
	int i, elapsed;

	printf("> ���� �ð��� �� �Է�(24�ð�) : ");
	scanf("%d%d", &hour, &min);
	set(hour, min);
	printf("> ������ �ð� : ");
	show();

	printf("> ��� �ð� �Է�(��) : ");
	scanf("%d", &elapsed);

	for(i = 0; i < elapsed; i++)
	{
		move();
	}
	printf("> ���� �ð� : ");
	show();

	return 0;
}

void set(int h, int m)
{
	if( (h >= 0 && h < 12) || h == 24) apm = AM;
	else apm = PM;

	if(h == 12) hour = h;
	else hour = h % 12;

	min = m;
}

void show(void)
{
	char *cp;

	if(apm == AM) cp = "AM";
	else cp = "PM";

	printf("%02d:%02d(%s)\n", hour, min, cp);
}

void move(void)
{
	min++;
	if(min == 60)
	{
		hour++;
		min = 0;
		if(hour == 12)
		{
			if(apm == AM)
			{
				apm = PM;
			}
			else
			{
				apm = AM;
				hour = 0;
			}
		}
	}
}