#include<stdio.h>

struct Person
{
    double a;
    short b;
    double c;
    short d;
};
//not 8+2+8+2. 20. 
//4 4 2 4 4 2. 24.


struct Person1
{
    char name[10];
    int day;
    short month;
    int year;
    double height;
};
//4 4 2 4 2 4 4 4 32.
//ppt에 36? ??? 이건 뭐지?

struct Person2
{
    char name[10];
    short month;
    int day;    
    int year;
    double height;
};
//4 4 2 4 4 4 4. 32



int main(void)
{
    int nLength = sizeof(struct Person2);
    printf("%d",nLength);   
    return 0;
}

