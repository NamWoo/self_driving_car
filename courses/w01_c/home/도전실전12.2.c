#include <stdio.h>
#include <string.h>

void main(void)
{
	char ch[200];
	char ne[80];
	
	printf("�ܾ� �Է� : ");
	scanf("%s", ch);
	printf("��������� ���ڿ� : %s\n", ch);
	
	while(1){
		printf("�ܾ� �Է� : ");
		scanf("%s", ne);
		
		if (strcmp(ne,"end") == 0){
			break;
		} 
		
		strcat(ch, " ");
		strcat(ch, ne);		
		
		printf("��������� ���ڿ� : %s\n", ch);
	}
}
