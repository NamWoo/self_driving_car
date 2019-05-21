#include <stdio.h>

int main(void)
{
	int arr[5] = {1,3,5,7,9};
	int *pArr = arr - 1;
	
	
	printf("%x\n", arr - 1);
	printf("%x\n", arr);
	printf("%x\n", arr + 1);
	
	printf("%d", *(++pArr));
	printf("%d", *(++pArr));
	printf("%d", *(pArr+1));
	printf("%d", *(pArr+2));
	
	return 0;
}
