#include <stdio.h>

int main()
{
	int answer,input,count=0;
	
	answer = rand()%30;
	
	while(1)
	{
		printf("input number : ");
		scanf("%d",&input);
		
		if( input > answer)
		{
			printf("%d보다 작습니다.\n",input);
		}
		else if ( input < answer)
		{
			printf("%d보다 큽니다.\n",input);
		}
		else
		{
			printf("정답입니다.\n시도한 횟수는 %d입니다.\n",count);
			break;
		}
		count++;
	}
	
	return 0;
}
