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
    /* write０╳走〝 "?０??? 易?芋? */ 
    int buf[100] = "write...\n"; 
 
    kva = ioremap(0x56000060, 28); 
     
    fd = open("/dev/SK", O_RDWR); 
    printf("fd = %d\n", fd); 
     
    if (fd<0) { 
        perror("/dev/SK error"); 
        exit(-1); 
    } 
    else 
        printf("LED Test start\n"); 
     
    /* fd﹉╳ ﹉╳???﹉?? 芋???０╳ buf０╳ ???? 10易???芋Ｙ?? ?昌??? ??易? */ 
    retn = write(fd, buf, 10); 
     
    printf("\nSize of written data : %d\n", retn); 
 
    close(fd); 
     
    return 0; 
}

