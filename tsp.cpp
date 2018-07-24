#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e,i,**ar;
    cout<<"\t\tTRAVELLING SALESMAN PROBLEM"<<"\nEnter no of vertices :"; cin>>n;
    cout<<"\nEnter no of edges :"; cin>>e;
    ar=(int **)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        ar[i]=(int *)calloc(n,sizeof(int));
    cout<<"\nEnter the u v w for all edges"<<endl;
    while(e--){int u,v,w; cin>>u>>v>>w;ar[u][v]=ar[v][u]=w;}//taking input in adjacency matrix.
    for(i=0;i<n;i++) ar[i][i]=0;
    int *perm=(int *)calloc(n-1,sizeof(int));//its of n-1 size
    for(i=0;i<n-1;i++) perm[i]=i+1;//initialize perm[]
    int *route=(int *)calloc(n-1,sizeof(int));//same as perm[]
    int cost=INT_MAX;int mincost=INT_MAX;
    in src;
    //sort(perm,perm+(n-1));
    do
    {
        cost=INT_MAX;
        if(ar[0][perm[0]]!=0 && ar[perm[n-1-1]][0]!=0)//if edge from source to first permutated vertex exist ar[u][v] is not 0 and edge from last vertex to source is not zero
        {
            cost=ar[0][perm[0]]+ar[perm[n-1-1]][0];
            for(i=0;i<n-1-1;i++)//perm list is till n-1 and additional -1 as we check the next perm...so to prevent array index out of bounds
            {
                if(ar[perm[i]][perm[i+1]]!=0)
                    cost+=ar[perm[i]][perm[i+1]];
                else
                {
                    cost=INT_MAX;
                    break;
                }
            }
        }
        if(mincost>cost)//after adding the weight if the cost of the path is found smaller, we shall save it
        {
            mincost=cost;
            for(i=0;i<n-1;i++) route[i]=perm[i]; //copy the current permutated path in the route
        }
    }while(next_permutation(perm,perm+(n-1)));
        cout<<"\nSoution to tsp is:-";
        cout<<"\nPath taken is "<<endl;
        cout<<"0-->";
        for(i=0;i<n-1;i++)
            cout<<route[i]<<"-->";
        cout<<"0"<<endl<<"Path weight is "<<mincost;
        return 0;
}
