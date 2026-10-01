#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
ll m, n;
ll ans;
ll dp[nmax];
ll sum[nmax];
ll a[nmax];
bool visited[nmax];
char s[nmax];
vector<pii> dinhke[nmax];
void dfs(int u)
{
    visited[u] = true;
    for (auto x : dinhke[u])
    {
        if (!visited[x.fi])
        {
            dfs(x.fi);
            ans += sum[u] * ((x.se * (sum[x.fi] + 1) % MOD)) % MOD;
            sum[u] = sum[u] + x.se * (sum[x.fi] + 1);
            sum[u] %= MOD;
       
        }
    }
    ans += sum[u];
    ans %= MOD;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dinhke[u].push_back({v, w});
        dinhke[v].push_back({u, w});
    }
    dfs(1);
    cout << ans;
}
