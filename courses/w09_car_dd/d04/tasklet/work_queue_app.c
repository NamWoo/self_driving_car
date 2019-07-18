#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>



int main()
{
    int fd, i, retn;
    pid_t id;

    //char buf[100] = "write...\n;"
    char buf[100] = {0};
    (void)signal(SIGUSR1, usersignal);

    id = getpid();
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\n [APP] = %d \n",id);
    printf("\n\n\n\n\n\n\n\n\n\n");

    fd = open("/dev/",O_RDWR);
    printf("fd = %d\n",fd);

    
}