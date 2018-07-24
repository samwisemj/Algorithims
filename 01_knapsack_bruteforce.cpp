#include <bits/stdc++.h>
using namespace std;
typedef struct c{int wt,profit;}item;
int main()
{
    item *ar;
    int i,j,current_wt,knapsack_wt,n,k,*req,*item_taken,counter,max_wt=0,profit_counter,required_wt,max_profit=0;
    int kol=0,lol=0,mol=0;
    cout<<"Enter the no of items"<<endl; cin>>n;
    ar=(item *)malloc(n*sizeof(item));
    cout<<"Enter the item details"<<endl;
    for(i=0;i<n;i++)
        cin>>ar[i].wt>>ar[i].profit;
    int *perm=(int *)malloc(n*sizeof(int)); for(i=0;i<n;i++) perm[i]=i;
    req=(int *)calloc(n,sizeof(int)); item_taken=(int *)calloc(n,sizeof(int));
    cout<<"Enter total knapsack capacity"<<endl; cin>>knapsack_wt;

    do
    {
        if(lol==10) mol=lol=kol=0;
        cout<<lol++<<kol++<<mol++;
        current_wt=0;counter=0;profit_counter=0;
        //required_wt=knapsack_wt;
        for(i=0;i<n;i++)
        {
            if(ar[perm[i]].wt + current_wt <= knapsack_wt)//if the current item wt is less than or eq to req wt i will consider that item...
            {
                current_wt+=ar[perm[i]].wt;
                //required_wt-=ar[perm[i]].wt;
                req[counter++]=perm[i];
                profit_counter+=ar[perm[i]].profit;
            }
            else
                continue;
        }
        if(max_profit<profit_counter)
        {
            max_profit=profit_counter;
            for(i=0;i<counter;i++) item_taken[i]=req[i];
            k=counter;
            max_wt=current_wt;
        }
        cout<<"\b\b\b";
    }while(next_permutation(perm,perm+n));
     cout<<"Profitable solution for knapsack"<<endl;
     for(i=0;i<k;i++)
        cout<<i+1<<" . Weight = "<<ar[item_taken[i]].wt<<" Profit = "<<ar[item_taken[i]].profit<<endl;
     cout<<"Maximum profit is "<<max_profit<<endl;
     cout<<"Maximum weight is "<<max_wt;
     return 1;
}
/*
3
10 60
20 100
30 120
50
Expected o/p = 220


15 12
25 20
45 21
20 26
14 25
35 16
25 14
10 58
45 18
10 15
55 10
12 42
18 22
20 14
15 13
*/
