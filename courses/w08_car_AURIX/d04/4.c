/*****************************************************
 *
 * myproject.c
 *
 * Description : Hello World in C, ANSI-style
 *
 */

enum tag
{
	A = 123123,
	B
};

enum tag1
{
	C = 100,
	D
};



void func(int arg1, int * arg2)
{
	volatile char a = 10;

	arg1 = a + *arg2;
}


int main(void)
{
	volatile char A[10] = "string";
	volatile char *B = "string";

	A[1]= 'a';
	B[1]= 'a';

	*(A+1) = 'a';
	*(B+1) = 'a';
}
