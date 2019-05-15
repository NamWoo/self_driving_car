#include <stdio.h>

void rotate(int *ap, int *bp, int *cp);

int main(void)
{
	int a = 1, b = 2, c = 3;
	char ch;

	printf("%d:%d:%d", a, b, c);
	while(1)
	{
		scanf("%c", &ch);
		if (ch != '\n')
		{
			break;
		}
		rotate(&a, &b, &c);
		printf("%d:%d:%d", a, b, c);
	}

	return 0;
}

void rotate(int *ap, int *bp, int *cp)
{
	int temp;

	temp = *ap;
	*ap = *bp;
	*bp = *cp;
	*cp = temp;
}