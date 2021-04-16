#include <stdio.h>


int main(void)
{
	printf("%d",~0);
	
	char *strings[2]={"apple","banana"}; //100 //200
	char *ptr = strings[0]; //ptr 100
	
	printf("%c",*++ptr);  //*(prt+sizeof(char))
	
	return 0;
}


