#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int **ar,n,current=0,next,count=1,i,j,temp;
    printf("Enter the no of activites");
    scanf("%d",&n);
    ar=(int **)malloc(n*sizeof(int *));
    for(i=0;i<3;i++)
        ar[i]=(int *)malloc(n*sizeof(int));
    printf("Enter the start and finsh time for each job\n");
    for(i=0;i<n;i++)
    {
        printf("Job %d : ",i+1);
        scanf("%d",&ar[1][i]);
        scanf("%d",&ar[2][i]);
        ar[0][i]=i+1;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ar[2][j]>ar[2][j+1]) //sort activity as ascending order of their next finishing time
            {
                temp=ar[2][j];  ar[2][j]=ar[2][j+1];    ar[2][j+1] = temp;
                temp=ar[1][j];  ar[1][j]=ar[1][j+1];    ar[1][j+1] = temp;
                temp=ar[0][j];  ar[0][j]=ar[0][j+1];    ar[0][j+1] = temp;
            }
        }
    }
    printf("The jobs that can be selected are:-\n");
    printf("\n%d. Job %d : Start Time : %d End Time : %d",count++,ar[0][current],ar[1][current],ar[2][current]);
    for(current=0,next=1;;)
    {
        if((ar[1][next]>=ar[2][current])&&next<n)//starting time of next job greater than finishing time of current
        {
            current=next;
            next++;
            printf("\n%d. Job %d : Start Time : %d End Time : %d",count++,ar[0][current],ar[1][current],ar[2][current]);
        }
        else
            next++;
        if(next>n)
                break;
    }
}
