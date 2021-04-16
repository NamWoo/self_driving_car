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
    /* write에서 사용할 버퍼 */
    char buf[100];
int i;
    
    fd = open("/dev/SK", O_RDWR);
    printf("fd = %d\n", fd);
    
    if (fd<0) {
        perror("/dev/SK error");
        exit(-1);
    }
    else
        printf("SK has been detected...\n");
    
for(i=0; i<5; ++i)
{

    gets(buf);
    retn = write(fd, buf, 10);
}
    
    printf("\nSize of written data : %d\n", retn);

    close(fd);
    
    return 0;
}
