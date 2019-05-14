#if 0
#include <stdio.h>
//도전1번 
int main(void)
{
	int score[5];
	int i, max=0, min=0, tot=0;
	 
	printf("5명 심사위원의 점수 입력 : ");
	for(i=0;i<5;i++){
		scanf("%d",&score[i]);
	}
	
	for(i=1;i<5;i++){
		if(score[max]<score[i])
			max=i;
		if(score[min]>score[i])
			min=i;
	}
	printf("유효점수 : ");
	
	for(i=0;i<5;i++){
		if(i==max || i==min) continue;
		printf("%d ",score[i]);
		tot+=score[i];
		
	}
	printf("\n평균 : %.1lf", (double)tot/3.0);
	
	return 0;
}

#endif
#include <stdio.h>
//도전3번 
int main(void)
{
	int lotto[6]={0,};
	int i, j;
	
	
	for(i=0;i<6;i++){
		printf("로또번호 입력 :");
		scanf("%d",&lotto[i]);
		for(j=0;j<i;j++){
			if(lotto[i]==lotto[j]){
				printf("같은 번호가 있습니다!\n");
				lotto[i]=0;
				i--;
				break;
			}
		} 
	}
	
	printf("입력된 로또번호 :");
	for(i=0;i<6;i++){
		printf("%d ",lotto[i]);
	}
	
	return 0;
}
