#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

void main()

{
DIR *d;
struct dirent *di;
d=opendir(".");
while(di=readdir(d))
  {
     printf("%s \n",di->d_name);
 
  }




}


