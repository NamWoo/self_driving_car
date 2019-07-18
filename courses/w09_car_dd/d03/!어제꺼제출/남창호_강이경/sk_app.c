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

    // char buf[100] = "write...\n";
    char buf[100] = {0};
    
    fd = open("/dev/SK", O_RDWR);
    printf("fd = %d\n", fd);
    
    if (fd<0) {
        perror("/dev/SK error");
        exit(-1);
    }
    else
        printf("SK has been detected...\n");
    
    retn = write(fd, buf, 10);
    
    //retn = read(fd, buf, 20); // fd가 가르키는 파일에 buf에서 20byte 읽음
    //printf("\ndata : %s\n", buf);

    close(fd);
    
    return 0;
}
