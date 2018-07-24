#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   long int n,m,a,b,j,i,k,max=0;
    cin>>n>>m;
    long int *ar;
    ar=(long int*)calloc(n+1,sizeof(long int));

    for(j=0;j<m;j++)
        {
        cin>>a>>b>>k;
        for(i=a;i<=b;i++)
            {
            ar[i]+=k;
        }
    }
    for(i=1;i<=n;i++){
        if(ar[i]>max) max=ar[i];
    }
    cout<<max;
    return 0;
}
