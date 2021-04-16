#include <stdio.h>

double average(double a,double b, double c){
	return (a+b+c)/3;
}

int main(void){
	int arr[5] = {0};
	double arr2[3] = {0};
	int i;
	printf("5명 심사위원의 점수 입력: ");
	 
	
	for(i = 0; i<5; i++){
		scanf("%d", &arr[i]);
	}

	int max =0;
	int min =100;
	for(i = 0; i<5; i++){
		if(arr[i]>max){
			max = arr[i];
		}
		if(arr[i]<min){
			min = arr[i];
		}
	}
	
	printf("유효 점수: ");
	int ind = 0;
	for(i=0; i<5; i++){
		if( (arr[i]==max) || (arr[i] == min)){
			continue;
		}
		else {
			arr2[ind] = arr[i];
			ind++;
			printf("%d ", arr[i]);
		}
	}
	printf("\n평균: %.1lf\n",average(arr2[0],arr2[1],arr2[2]));
	
	
	return 0;
}
