#include <stdio.h>

int main(void)
{
	int ch;

	while((ch = getchar()) != '\n')
	{
		if((ch >= 'A') && (ch <= 'Z')) ch += ('a' - 'A');
		else if((ch >= 'a') && (ch <= 'z')) ch -= ('a' - 'A');
		putchar(ch);
	}

	return 0;
}