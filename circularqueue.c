#include <stdio.h>
int q[25],size,item,front=-1,next,rear=-1,choice;

void insert()
{
    printf("enter element to insert\n");
    scanf("%d",&item);
    if(front==-1)
    {
        front=0;
        rear=0;
        q[rear]=item;
    }
    else
    {
        next=(rear+1)%size;
        if(next!=front && next!=size)
        {
            rear=next;
            q[rear]=item;
        }
        else
        {
          printf("queue full\n");
        }
    }
}

void delete()
{
    if(front==-1)
    {
        printf("queue empty\n");
    }
    else
    {
    item=q[front];
     if(front==rear)
     {
         front=-1;
         rear=-1;
     }
     else
     {
      front=(front+1)%size;
     }
    }
}

void displayqueue()
{
    if(front==-1)
    {
        printf("queue empty\n");
    }
    else
    {
        printf("front %d\n",front);
        printf("rear %d\n",rear);
        printf("elements are\n");
        for(int i=front;i!=rear;i=(i+1)%size)
        {
            printf("%d\t",q[i]);
        }
        printf("%d\n",q[rear]);
    }
}


void main()
{
printf("enter size of queue\n");
scanf("%d",&size);


do
{
    printf("select one of the option below\n");
    printf("1:add queue 2:dequeue 3:display queue 4:exit \n");
    scanf("%d",&choice);
switch(choice)
{
     case 1:insert();
              break;
      case 2:delete();
               break;
      case 3:displayqueue();
             break;
      case 4:break;
}
}while(choice!=4);

}