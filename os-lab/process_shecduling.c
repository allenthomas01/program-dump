/** COMMENT
  program to simulate FCFS,SJF,ROUND ROBIN,PRIORITY scheduling algorithms to find turnaround and waiting time
    COMMENT       **/ 

#include <stdio.h>
#include <unistd.h>


int n,i=0,j;
struct process{
   int no;
   int bt;
   int at;
   int ct;
   int tat;
   int wt;

   }p[10];



void sort(int n);
void ct(int n);
void tat(int n);
void wt(int n);

void main()
{

printf("enter number of processes :");
scanf("%d",&n);

for(i=0;i<n;i++)
{
scanf("%d %d",&p[i].bt,&p[i].at);
p[i].no =i+1;

}

sort(n);
ct(n);
tat(n);
wt(n);
printf(" Process|Burst time|Arrival time|Waiting time|Turnaround time");
for(i=0;i<n;i++)
{
printf("%d %d %d %d %d",p[i].no,p[i].bt,p[i].at,p[i].wt,p[i].tat);

}

}

//--------         fcfs scheduling    ----------


void sort(int n)
{
 struct process temp; for(i=0;i<n-1;i++)
  {
      for(j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
              {

                  temp=p[i];
                  p[j]=p[j+1];
                  p[j+1]=temp;

              }


        }


  }



}



void ct(int n)
{
p[0].ct=p[0].at+p[0].bt;
 for(i=1;i<n;i++)
   {
      if(p[i].at<p[i-1].ct)
         p[i].ct=p[i].at + p[i].bt;
      else
         p[i].ct=p[i-1].ct+p[i].bt;

   }

}



void tat(int n)
{
for(i=0;i<n;i++)
 p[i].tat=p[i].ct-p[i].at;

}


void wt(int n)
{
for(i=0;i<n;i++)
p[i].wt=p[i].tat-p[i].bt;

}

//----------     sjf  scheduling           --------------

void sortarrival(int n)
{
struct process temp;
int j;
for(i=0;i<n-1;i++)
{
 for(j=0;j<n-i-1;j++)
  {
    if(p[i].at>p[j+1].at)
      {
          temp=p[j];
          p[j]=p[j+1];
          p[j+1]=temp;

     }

  }

}


}












