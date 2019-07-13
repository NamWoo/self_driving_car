
#include <stdio.h>


int main(void)
{
    int retn;
    int fd;
    /* write에서 사용할 버퍼 */
    char buf[100] = "write...\n";


    printf("first size : %d\n",sizeof(buf));    //100
    printf("second size : %d\n",sizeof(buf));


    // fd = open("/dev/SK", O_RDWR);
    // printf("fd = %d\n", fd);
    
    // if (fd<0) {
    //     perror("/dev/SK error");
    //     exit(-1);
    // }
    // else
    //     printf("SK has been detected...\n");
    
    // /* fd가 가르키는 파일에 buf에 있는 10바이트를 쓰라는 의미 */
    // retn = write(fd, buf, 10);
    
    // printf("\nSize of written data : %d\n", retn);

    // close(fd);
    
    return 0;
}
