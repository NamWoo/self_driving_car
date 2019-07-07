# include <stdio.h>

int main(int argc, char *argv[])
{
    volatile unsigned int i = 0;

    for(;;)
    {
        printf("heeello\n");
        i++;

        if( i > 10)
        {
            goto END;
        }
    }
END:;
}
