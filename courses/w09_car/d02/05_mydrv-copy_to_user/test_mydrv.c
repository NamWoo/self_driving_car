/* test_mydrv.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_BUFFER 26
char buf_in[MAX_BUFFER], buf_out[MAX_BUFFER];

int main()
{
  int fd,i;
  
  fd = open("/dev/mydrv",O_RDWR);
  read(fd,buf_in,MAX_BUFFER);
  printf("buf_in = %s\n",buf_in);
  
  for(i = 0;i < MAX_BUFFER;i++)
     buf_out[i] = 'a' + i;
  write(fd,buf_out,MAX_BUFFER);
  close(fd);
  return (0);
}
