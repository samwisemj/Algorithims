#include<bits/stdc++.h>
using namespace std;
int V;
int findMinKey(int key[],int mst[])
{
    int min=INT_MAX,u;
        for(int i=0;i<V;i++)
            if(min>key[i]&&!mst[i])
                min=key[i],u=i;
    return u;
}
int main()
{
    int i,j,v,mstwt=0;
    cout<<"Enter the no vertices"<<endl;
    cin>>V;
    cout<<"enter the adjacency graph"<<endl;
    int ar[V][V];
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            cin>>ar[i][j];
    int key[V],mst[V],parent[V];
    for(i=0;i<V;i++)
       {key[i]=INT_MAX;mst[i]=0;parent[i]=i;}
    key[0]=0;
    for(i=0;i<V-1;i++)
    {
        int u=findMinKey(key,mst);
        mst[u]=1;
        for(v=0;v<V;v++)
            if(!mst[v]&&ar[u][v]!=0&&ar[u][v]<key[v])
                parent[v]=u,key[v]=ar[u][v];
    }
    cout<<"The MST is:-"<<endl;
    for(i=1;i<V;i++)
        cout<<i<<"--->"<<parent[i]<<" :: "<<ar[parent[i]][i]<<endl,mstwt+=ar[i][parent[i]];
    cout<<"Weight of the spaning tree is "<<mstwt;
}

/*0 20 0 10 0
20 0 10 0 0
0 10 0 0 0
10 0 0 0 20
0 0 0 20 0

1. Edge(1 ,4) = 10
2. Edge(2 ,3) = 10
3. Edge(1 ,2) = 20
4. Edge(4 ,5) = 20
The cost of spaning tree is 60*/
