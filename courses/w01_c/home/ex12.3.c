#include <stdio.h>

void main(void)
{
	char str[80];
	
	printf("���ڿ� �Է� : ");
//	scanf("%s", str);
//	printf("%d",sizeof(str));
	fgets(str,sizeof(str),stdin);
	printf("ù��°�ܾ�%s",str);
//	scanf("%s", str);
//	printf("ù��°�ܾ�%s\n",str);
}

