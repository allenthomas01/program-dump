#include <stdio.h>
#include <unistd.h>

void main()
{
int pid;
printf("hello world \n");
fork();
printf("beginning of fork \n");
printf("process id is %d \n",getpid());

}


