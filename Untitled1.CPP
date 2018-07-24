#include <bits/stdc++.h>
using namespace std;
void* operator new(size_t sz) { cout<<"\noperator new: Bytes\n"<< sz; void* m = malloc(sz); if(!m) cout<<"\nout of memory"; return m; } void operator delete(void* m) { cout<<"\noperator delete"; free(m); } class Test { int i[100]; public: Test() { cout<<"\nTest()"; } ~Test() { cout<<"\n~Test()"; } }; int main() {  cout<<"\ncreating & destroying an int"; int* p = new int(47); delete p; cout<<"\ncreating & destroying an s"; Test* s = new Test; delete s; cout<<"\ncreating & destroying S[3]"; Test* sa = new Test[3]; delete []sa; return 0; }
