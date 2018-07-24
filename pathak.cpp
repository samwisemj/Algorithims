#include<bits/stdc++.h>
using namespace std;
int G[100][100];
int main(){
    string str="";
    int n,e,u,v;
    cout<<"Enter nunber of vertices and edges=";
    cin>>n>>e;
    for(int i=0;i<=n;i++) str+=(i%n+'0');
    cout<<"All possible routes\n";
    do{
       cout<<str<<endl;

   }while(next_permutation(str.begin()+1,str.end()-1));
    return 0;
}
