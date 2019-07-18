// 8장 도전실전예제 3번

#include <stdio.h>
int main(void)
{
	int lotto[6];
	int i,j;
	for(i=0;i<6;i++){
		printf("로또번호 입력 : ");	
		scanf("%d", &lotto[i]);
			for(j=0;j<i;j++){
						if(lotto[i]==lotto[j]){
							printf("같은 번호가 있습니다!\n");
							i--;
							break;
						}
			}
	}
	printf("입력된 로또번호 :");
	for(i=0;i<6;i++){
	printf("%6d", lotto[i]);		
	}
	
	return 0;
}
