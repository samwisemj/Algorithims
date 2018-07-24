#include <stdio.h>
#include <stdlib.h>
#define long_int_max 999999999
long int *parent;
long int find(long int v)
{
    while(parent[v])
        v=parent[v];
    return v;
}
long int uni(long int u,long int v)
{
    if(u!=v)
    {
        parent[v]=u;
        return 1;
    }
    return 0;
}

long int main()
{
    long int **ar,j,m,i=1,n,v,u,a,b,min=long_int_max,count=1,mincount=0;
    scanf("%d",&n);n++;scanf("%d",&m);
    parent=(long int *)calloc(n ,sizeof(long int));
    ar=(long int **)calloc(n,sizeof(long int *));
    //t=(long int*)calloc(n,sizeof(long int));
    for(j=0;j<n;j++)
    {
       ar[j]=(long int *)calloc(n,sizeof(long int));
    }
        for(j=0;j<m;j++)
        {
            scanf("%d",&u);
            scanf("%d",&v);
            scanf("%d",&i);
            ar[u][v]=ar[v][u]=i;
          if(ar[u][v]==0)
                ar[u][v]=long_int_max;
        }
    scanf("%d",&i);
    u=v=0;
    for(i=1;i<n;i++)
    {  // prlong intf("\n");
        for(j=1;j<n;j++)
               {   if(ar[i][j]<=0) ar[i][j]=long_int_max;}}
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
    a=u;    b=v;
    u=find(u); v=find(v);
    if(uni(u,v))
    {
       // prlong intf("\n%d. Edge(%d ,%d) = %d",count,a,b,min);
        mincount+=min;
        count++;
    }
    min=long_int_max;
    ar[a][b]=long_int_max;
    ar[b][a]=long_int_max;
    }
    printf("%d",mincount);
}

