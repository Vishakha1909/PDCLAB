#include<stdio.h>
#include<conio.h>

struct proc
{
  int timestamp;
  int pid;
  int num_reply;
};

void main()
{
  int i,j,num_critical,num,tempid,temptstamp,k;
  int count=0;
  struct proc p[50];
  printf("IMPLEMENTING RICART-AGRAWALA ALGORITHM\n");
  printf("Enter number of processes: ");
  scanf("%d",&num);
  printf("\n");
  for(i=0;i<num;i++)
  {
    p[i].timestamp=0;
    p[i].num_reply=0;
  }
  printf("Enter the number of processes competing to enter the critical section: ");
  scanf("%d",&num_critical);
  for(i=0;i<num_critical;i++)
  {
    printf("Enter the process id (must be less than %d): ",num);
    scanf("%d",&tempid);
    printf("Enter the timestamp of that process: ");
    scanf("%d",&temptstamp);
    printf("\n");
    p[tempid].pid=tempid;
    p[tempid].timestamp=temptstamp;
  }
  for(i=0;i<num;i++)
  {
      if(p[i].timestamp!=0)
      {
        printf("Process %d  ",i);
        printf("(%d,%d,%d)",p[i].pid,p[i].timestamp,p[i].num_reply);
      }
      printf("\n");
  }
  for(i=0;i<num;i++)
  {
      if(p[i].timestamp==0)
      {
        printf("Process %d does not compete for the CS and so sends a reply message to all\n",i);
        for(j=0;j<num;j++)
        {
          if(p[j].timestamp!=0)
            p[j].num_reply++;
        }
      }
      else
      {
         for(j=0;j<num;j++)
         {
           if((p[j].timestamp!=0)&&(p[i].timestamp>p[j].timestamp))
           {
             printf("Process %d sends a REPLY message to process %d\n",i,j);
             p[j].num_reply++;
            }
          }
      }
    }
  printf("\n");
  for(i=0;i<num;i++)
  {
      if(p[i].timestamp!=0)
      {
        printf("Process %d  ",i);
        printf("(%d,%d,%d)",p[i].pid,p[i].timestamp,p[i].num_reply);
      }
      printf("\n");
  }
  do
  {
  for(i=0;i<num;i++)
  {
    if(p[i].num_reply==num-1)
    {
      printf("Process %d enters the critical section\n",i);
      printf("On exiting the CS process %d sends a REPLY message to others\n\n",i);
      p[i].timestamp=0;
      p[i].num_reply=0;
      count++;
      for(k=0;k<num;k++)
      {
        if(p[k].timestamp!=0)
          p[k].num_reply++;
       }
      for(i=0;i<num;i++)
      {
        if(p[i].timestamp!=0)
        {
          printf("Process %d is   ",i);
          printf("(%d,%d,%d)",p[i].pid,p[i].timestamp,p[i].num_reply);
        }
        printf("\n");
      }
     }
   }
   }while(count<num_critical);
  printf("The ")
  getch();
}
