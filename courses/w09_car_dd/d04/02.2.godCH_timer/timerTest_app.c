/***************************************
 * Filename: sk_app.c
 * Title: Skeleton Device Application
 * Desc: Implementation of system call
 ***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>


int main(void)
{
	int fd;
    int mod = 1;

	fd = open("/dev/timerTest",O_RDWR);
	while(mod != 0){
        printf("press 0 to stop :");
        scanf("%d", &mod);
    }
	close(fd);
	return (0);
}