#include<stdio.h>
 
void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    
 
       printf("+-----+--------------+------------+--------------+\n");
    printf("| PID | Burst Time | Waiting Time | Turnaround Time|\n");
     printf("+-----+--------------+------------+--------------+\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("|  %d  |     %d      |      %d      |       %d       |\n",p[i],bt[i],wt[i],tat[i]);
         printf("+-----+--------------+------------+--------------+\n");

    }
 
 
}


