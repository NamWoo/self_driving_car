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
			printf("%d���� �۽��ϴ�.\n",input);
		}
		else if ( input < answer)
		{
			printf("%d���� Ů�ϴ�.\n",input);
		}
		else
		{
			printf("�����Դϴ�.\n�õ��� Ƚ���� %d�Դϴ�.\n",count);
			break;
		}
		count++;
	}
	
	return 0;
}
