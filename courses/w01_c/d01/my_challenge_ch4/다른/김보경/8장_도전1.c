#include<stdio.h>

int main(void){
	int ary[5];
	int i;
	int minimum=2000000000,maximum=-1;
	int sum=0;
	int cnt=0;
	printf("5�� �ɻ������� ���� �Է� : ");
	for(i=0;i<5;i++){
		scanf("%d",&ary[i]);
		if(maximum<ary[i]){
			maximum=ary[i];
		}
		if(minimum>ary[i]){
			minimum=ary[i];
		}
	}
	
	printf("��ȿ���� : ");
	for(i=0;i<5;i++){
		if(ary[i]!=minimum && ary[i]!=maximum){
			printf("%3d",ary[i]);
			sum+=ary[i];
			cnt++;
		}
	}
	printf("\n��� : %.1lf",(double)sum/(double)cnt);
}
