#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n, m;
ll trace[nmax];
ll dem = 1;
ll dp[nmax];
vector<ll> dinhke[nmax];
bool visited[nmax];
void dfs(int u)
{
    visited[u]=true;
    for(auto x:dinhke[u])
    {
        if(!visited[x])
        {
            dfs(x);
            dp[u]+=dp[x];
        }
    }
}

int main()
{
    freopen("CHILDTREE.inp","r",stdin);
    freopen("CHILDTREE.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        dinhke[u].push_back(v);
        dinhke[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    dp[i]=1;
    dfs(m);
    for (int i = 1; i <= n; i++)
    {
       cout<<dp[i]<<endl;
    }
}
