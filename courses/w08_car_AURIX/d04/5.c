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
	volatile float f = 3.14;
	volatile double d = 3.14;
	volatile int tmp = 0;

	volatile enum tag AAA;
	volatile enum tag1 BBB;

	func(tmp, &tmp);

	tmp = sizeof(AAA);

	tmp = sizeof(BBB);

	if(f==d)
	{
		tmp = 1;
	}
	else
	{
		tmp = 2;
	}
}
