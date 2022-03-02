#include<stdio.h>
#include<conio.h>

struct proc
{
    struct msg
    {
        int timestamp;
        int pid;
    }m[20];
    int num_reply;
};

void main()
{
  int num,num_critical,i,j,k,tempid,temptstamp;
  int a,b;
  struct proc p[50];
  printf("IMPLEMENTING LAMPORT ALGORITHM\n");
  printf("Enter number of processes: ");
  scanf("%d",&num);
  printf("\n");
  printf("Enter the number of processes competing to enter critical section: ");
  scanf("%d",&num_critical);
  printf("\n");
  j=0;
  for(i=0;i<num_critical;i++)
  {
    printf("Enter the process id (must be lesser than %d): ",num);
    scanf("%d",&tempid);
    printf("\n");
    printf("Enter the timestamp of the process: ");
    scanf("%d",&temptstamp);
    printf("\n");
    for(k=0;k<num;k++)
    {
      p[k].m[j].pid=tempid;
      p[k].m[j].timestamp=temptstamp;
      p[k].num_reply=num;
    }
    j++;
  }
  for(k=0;k<num;k++)
  {
      for(i=0;i<num_critical-1;i++)
      {
        for(j=i+1;j<num_critical;j++)
        {
          if(p[k].m[i].timestamp>p[k].m[j].timestamp)
          {
            tempid=p[k].m[i].pid;
            temptstamp=p[k].m[i].timestamp;
            p[k].m[i].pid=p[k].m[j].pid;
            p[k].m[i].timestamp=p[k].m[j].timestamp;
            p[k].m[j].pid=tempid;
            p[k].m[j].timestamp=temptstamp;
          }
        }
      }
  }
  for(i=0;i<num;i++)
  {
    printf("Process %d with %d REPLY message: ",i,p[i].num_reply);
    for(j=0;j<num_critical;j++)
    {
      printf("(%d,%d)<--",p[i].m[j].pid,p[i].m[j].timestamp);
    }
    printf("\n");
  }
  while(num_critical>0)
  {
      for(i=0;i<num;i++)
      {
        if(p[i].m[0].pid==i)
        {
          printf("Since process %d is at the top of the request queue ,it enters the critical section\n",i);
          printf("\nOn exiting the critical section: ");
          printf("Process %d sends a RELEASE message to all the other processes\n",i);
          for(a=0;a<num;a++)
          {
              for(j=0;j<num_critical-1;j++)
              {
                p[a].m[j].pid=p[a].m[j+1].pid;
                p[a].m[j].timestamp=p[a].m[j+1].timestamp;

              }
          }
          num_critical--;
          if(num_critical>0)
          {
            printf("Now the request queue status in each process is\n");
            for(a=0;a<num;a++)
            {
                printf("Process %d with %d REPLY messages: ",a,p[a].num_reply);
                for(b=0;b<num_critical;b++)
                {
                    printf("(%d,%d)<--",p[a].m[b].pid,p[a].m[b].timestamp);
                }
                printf("\n");
            }
          }
          else
           printf("Request queue is empty\n");
        }
      }
  }
  getch();
}
