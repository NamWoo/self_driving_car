#include <stdio.h>
#include <string.h>

void main(void)
{
	char ch1[80], ch2[80];
	char *reap1, *reap2;
	
	printf("�� �ܾ� �Է� : ");
	scanf("%s%s", ch1, ch2);
	
//	printf("%s\n",ch1);
//	printf("%s\n",ch2);
	if (strlen(ch1) > strlen(ch2))
		reap1 = ch1;
	else if (strlen(ch2) > strlen(ch1))
		reap1 = ch2;
	
	if (strcmp(ch1, ch2) == -1)
		reap2 = ch1;
	else if (strcmp(ch1, ch2) == 1)
		reap2 = ch2;
	else if (strcmp(ch1, ch2) == 0){
	}
		
	printf("���̰� �� �ܾ� : %s\n",reap1);
	printf("������ ���� ������ �ܾ� : %s\n",reap2);
}
