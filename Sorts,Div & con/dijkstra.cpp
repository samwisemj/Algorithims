#include<bits/stdc++.h>>
#define infinity 9999999
#define V 9
using namespace std;

int mindist(int dist[V],int vis[V])
{
    int i,ind,mind=infinity;
    for(i=0;i<V;i++)
    {
        if(mind>=dist[i] && !vis[i])
          {

           mind=dist[i];
            ind=i;}
    }
    return ind;
}
int main()
{
    int v=V,i,j,u;
    int ar[v][v]=       {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    int src=0;
    int dist[v];
    int visited[v]={0,0,0,0,0,0,0,0,0};
    int path[v]={0,infinity,infinity,infinity,infinity,infinity,infinity,infinity,infinity};
    for(i=0;i<v;i++)
        dist[i]=infinity;
    dist[src]=0;
    for(i=0;i<v-1;i++)
    {
        u=mindist(dist,visited);
        visited[u]=1;
        for(j=0;j<v;j++)
        {
            if(!visited[j] && ar[u][j]!=0 && dist[j]>ar[u][j]+dist[u] && dist[u]!=infinity)
            {
                dist[j]=ar[u][j]+dist[u];
                path[u]=j;
            }
        }
    }
    for(j=0;j<v;j++)
        {
            cout<<dist[j]<<",";
        }
    cout<<endl;
    while(src!=8)
    {
        cout<<path[src]<<"-->";
        src=path[src];
    }//

}
