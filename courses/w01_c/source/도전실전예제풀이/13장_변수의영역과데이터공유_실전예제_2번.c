#include <stdio.h>

enum { AM, PM };

void set(int h, int m);  // 최초 시간과 분을 설정하는 함수
void show(void);         // 시간과 분을 화면에 출력하는 함수
void move(void);         // 한 번 호출될 때마다 1분씩 시간 증가

int hour, min, apm;


int main(void)
{
	int hour, min;
	int i, elapsed;

	printf("> 최초 시간과 분 입력(24시간) : ");
	scanf("%d%d", &hour, &min);
	set(hour, min);
	printf("> 설정된 시간 : ");
	show();

	printf("> 경과 시간 입력(분) : ");
	scanf("%d", &elapsed);

	for(i = 0; i < elapsed; i++)
	{
		move();
	}
	printf("> 현재 시간 : ");
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