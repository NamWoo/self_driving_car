#include <stdio.h>

int main(){
	
	char num[46]={0,};
	int lotto;
	int i;
	
	for(i=0;i<6;){
		printf("�ζǹ�ȣ �Է� : ");
		scanf(" %d",&lotto);
		if(num[lotto]){
			printf("���� ��ȣ�� �ֽ��ϴ�!\n");
		}
		else{
			num[lotto]=1;
			i++;
		}
	}
	
	
	printf("�Էµ� �ζǹ�ȣ : ");
	for(i=1;i<46;i++)
		if(num[i]) printf("%4d",i);
	
	
	
	
	
	return 0;
}
