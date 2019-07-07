/*****************************************************
 *
 * myproject.c
 *
 * Description : Hello World in C, ANSI-style
 *
 */

typedef short * SSI;

typedef SSI (*AP)[3];

typedef AP (*FP)(void);

//short * (*(*var)(void))[3];
//
//
//
//SSI (*(*var)(void))[3]
//AP (*var)(void);
FP var;

struct va_tag
{
    char a;
    short b;
    int c;
    long d;

    float e;
    double f;
    int *p;
};

void func(int *arg)
{
    // a -> 'A'
    volatile char a = (*(struct va_tag *)arg).a;
    // b -> 10
    volatile short b = (*(struct va_tag *)arg).b;
    // c -> 500
    volatile int c = (*(struct va_tag *)arg).c;
    // d -> 1000
    volatile long d = (*(struct va_tag *)arg).d;
    // e -> 3.14
    volatile float e = (*(struct va_tag *)arg).e;
    // f -> 6.625
    volatile double f = (*(struct va_tag *)arg).f;
    // *P -> 123
    volatile int * p = (*(struct va_tag *)arg).p;
    volatile int tmp = *p;

    p = ((struct va_tag *)arg)->p;
















    a = *          ((char *)arg + 0);
    b = *(short *) ((char *)arg + 2);
    c = *(int *)   ((char *)arg + 4);
    d = *(long *)  ((char *)arg + 8);
    e = *(float *) ((char *)arg + 12);
    f = *(double *)((char *)arg + 16);
    p = *(int **)  ((char *)arg + 20);
    tmp = *p;
}



int main(void)
{
    int start = 123;

    struct va_tag var = {'A', 10, 500, 1000, 3.14f, 6.625, &start};

    func(&var);
}
