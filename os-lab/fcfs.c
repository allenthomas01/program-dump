#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int completion_time;
    int turnaround_time;
}Process;

void print_table(Process p[],int n);
float sum_waiting_time,sum_turnaround_time;

int main()
{
    Process p[MAX];
    int i,j,n;
    printf("Enter total number of processes:");
    scanf("%d",&n);
    printf("Enter the arrival time for each processes:\n");
    for(i=0;i<n;i++)
    {
        p[i].pid=i;
        printf("p[%d]:",i);
        scanf("%d",&p[i].arrival_time);
        p[i].waiting_time=p[i].turnaround_time=0;
    }
    printf("Enter the burst time for each processes:\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]:",i);
        scanf("%d",&p[i].burst_time);
    }
    p[0].turnaround_time=p[0].completion_time=p[0].burst_time;
    for(i=1;i<n;i++)
    {
        int ct=0;
        for(int j=i;j>=0;j--)
        {
            ct=ct+p[j].burst_time;
        }
        p[i].completion_time=ct;
        p[i].waiting_time=p[i-1].completion_time-p[i].arrival_time;
        p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
    }

    //print table

    printf("\n");
    print_table(p,n);
    printf("\n");

     return 0;
}

void print_table(Process p[],int n)
{
    int i;
    printf("+-----+--------------+------------+--------------+----------------+\n");
    printf("| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time|\n");
    printf("+-----+--------------+------------+--------------+----------------+\n");
    for(i=0;i<n;i++){
      printf("|  %d  |       %d      |     %d      |      %d      |       %d       |\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
      printf("+-----+--------------+------------+--------------+----------------+\n");

    }

}

