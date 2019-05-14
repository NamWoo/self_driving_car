#include <stdio.h>

int main(){
	
	char num[46]={0,};
	int lotto;
	int i;
	
	for(i=0;i<6;){
		printf("로또번호 입력 : ");
		scanf(" %d",&lotto);
		if(num[lotto]){
			printf("같은 번호가 있습니다!\n");
		}
		else{
			num[lotto]=1;
			i++;
		}
	}
	
	
	printf("입력된 로또번호 : ");
	for(i=1;i<46;i++)
		if(num[i]) printf("%4d",i);
	
	
	
	
	
	return 0;
}
