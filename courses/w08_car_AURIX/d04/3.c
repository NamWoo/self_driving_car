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
	volatile char A = 0xFF;
	volatile int B;

	B = A;
}
