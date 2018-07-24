/** Traveling Salesman Problem using brute force, Time Complexity: O(N! )
 ** @author: Arpan Pathak **/
#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
int G[100][100];
int main(){
    string permutation="",route="";
    int e,n,u,v,w,cost=inf;
    cout<<"Enter number of vertices and edges=";
    cin>>n>>e;
    cout<<"Enter connections(u,v,w) :\n";
    while(e--){ cin>>u>>v>>w; G[u][v]=w; G[v][u]=w; }
    for(int i=0;i<=n;i++) permutation+=(i%n+'0');
    /* Home Town is 0 */
    do{
        int current_cost=0;
        for(int i=0;i<n;i++){
            if(!G[permutation[i]-'0'][permutation[i+1]-'0']){
                current_cost=inf; break;
            }
            current_cost+=G[permutation[i]-'0'][permutation[i+1]-'0'];
        }
        if(current_cost<cost ){
            cost=current_cost;
            route=permutation;
        }
    }while(next_permutation(permutation.begin()+1,permutation.end()-1));
    cout<<"Minimum Cost of TSP="<<cost<<endl;
    cout<<"TSP route : "<<route;
    return 0;
}
/** Connections .....
5
8
0 1 1
0 2 1
0 3 1
0 4 8
1 2 5
1 3 3
2 3 6
3 4 2
    Expected TSP cost=19
    best TSP route : 0-->2-->1-->3-->4-->0
**/
