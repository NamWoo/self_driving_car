
#include<stdio.h>

int main(){
	
	int sc[7];
	int sum=0;
	int min=5,max=6;
	float avr;
	int i;
	
	printf("5�� �ɻ������� ���� �Է� : ");
	
	for(i=0;i<5;i++){
		scanf(" %d", &sc[i]);
	}
	
	sc[5]=10;sc[6]=0;

	for(i=0;i<5;i++){
		max=sc[i]>sc[max]?i:max;
		min=sc[i]<sc[min]?i:min;
	}
	
	sc[max]=0;
	sc[min]=0;
	
	printf("��ȿ���� : ");
	for(i=0;i<5;i++){
		if(sc[i]){
			printf("%4d",sc[i]);
			sum+=sc[i];
		}
	}
	
	avr=(float)sum/3;
	
	printf("\n��� : %.1f \n",avr); 



	return 0;
}



