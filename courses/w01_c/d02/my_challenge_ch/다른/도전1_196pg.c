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
		printf("���� �Է�(1���� 30����) : ");
		scanf("%d",&num);
		
		if(answer == num){
			printf("�����Դϴ�!\n");	
			printf("�õ��� Ƚ���� %dȸ �Դϴ�.\n",cnt+1);	
			break;
		}else if(answer > num){
			printf("%d���� Ů�ϴ�!\n",num);
			cnt++;
		}else{
			printf("%d���� �۽��ϴ�!\n",num);
			cnt++;
		} 
	}	
} 
