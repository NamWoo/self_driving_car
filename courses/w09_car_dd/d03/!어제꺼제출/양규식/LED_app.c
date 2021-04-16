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
    /* write�������� "?��??? ��?��? */ 
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
     
    /* fd�Ƣ� �Ƣ�???��?? ��???���� buf���� ???? 10��???����?? ?��??? ??��? */ 
    retn = write(fd, buf, 10); 
     
    printf("\nSize of written data : %d\n", retn); 
 
    close(fd); 
     
    return 0; 
}

