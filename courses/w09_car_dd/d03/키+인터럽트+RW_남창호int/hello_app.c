#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_BUFFER 50
char buf_in[MAX_BUFFER], buf_out[MAX_BUFFER];

int main()
{
	int fd,i;
	int mode = 9;

	fd = open("/dev/keyint",O_RDWR);
	
	while(mode != 0){
		printf("when you ready, (1 : go, 0 : stop) :");
		scanf("%d", &mode);
		if(mode == 1){
			read(fd,buf_in,MAX_BUFFER);
			printf("What app's heard from kernel : %s\n",buf_in);
		}
	}
	
	strcpy(buf_out, "I'm Application");
	write(fd,buf_out,MAX_BUFFER);

	close(fd);
	return (0);
}

