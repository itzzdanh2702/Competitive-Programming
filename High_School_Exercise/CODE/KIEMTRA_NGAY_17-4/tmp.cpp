#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
bool visited[1005];
ll u, v, percent, dirt;
ll m;
ll kq[MAXN];
long double dp[MAXN];
struct store
{
    ll node, percent, dirt;
};
bool leaf[MAXN];
vector<store> dinhke[MAXN];
void dfs(ll k)
{
    visited[k] = true;
    for (auto x : dinhke[k])
    {
        if (!visited[x.node])
        {
            dfs(x.node);
            if(leaf[x.node])
            {
                dp[x.node] = kq[x.node];
            }
            else if (!leaf[x.node])
            {
                if (x.dirt == 1)
                    dp[k] = max(dp[k],(long double)(sqrt(dp[x.node]) * 100 / x.percent));
                else
                    dp[k] = max(dp[k], ((long double)(dp[x.node] * 100) / x.percent));
            }
        }
    }
}
int main()
{
    // freopen("FISH.inp", "r", stdin);
    // freopen("FISH.out", "w", stdout);
    cin >> m;
   
    for(int i = 1 ; i < m ; ++i)
    {
        cin >> u >> v >> percent >> dirt;
        dinhke[u].push_back({v, percent, dirt});
        dinhke[v].push_back({u, percent, dirt});
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> kq[i];
        if (kq[i] == -1)
        {
            leaf[i] = 1;
        }
        else
        {
            leaf[i] = 0;
        }
    }
    dfs(1);
    cout << fixed << setprecision(4) << dp[1]; 
}
