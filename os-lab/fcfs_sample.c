/** COMMENT
  program to simulate FCFS 
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
printf("Enter burst time and arrival time\n");
scanf("%d %d",&p[i].bt,&p[i].at);
p[i].no =i+1;

}

sort(n);
ct(n);
tat(n);
wt(n);
printf("Process  | Burst time |  Arrival time |  Waiting time | Turnaround time\n");
for(i=0;i<n;i++)
{
printf("%d \t\t %d \t \t %d \t\t %d \t\t %d\n",p[i].no,p[i].bt,p[i].at,p[i].wt,p[i].tat);

}
}

//--------         fcfs scheduling    ----------


void sort(int n)
{
 struct process temp; 
  for(i=0;i<n-1;i++)
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

