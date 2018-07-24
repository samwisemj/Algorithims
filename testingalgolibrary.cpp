#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[]={4,4,2,1};int c=0;
  int n=sizeof(ar)/sizeof(*ar);
  // int n=10;
    sort(ar,ar+n);
    do
    {
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<ar[i]<<"  ";
        c++;
    }while(next_permutation(ar,ar+n));
    cout<<"\n"<<c;
    return 0;
}
