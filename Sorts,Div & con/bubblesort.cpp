#include <bits/stdc++.h>
using namespace std;
void swp(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int i,j,n;
    cout<<"size??";
    cin>>n;
    int ar[n];
    cout<<"enter elements";
    for(i=0;i<n;i++)
        cin>>ar[i];
    for(i=0;i<n;i++)
        for(j=0;j<n-1-i;j++)
        {
            if(ar[j+1]<ar[j])
                swp(&ar[j],&ar[j+1]);
        }
    for(i=0;i<n;i++)
        cout<<ar[i]<<endl;
}
