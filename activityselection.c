#include<stdio.h>
void main()
{
    int n,start[100],finish[100],task[100],i,j,time=0,temp;
    printf("Enter number of jobs:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter start and finish time for job %d:",i+1);
        scanf("%d %d",&start[i],&finish[i]);
        task[i]=i+1;
    }
     for (i = 0; i < n - 1; i++) 
    for (j = 0; j < n - i - 1; j++) 
      if (start[j] > start[j + 1])   
        {
        temp = start[j];  
        start[j] = start[j + 1];  
        start[j + 1] = temp; 
        temp = task[j];  
        task[j] = task[j + 1];  
        task[j + 1] = temp;
        temp = finish[j];  
        finish[j] = finish[j + 1];  
        finish[j + 1] = temp;
        }
        printf("task %d completed\n",task[0]);
        time=finish[0];
        for(i=1;i<n;i++)
        {
            if(time<=start[i])
            {
                 printf("task %d completed\n",task[i]);
                 time=finish[i];
            }
        }
        printf("task scheduling completed");
    
}
