#include<bits/stdc++.h>
using namespace std;
typedef struct edgearay
{
    int u,v,w;
}edge;
int main()
{
    cout<<"Enter no of vertices ";
    int n,src; cin>>n;
    cout<<"Enter no of edges ;";
    int e; cin>>e;
    edge *ar;
    ar=(edge *)malloc(e*sizeof(edge));
    int *dist;
    dist=(int *)calloc(n,sizeof(int));
    int i;
    cout<<"\nEnter u v w for edges\n";
    for(i=0;i<e;i++)
    {
        cin>>ar[i].u>>ar[i].v>>ar[i].w;
    }
     for(i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    cout<<"\nEnter source:";
    cin>>src;
    dist[src]=0;
    int count=0;
    for(count=0;count<n-1;count++)
    {
        for(i=0;i<e;i++)
         if(dist[ar[i].u]!=INT_MAX&&dist[ar[i].u]+ar[i].w<dist[ar[i].v])
            dist[ar[i].v]=dist[ar[i].u]+ar[i].w;
    }
    for(i=0;i<n;i++)
         if(dist[ar[i].u]!=INT_MAX&&dist[ar[i].u]+ar[i].w<dist[ar[i].v])
            cout<<"\nGraph has negative edge cycles::--";
    cout<<"\nShortest distances from source\n";
    for(i=0;i<n;i++)
        cout<<"\nSource "<<src<<" to "<<i<<"----> "<<dist[i];
    return 0;
}
/*
5
8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0
*/
