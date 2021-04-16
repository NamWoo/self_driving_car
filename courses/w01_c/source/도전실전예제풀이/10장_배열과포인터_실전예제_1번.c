#include <stdio.h>

void print_graph(int *sp, int size);

int main(void)
{
	int score[5] = {72, 88, 95, 64, 100};
	
	print_graph(score, 5);

	return 0;
}

void print_graph(int *sp, int size)
{
	int i, j;
	int star_cnt;

	for(i = 0; i < size; i++)
	{
		star_cnt = sp[i] / 5;
		printf("(%3d) ", sp[i]);
		for(j = 0; j < star_cnt; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
