#include<stdio.h>
#include <stdlib.h>

void main()
{
	int num,cnt;
//	int answer = 19;
	int answer;
	
	answer = rand()%30+1;
	
	while(1)
	{	
		printf("숫자 입력(1부터 30까지) : ");
		scanf("%d",&num);
		
		if(answer == num){
			printf("정답입니다!\n");	
			printf("시도한 횟수는 %d회 입니다.\n",cnt+1);	
			break;
		}else if(answer > num){
			printf("%d보다 큽니다!\n",num);
			cnt++;
		}else{
			printf("%d보다 작습니다!\n",num);
			cnt++;
		} 
	}	
} 
