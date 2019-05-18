#include <stdio.h>

void my_gets(char *str,int size);

void main(void)
{
	char str[7];
	my_gets(str, sizeof(str));
	printf("ют╥б %s\n", str);
}

void my_gets(char *str,int size)
{	
	char ch;
	int i=0;
	
	ch = getchar();
//	printf("%c\n",ch);
	
	while ((ch!='\n')&&(i<size-1))
	{
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i]='\0';
	
	
}
