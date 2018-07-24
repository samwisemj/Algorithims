#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Int_max 999999
int *parent;
int find(int v);
int uni(int u,int v);
void main()
{
    int **ar,u,a,b,v,n,i,j,min=Int_max,count=1,mincount=0;
    printf("\nEnter the no vertex ");
    scanf("%d",&n);n++;
    ar=(int **)malloc(n*sizeof(int *));
    parent=(int *)calloc(n ,sizeof(int));
    printf("\nEnter the cost matrix\n");
    for(j=0;j<n;j++)
    {
       ar[j]=(int *)malloc(n*sizeof(int));
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
           {
            if(ar[i][j]==0)
                ar[i][j]=Int_max;
        }
    }
    while(count<n-1)
    {
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(ar[i][j]<min)
            {
                min=ar[i][j];
                u=i;v=j;
            }
        }
    }
    a=u;b=v;
    u=find(u); v=find(v);
    if(uni(u,v))
    {
        printf("\n%d. Edge(%d ,%d) = %d",count,a,b,min);
        mincount+=min;
        count++;
    }
    min=Int_max;
    ar[a][b]=Int_max;
    ar[b][a]=Int_max;
    }
    printf("\nThe cost of spaning tree is %d",mincount);
}
int find(int v)
{
    while(parent[v])
        v=parent[v];
    return v;
}
int uni(int u,int v)
{
    if(u!=v)
    {
        parent[v]=u;
        return 1;
    }
    return 0;
}


/*0 20 0 10 0
20 0 10 0 0
0 10 0 0 0
10 0 0 0 20
0 0 0 20 0
*/
