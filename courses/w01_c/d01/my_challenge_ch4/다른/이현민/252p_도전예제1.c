#include<stdio.h>

int main(void)
{
	int i, j, min, max;
	int arr[5];
	int maxIdx, minIdx;
	printf("5 명 심사위원의 점수 입력 : ");
	
	scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
	
	min = arr[0];
	max = arr[0];
	
	for(i = 1; i < 5; i++){
		
		if(min > arr[i]){
			min = arr[i];
			minIdx = i;
		}
		
		if(max < arr[i]){
			max = arr[i];
			maxIdx = i;
		}
		
	}
	
	for(i = 0; i < 5; i++){
		if(minIdx == i || maxIdx == i){
			continue;
		}
		printf("%d", arr[i]);
	}
	
	return 0;
 } 
