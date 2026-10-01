#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll trace[nmax];
ll n, m, q;
ll dem;
ll u, v;
bool visited[nmax];
set<ll> dinhke[nmax], s1;

/*/int findroot(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = findroot(root[u]);
}
void mergeroot(ll u, ll v)
{
    ll x = findroot(u);
    ll y = findroot(v);
    if (x != y)
        root[x] = y;
}
/*/
void dfs(int i)
{
    visited[i] = true;
    for (auto x : dinhke[i])
    {
        if (!visited[x])
        {
            visited[x] = true;
            trace[x] = i;
            dfs(x);
        }
    }
}
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        dinhke[u].insert(v);
        dinhke[v].insert(u);
    }
    dfs(m);
    while(q--)
    {
        ll k;
        cin>>k; 
        if(trace[k]!=0)
        cout<<trace[k]<<endl;
        else cout<<"-1"<<endl;        
    }
   
}