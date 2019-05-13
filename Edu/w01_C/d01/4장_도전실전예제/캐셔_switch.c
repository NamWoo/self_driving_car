//캐셔프로그램 

#include <stdio.h>



 
int main(void)
{
	int item1, item2, item3;
	int sum, i;
	int ringqian, ring1, ring2, ring3, ring4, ring5;
	int ring6, ring7, ring8, ring9, ring10;
	int k5, k1, h5, h1, d5, d1; 
	int k5r, k1r, h5r, h1r, d5r, d1r; 
	
	printf("세 개의 물건값을 입력하세요 :");
	scanf("%d %d %d", &item1, &item2, &item3);
	sum = item1 + item2 + item3;
	ringqian = 10000-sum;
	printf("거스름돈은 %d원 입니다.\n", ringqian);


// 잔돈 계산 함수 
int ring(int a, int b)
{
    k5 = a/b;
    
    switch (b)	{
	case 5000:
		printf("오천원권 : %d장\n", k5);
		break; 
	case 1000:
		printf("천원권 : %d장\n", k5);
		break;
	case 500:
		printf("오백원짜리 동전 : %d개\n", k5);
		break;
	case 100:
		printf("백원짜리 동전 : %d개\n", k5);
		break;
	case 50:
		printf("오십원짜리 동전 : %d개\n", k5);
		break;
	case 10:
		printf("십원짜리 동전 : %d개\n", k5);
		break;
	}
	b = a%b;
    
	return b; 
}


	ring1 = ring(ringqian, 5000);
	ring2 = ring(ring1, 1000);
	ring3 = ring(ring2, 500);
	ring4 = ring(ring3, 100);
	ring5 = ring(ring4, 50);
	ring6 = ring(ring5, 10);
	
	return 0;	
}




