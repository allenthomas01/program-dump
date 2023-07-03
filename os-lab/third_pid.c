#include <stdio.h>
#include <unistd.h>

void main()
{
int a;
printf("before forking \n");
fork();
printf("after first forking\n");
fork();
printf("after second forking \n");
printf("hello world from process %d \n",getpid());
}



