#include <stdio.h>

//int *array[3]
//int array[2][3]
//int array[][3]
//int (*array)[3]

void MyPrint1(int *array[3])
{
	printf("int *array[3] %d %d %d\n",array, *array, &array);
}
void MyPrint2(int array[2][3])
{
	printf("int array[2][3] %d %d %d\n",array, *array, &array);
}
void MyPrint3(int array[][3])
{
	printf("int array[][3] %d %d %d\n",array, *array, &array);
}
void MyPrint4(int (*array)[3])
{
	printf("int (*array)[3] %d %d %d\n",array, *array, &array);
}

void main(void)
{
	int *array1[3] = {{1,2,3},{4,5,6}};
	int array2[2][3] = {{1,2,3},{4,5,6}};
	int array3[][3] = {{1,2,3},{4,5,6}};
	int (*array4)[3] = {{1,2,3},{4,5,6}};


	
	
	MyPrint1(array1);
	MyPrint2(array2);
	MyPrint3(array3);
	MyPrint4(array4);
	
	
	
}
