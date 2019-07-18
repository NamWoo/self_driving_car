#include <stdio.h>
 
int main(void)
{
	int item1, item2, item3, b, i, c;	
	int ringring[6] = {5000, 1000, 500, 100, 50, 10};
//	char ringname[] = {'오천원', '천원', '오백원', '백원', '오십원', '십원', '\0'};
	
	printf("세 개의 물건값을 입력하세요 :");
	scanf("%d %d %d", &item1, &item2, &item3);
	b = 10000-(item1 + item2 + item3);
	printf("거스름돈은 %d원 입니다.\n", b);

	for (i=0 ; i<6 ; i++)
	{
		c = ringring[i]; 
		printf("%d원짜리 %d개\n",c, b/c);			
		b = b%c;
	}

	return 0;	
}




