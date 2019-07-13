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
    char buf[100] = "write...\n";
    
    fd = open("/dev/SK", O_RDWR);
    printf("fd = %d\n", fd);
    
    if (fd<0) {
        perror("/dev/SK error");
        exit(-1);
    }
    else
        printf("SK has been detected...\n");
    
    /* fd가 가르키는 파일에 buf에 있는 10바이트를 쓰라는 의미 */
    retn = write(fd, buf, sizeof(buf));
    
    printf("\nSize of written data : %d\n", retn);

    close(fd);
    
    return 0;
}
