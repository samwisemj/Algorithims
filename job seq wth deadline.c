//Job sequencing with deadline
//Author Subhamoy Sarkar
#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int job,deadline,profit;
}node;
int min(int a, int b){if(a>b)return b;return a;}
void main()
{
    int n,i,j,k,dmax,*slot,c=1,profitcount=0;
    node *ar,temp;
    printf("Enter the no of jobs\n");
    scanf("%d",&n);
    ar=(node *)malloc(n*sizeof(node));
    printf("Enter the deadline and profit for jobs:-\n");
    for(i=0;i<n;i++)
    {
        printf("Job %d: ",i+1);
        scanf("%d",&ar[i].deadline);
        scanf("%d",&ar[i].profit);
        ar[i].job=i+1;
    }
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
        {
                if(ar[j].profit<ar[j+1].profit)
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
            else if(ar[j].profit==ar[j+1].profit)
            {
                if(ar[j].job>ar[j+1].job)
                {
                    temp=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                }
            }
        }
    dmax=ar[0].deadline;
    for(i=1;i<n;i++)
        if(dmax<ar[i].deadline)
            dmax=ar[i].deadline;
    slot=(int *)calloc((dmax+1),sizeof(int));
    i=0;
    while(c<=dmax)
    {
        k=min(ar[i].deadline,dmax);
       while(k>=1)
       {
               if(slot[k]==0)
               {
                    slot[k]=ar[i].job;
                    profitcount+=ar[i].profit;
                    c++;
                    k=0;
               }
               k--;
       }
       i++;
    }
    printf("The Jobs Sequences are:-\n ");
    for(i=1;i<=dmax;i++)
        printf("\n%d. Job %d ",i,slot[i]);
    printf ("\n The profit is %d",profitcount);
}
