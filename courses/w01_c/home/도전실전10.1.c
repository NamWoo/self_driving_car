#include <stdio.h>

int score[5] = {72,88,95,64,100};
void print_graph(int *ps, int size);

void main(void)
{
	int score[5] = {72,88,95,64,100};
	int size;
	
	size = sizeof(score)/ sizeof(int);	
	print_graph(score, size);
	
}


void print_graph(int *ps, int size)
{
	int i, j;
	int m = 5;
	for(i=0; i<size; i++)
	{
		printf("(%3d) ", ps[i]);		
		for(j=0; j<ps[i]/m; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
}


