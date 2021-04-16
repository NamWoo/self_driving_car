#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void mySigHdlr(int signo)
{
  if (signo == SIGINT) {
    printf("received SIGINT\n");
  }
}

int main(void)
{
  if (signal(SIGINT, mySigHdlr) == SIG_ERR) {
    printf("\ncan't catch SIGINT\n");
  }
  while(1) {
    sleep(1);
  }
  return 0;
}
