
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000

ll m,n,t;

vector<ll> dinhke[nmax];
bool a[1001][1001],check;

int main()
{
    cin>>m>>n;
    while(n--)
    {
        ll u,v;
        cin>>u>>v;
        dinhke[u].push_back(v);
        dinhke[v].push_back(u);
    }
    cin>>t;
    while(t--)
    {
        check=0;
        ll k,q;
        cin>>k>>q;
        for(auto it:dinhke[k])
        if(it==q)
        check=1;
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
    }
}