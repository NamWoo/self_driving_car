//#include "../lib2450/Uart.h"

void Ex1()
{
    int num;
    int *ptr;

    ptr = &num;

    num = -1;
    printf("%#x \n", num);
    *(char *)ptr = 0x12345678;  // warning
    printf("%#x \n", num);

    num = -1;
    *(short *)ptr = 0x12345678; // warning
    printf("%#x \n", num);

    num = -1;
    *ptr = 0x12345678;
    printf("%#x \n", num);
}

void Ex2()
{
    unsigned int num = 0x80808080;
    unsigned short s;
    unsigned char c;

    s = *(unsigned short *)&num;
    printf("%#x \n", s);
    
    c = *(unsigned char *)&num;
    printf("%#x \n", c);
}


void main()
{
    printf("---------- Ex1 ---------- \n");
    Ex1();
	
	printf("\n\n---------- Ex2 ---------- \n");
	Ex2();
}
