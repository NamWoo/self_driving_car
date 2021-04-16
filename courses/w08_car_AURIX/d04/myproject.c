/*****************************************************
 *
 * myproject.c
 *
 * Description : Hello World in C, ANSI-style
 *
 */

void func(int *arg)		//구조체로 안받고 맴버참조를 할 수 없다. 구조체의 주소 넘겼으니까 다 읽어올 수 있다.
{
    // a -> 'A'
    volatile char a = (char)arg;
    // b -> 10
    volatile short b = (short)arg;
    // c -> 500
    volatile int c = (int)arg;
    // d -> 1000
    volatile long d = (long)arg;
    // e -> 3.14
//    volatile float e = (float)arg;
    // f -> 6.625
//    volatile double f = (double)arg;
    // *P -> 123
    volatile int * p = arg;
}

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

int main(void)
{
    int start = 123;

    struct va_tag var = {'A', 10, 500, 1000, 3.14f, 6.625, &start};

    func(&var);
}
