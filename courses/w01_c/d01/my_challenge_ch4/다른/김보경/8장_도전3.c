#include<stdio.h>

int main(void){
	int ary[46]={0};
	int ary2[6];
	int cnt=0;
	int n;
	while(cnt<6){
		printf("�ζǹ�ȣ �Է� : ");
		scanf("%d",&n);
		if(ary[n]){
			printf("���� ��ȣ�� �ֽ��ϴ�!\n"); 
		}
		else{
			ary[n]=1;
			ary2[cnt]=n;
			cnt++;
		}
	}
	int i;
	printf("�Էµ� �ζǹ�ȣ :");
	for(i=0;i<6;i++)
	     printf("%3d",ary2[i]);
}
