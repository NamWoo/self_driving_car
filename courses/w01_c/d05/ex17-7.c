#include <stdio.h> 

struct score
{
	int kor;
	int eng;
	int mat;	
};

int main(void)
{
	struct score yuni = {90,80,70};
	struct score *ps = &yuni;
	
//	yuni.kor = ;

	printf("���� : %d\n", (*ps).kor);
	printf("���� : %d\n", (*ps).eng);
	printf("���� : %d\n", (*ps).mat);
	

	
	
	
}

