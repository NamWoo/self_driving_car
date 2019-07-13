/***************************************
 * Filename: sk_app.c
 * Title: Skeleton Device Application
 * Desc: Implementation of system call
 ***************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <malloc.h>

typedef struct
{
   int age;  
   char name[30];
   char address[20]; 
   int  phone_number; 
   char depart[20]; 
} __attribute__ ((packed)) mydrv_data;

int main(void)
{
    int retn;
    int fd;
	char buf[20] = {0};
   
    fd = open("/dev/SK", O_RDWR);
    printf("fd = %d\n", fd);


    if (fd<0) {
        perror("/dev/SK error");
        exit(-1);
    }
    else
        printf("SK has been detected...\n");
    
    retn = write(fd, &buf, 20);
    	
    close(fd);
    
    return 0;
}
