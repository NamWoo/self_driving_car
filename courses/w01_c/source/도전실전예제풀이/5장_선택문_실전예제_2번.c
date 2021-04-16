#include <stdio.h>

int main(void)
{
	int rich = 150;
	double grade = 4.1;
	double pay;

	if(rich < 100)
	{
		pay = 100 * 0.6;
	}
	else if(grade >= 4.0)
	{
		pay = 100 * 0.8;
	}

	printf("다음 학기 납입할 등록금은 %.0lf만원입니다.\n", pay);

	return 0;
}