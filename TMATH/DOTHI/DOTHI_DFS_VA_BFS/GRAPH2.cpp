#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll n,m,t,q;
vector<ll> dinhke[100001];
int main()
{
   
    cin>>n>>m;
    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        dinhke[u].push_back(v); 
    }
   cin>>t;
   while(t--)
   {
    cin>>q;
    cout<<dinhke[q].size()<<" ";
    for(auto x:dinhke[q])
    cout<<x<<" ";
    cout<<endl;
   }

}