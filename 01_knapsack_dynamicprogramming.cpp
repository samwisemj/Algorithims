#include <bits/stdc++.h>
using namespace std;
int fnmax(int a, int b){if(a>b) return a; else return b; }
typedef struct c{int wt,profit;}item;
int main()
{
    item *ar;
    int **value,n,j,i,kwt,twt=0;
    cout<<"Enter no of items"<<endl; cin>>n;
    cout<<"Enter the weight and profit respectively:"<<endl;
    ar=(item *)malloc((n+1)*sizeof(item));
    for(i=1;i<=n;i++)
        cin>>ar[i].wt>>ar[i].profit;
    cout<<"Enter total knapsack wt";  cin>>kwt;
    int w=0;
    value=(int **)malloc((n+1)*sizeof(int *));
    for(i=0;i<=n;i++)
        value[i]=(int *)malloc((kwt+1)*sizeof(int));
    for(i=0;i<=n;i++) value[i][0]=0; for(i=0;i<=kwt;i++) value[0][i]=0;

    for(i=1;i<=n;i++)
    {
        for(w=1;w<=kwt;w++)
        {
            if(ar[i].wt>w)
                value[i][w]=value[i-1][w];
            else
                value[i][w]=fnmax(value[i-1][w], (ar[i].profit + (value[i-1][w-ar[i].wt])));
        }
    }
    cout<<"Solution to knapsack is"<<endl;
    i=n;w=kwt;
    while(i>0 && w>0)
    {
        if(value[i][w]!=value[i-1][w])
        {
            cout<<"Item with wt "<<ar[i].wt<<" and profit "<<ar[i].profit<<endl;
            twt+=ar[i].wt;
            w-=ar[i].wt;
        }
        i--;
    }
    cout<<"Max value in knapsack : "<<value[n][kwt]<<" and wt is :"<<twt;
    //for(i=0;i<=n;i++){cout<<endl; for(j=0;j<=kwt;j++) cout<<value[i][j]<<"  ";}
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
