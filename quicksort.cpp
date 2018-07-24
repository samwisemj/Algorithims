#include<bits/stdc++.h>
#include <ctime>
using namespace std;

void swp(int *a,int *b){int temp=*b;*b=*a;*a =temp;}
int prtition(int *ar,int start,int endd)
{
    int pivot=ar[endd];
    int pindex=start;
    for(int i=start;i<endd;i++)
     {
         if(ar[i]<=pivot)
            {
                swp(&ar[i],&ar[pindex]);
                pindex++;
            }
     }
    swp(&ar[endd],&ar[pindex]);
    return pindex;
}
void quicksort(int *ar,int start,int endd)
{
    if(start<endd)
    {
        int pindex=prtition(ar,start,endd);
        quicksort(ar,start,pindex-1);
        quicksort(ar,pindex+1,endd);
    }
}
int main()
{
    int n;int *ar;
    cout<<"Enter array size"<<endl;
    cin>>n;
    ar=(int *)malloc(n*sizeof(int));
    cout<<"Enter array"<<endl;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    clock_t s,e;
    s=clock();
    quicksort(ar,0,n-1);
    e=clock();
    cout<<"The sorted array is:"<<endl;
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<"\nClock time "<<(e-s);
}
