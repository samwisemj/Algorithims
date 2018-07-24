/*Distribute n cows to n^2 farmers such that each farmer gets equal amount of milk.
The cows are tagged as 1,2,3,4....till n^2 and each cows produce milk as per their tags...

@author :Subhamoy Sarkar*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cout<<"Enter the no of farmers :"<<endl;
    cin>>n;
    int ar[n][n];
    for(i=0;i<n;i++)
        ar[0][i]=i+1;
    for(i=1;i<n;i++)
        for(j=0;j<n;j++)
        {
            ar[i][j]=ar[i-1][j]+1;
            if(ar[i][j]>n)
                ar[i][j]-=n;
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ar[i][j]=(n*j)+ar[i][j];
    cout<<"The solution is :-"<<endl;
    for(i=0;i<n;i++)
        {   int sum=0;
            cout<<endl<<"Farmer "<<(i+1)<<":"<<"   ";
            for(j=0;j<n;j++)
            {
                cout<<ar[i][j]<<" ";
                sum+=ar[i][j];
            }
        cout<<"  Milk = "<<sum;
        }
}
