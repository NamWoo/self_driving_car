#include<stdio.h>

char *my_token(char *ps);

void main(void)
{
//	char str[80];
	char str[80] = "music is my life";
	char *p = str;
	int i, cnt=0, result;
	
	printf("문장 입력 : ");
//	gets(str);
	printf("%s\n", str);
	my_token(str);
//	while ((p= my_token(str)) != NULL)
//	{
//		printf("%s\n", p);
//	}	
//	result = my_strcmp(a) > my_strcmp(b) ? 1 : 0;
//	if (result == 1)
//		printf("앞에꺼 더 커");
//	else
//		printf("뒤에꺼 더 커");
	return 0;
}

char *my_token(char *ps)
{
	int i, cnt;
	int comp;
	int *c; // 주소 
	char *g; // 주소
	
//	for(i=0; i<sizeof(ps); i++)
	for(i=0; i<strlen(ps); i++)
	{
		printf("!%c!\n", ps[i]);
//		comp = ps[i] == 0 ? 1 : 0;
		if (ps[i] == 32)
		{
			//comp =  *ps;
			printf(" %d\n",ps[i]);
			c = &(ps[i]);
			
			printf("%d\n", c);
//			printf("%c\n", g);	
//			comp++;
		}

		
	}
	
//		cnt += *ps++;
//	printf("%c\n",cnt);
	return &cnt;	
}
