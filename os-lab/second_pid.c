#include <stdio.h>
#include <unistd.h>

void main()
{
int pid;
printf("hello world \n");
printf("i am parent proces %d\n",getpid());
printf("this is before forking\n");
pid=fork();
printf("beginning of fork \n");
 if(pid==0)
  {
   printf("i am child process %d \n",getpid());

  }
 else
  printf("i am parent process %d\n",getpid());
}






