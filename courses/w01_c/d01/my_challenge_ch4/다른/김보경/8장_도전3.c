#include<stdio.h>

int main(void){
	int ary[46]={0};
	int ary2[6];
	int cnt=0;
	int n;
	while(cnt<6){
		printf("로또번호 입력 : ");
		scanf("%d",&n);
		if(ary[n]){
			printf("같은 번호가 있습니다!\n"); 
		}
		else{
			ary[n]=1;
			ary2[cnt]=n;
			cnt++;
		}
	}
	int i;
	printf("입력된 로또번호 :");
	for(i=0;i<6;i++)
	     printf("%3d",ary2[i]);
}
