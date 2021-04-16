// 8장 배열의 도전 실전 예제 1번

#include <stdio.h>
#include <string.h>

int main(void)
{
	int score[5];
	int max, min, tot = 0;
	int max_index, min_index;
	int i;
	double avg;

	printf("5명 심사위원의 점수 입력 : ");
	for(i=0; i<5; i++)
	{
		scanf("%d", &score[i]);
	}

	max = min = score[0];         // 첫 번째 점수가 최대값이고 최소값이라고 가정
	max_index = min_index = 0;    // 최대값과 최소값의 위치 기억
	for(i=1; i<5; i++)
	{
		if(score[i] > max)
		{
			max = score[i];       // 이 후의 점수가 max보다 크면 최대값으로 한다
			max_index = i;
		}
		if(score[i] < min)
		{
			min = score[i];       // 이 후의 점수가 min보다 작으면 최소값으로 한다
			min_index = i;
		}
	}

	printf("유효점수 : ");
	for(i=0; i<5; i++)
	{
		if((i == max_index) || (i == min_index)) continue;   // 최대값이나 최소값은 제외
		printf("%5d", score[i]);                             // 점수 출력
		tot += score[i];                                     // 점수 누적
	}
	printf("\n");

	printf("평균 : %.1lf\n", tot / 3.0);    // 최대값과 최소값을 제거한 평균 계산

	return 0;
}
