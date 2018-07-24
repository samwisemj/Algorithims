#include<bits/stdc++.h>
using namespace std;
class a
{
protected:
    int x;
};
class b:virtual public a
{
    protected:int y;
};
class c:virtual public a
{
    protected : int z;
};
class hello:public b,c
{
    public:
    hello(){
    cin>>x>>y>>z;
    cout<<x<<y<<z;}
};
int main()
{
    hello l;
}
