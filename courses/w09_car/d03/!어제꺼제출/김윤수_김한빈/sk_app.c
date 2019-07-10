/***************************************

 * Filename: sk_app.c

 * Title: Skeleton Device Application

 * Desc: Implementation of system call

 ***************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{	
    int retn;
    int fd;
    char buf[100] = "write...\n";
    
    fd = open("/dev/SK", O_RDWR);
    printf("fd = %d\n", fd);
    
    if (fd<0) {
        perror("/dev/SK error");
        exit(-1);
    }
    
    else
        printf("SK has been detected...\n");

    retn = write(fd, buf, 10);
    
    close(fd);
    return 0;
}