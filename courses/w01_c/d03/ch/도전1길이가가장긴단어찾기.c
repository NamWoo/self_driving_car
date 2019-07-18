#include <stdio.h>

void print_graph(int *ps, int size);

int main(void)
{
	int score[5] = {72,88,95,64,100};
	int *ps = score;
	int i;
		
	for(i=0; i<3; i++){
		printf("(%3d) \n", *ps++); //*(ps++), ps[i] ´Ù °°´Ù. 
	}
		
	
//	word = getchar();
//	printf("%c",word);
	
	return 0;
}
