// 8�� ������������ 1��

#include <stdio.h>
int main(void)
{
	int score[5];
	int valid[3];
	int i,j, l=0;
	int sum=0;
	double average;
	
	printf("5�� �ɻ������� ���� �Է� : ");
	for(i=0;i<5;i++){
	
	scanf("%4d", &score[i]); 
	}
	
	//��ȿ���� ���
	for(i=0;i<5;i++){
		int k=4;
		for(j=0;j<5;j++){
			if(score[i]!=score[j]){
				if(score[i]<score[j]){
					k--;
				}
				else
					k++;
		}
		}
//		printf("%5d%5d",i,k);
//printf("%5d",l);
			if((k<8)&&(k>0)){					
				valid[l]=score[i];
				l++;
			}
	} 
	
	// ������� ���
	for(i=0;i<5;i++){
		
		sum += score[i]; 
		}
		average = sum/5.0;

	printf("��ȿ���� : ");
	
	for(i=0;i<3;i++){
	printf("%5d", valid[i]);
	}
	printf("\n��� : %.1lf\n", average);
	
	return 0;
	
 } 
