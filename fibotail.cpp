#include<bits/stdc++.h>

using namespace std;
int fibo(int n,int b,int c)
{
    if(n<=1)
        return c;
    return fibo(n-1,c,b+c);
}

int main()
{
    int c=fibo(5,1,0);
    cout<<c;
}
