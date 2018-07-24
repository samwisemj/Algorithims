#include<bits/stdc++.h>
using namespace std;
typedef struct stuc{
 int u,v,w;
 bool operator <(stuc &m)
    {
    return w<m.w;
    }
}edge;
 int *parent;
 int uni(int u,int v)
 {
     if(u!=v)
     {
         parent[u]=v;
        return 1;
     }
     return 0;
 }
 int find(int v)
 {
     while(parent[v])
        v=parent[v];
     return v;
 }
 int main()
 {
     int n,e,i,j,c=0,mst=0;
     cout<<"\nEnter the no of vertices ";
     cin>>n;
     cout<<"\nEnter the no of edges ";
     cin>>e;
     edge *ar=(edge *)malloc(e*sizeof(edge));
     parent=(int *)calloc(n,sizeof(int));
     cout<<"\nEnter u v w for edges\n";
     for(i=0;i<e;i++)
         cin>>ar[i].u>>ar[i].v>>ar[i].w;

   /* for(i=0;i<e;i++)
        for(j=0;j<e-1-i;j++)
        {
            if(ar[j].w>ar[j+1].w)
            {
                edge temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }*/
        sort(ar,ar+e);
        i=0;
        while(c<n-1)
        {
            int a=find(ar[i].u);
            int b=find(ar[i].v);
            if(uni(a,b))
               {
                   cout<<"\nEdge "<<ar[i].u<<" to Edge "<<ar[i].v<<" Weight "<<ar[i].w<<endl;
                   c++;
                   mst+=ar[i].w;
                }
                i++;
        }
        cout<<"MST IS "<<mst;
        return 0;
}
