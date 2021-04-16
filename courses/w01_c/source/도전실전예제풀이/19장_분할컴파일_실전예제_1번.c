#include <stdio.h>
#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) - (y))
#define MUL(x, y) ((x) * (y))
#define DIV(x, y) ((x) / (y))
#define input_expression(x, op, y) scanf("%d %c %d", &x, &op, &y)

int main(void)
{
	int a, b, res;
	char op;

	while(1)
	{
		printf("> 수식 입력(종료 Ctrl + Z) : ");
		if(input_expression(a, op, b) < 0) break;
		switch(op)
		{
		case '+': res = ADD(a, b); break;
		case '-': res = SUB(a, b); break;
		case '*': res = MUL(a, b); break;
		case '/': res = DIV(a, b); break;
		}
		printf("@ %d %c %d = %d\n", a, op, b, res);
	}

	return 0;
}
