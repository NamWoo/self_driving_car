#if 0
#include <stdio.h>
//����1�� 
int main(void)
{
	int score[5];
	int i, max=0, min=0, tot=0;
	 
	printf("5�� �ɻ������� ���� �Է� : ");
	for(i=0;i<5;i++){
		scanf("%d",&score[i]);
	}
	
	for(i=1;i<5;i++){
		if(score[max]<score[i])
			max=i;
		if(score[min]>score[i])
			min=i;
	}
	printf("��ȿ���� : ");
	
	for(i=0;i<5;i++){
		if(i==max || i==min) continue;
		printf("%d ",score[i]);
		tot+=score[i];
		
	}
	printf("\n��� : %.1lf", (double)tot/3.0);
	
	return 0;
}

#endif
#include <stdio.h>
//����3�� 
int main(void)
{
	int lotto[6]={0,};
	int i, j;
	
	
	for(i=0;i<6;i++){
		printf("�ζǹ�ȣ �Է� :");
		scanf("%d",&lotto[i]);
		for(j=0;j<i;j++){
			if(lotto[i]==lotto[j]){
				printf("���� ��ȣ�� �ֽ��ϴ�!\n");
				lotto[i]=0;
				i--;
				break;
			}
		} 
	}
	
	printf("�Էµ� �ζǹ�ȣ :");
	for(i=0;i<6;i++){
		printf("%d ",lotto[i]);
	}
	
	return 0;
}
