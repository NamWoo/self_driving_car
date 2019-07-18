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
	volatile signed int B = 1;
	volatile int tmp = 0;

	if(B > 0x1U)
	{
		tmp = 1;
	}
	else
	{
		tmp = 2;
	}
}
