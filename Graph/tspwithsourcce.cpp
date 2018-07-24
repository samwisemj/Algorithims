/* The infamous traveling salesman problem. Done by brute force. Make sure your edge starts from '0'. Time compexity O(n!)..
It will take a source from you and calculate the min path for the tour starting from and ending in it, through all the vertices....
@Author:Subhamoy Sarkar*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e,i,j,**ar,cost=INT_MAX,mincost=INT_MAX;
    cout<<"\t\tTRAVELLING SALESMAN PROBLEM"<<"\nEnter no of vertices :"; cin>>n;
    //cout<<"\nEnter no of edges :"; cin>>e;
    ar=(int **)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        ar[i]=(int *)calloc(n,sizeof(int));
        for(i=0;i<n;i++)for(j=0;j<n;j++)cin>>ar[i][j];
    //cout<<"\nEnter the u v w for all edges"<<endl;
    //while(e--){int u,v,w; cin>>u>>v>>w;ar[u][v]=ar[v][u]=w;}//taking input in adjacency matrix.
    //for(i=0;i<n;i++) ar[i][i]=0;
    int *perm=(int *)calloc(n-1,sizeof(int));//its of n-1 size
    int *route=(int *)calloc(n-1,sizeof(int));//same as perm[]
    int src; cout<<"\nEnter Source : "; cin>>src;
    for(int c=0,i=0;i<n-1;i++,c++) if(i!=src) perm[i]=c; else perm[i]=++c;//initializes the perm[] array...
    sort(perm,perm+(n-1));
    do
    {
        cost=INT_MAX;
        if(ar[src][perm[0]]!=0 && ar[perm[n-1-1]][src]!=0)//if edge from source to first permutated vertex exist ar[u][v] is not 0 and edge from last vertex to source is not zero
        {
            cost=ar[src][perm[0]]+ar[perm[n-1-1]][src];
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
            copy(perm,perm+(n-1),route); //copy the current permutated path in the route
        }
    }while(next_permutation(perm,perm+(n-1)));
        cout<<"\nSoution to tsp is:-";
        cout<<"\nPath taken is "<<endl;
        cout<<src<<"-->";
        for(i=0;i<n-1;i++)
            cout<<route[i]<<"-->";
        cout<<src<<endl<<"Path weight is "<<mincost;
        return 0;
}

