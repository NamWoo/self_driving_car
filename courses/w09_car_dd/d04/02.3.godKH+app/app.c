#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>

#define MAX_BUFFER 200

int main()
{
  int fd,i;
  char buffer[MAX_BUFFER];
	
  // system("mknod /dev/timer c 240 0");
  
  fd = open("/dev/timer",O_RDWR);
  printf("\n\n input STOP/START  : ");
  gets(buffer);
  write(fd,buffer,MAX_BUFFER);
  close(fd);
}