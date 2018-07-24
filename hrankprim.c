/*0 6 0 0 5 1
6 0 3 0 0 5
0 3 0 6 0 6
0 0 6 0 2 4
5 0 0 2 0 5
1 5 6 4 5 0*/

#include <stdio.h>
#include <stdlib.h>
#define Int_max 2147483647
int *parent;
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

int main()
{
    int **ar,j,m,i=1,n,v,u,a,b,min=Int_max,count=1,mincount=0;
    scanf("%d",&n);n++;scanf("%d",&m);
    parent=(int *)calloc(n ,sizeof(int));
    ar=(int **)calloc(n,sizeof(int *));
    //t=(int*)calloc(n,sizeof(int));
    for(j=0;j<n;j++)
    {
       ar[j]=(int *)calloc(n,sizeof(int));
    }
        for(j=0;j<m;j++)
        {
            scanf("%d",&u);
            scanf("%d",&v);
            scanf("%d",&i);
            ar[u][v]=ar[v][u]=i;
          if(ar[u][v]==0)
                ar[u][v]=Int_max;
        }
    scanf("%d",&i);
    u=v=0;
    for(i=1;i<n;i++)
    {  // printf("\n");
        for(j=1;j<n;j++)
               {   if(ar[i][j]==0) ar[i][j]=Int_max;}}
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
       // printf("\n%d. Edge(%d ,%d) = %d",count,a,b,min);
        mincount+=min;
        count++;
    }
    min=Int_max;
    ar[a][b]=Int_max;
    ar[b][a]=Int_max;
    }
    printf("%d",mincount);
}
