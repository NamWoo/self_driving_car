#include <stdio.h>
#include <string.h>

void main(void)
{
	char ch1[80];
	char *temp;
	int i,k;
	
	printf("�ܾ� �Է� : ");
	scanf("%s", ch1);	
	printf("�Է��� �ܾ� : %s, ������ �ܾ� : ", ch1);
	
	if ((k = strlen(ch1)) >= 6){	
		for (i=0; i< 5; i++){
			printf("%c", ch1[i]);
		}		
		for (i=0; i< k-5; i++){
			printf("*");
		}		
	}
}

