#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
bool visited[1005];
int u, v, percent, dirt;
int m;
long double dp[MAXN];
struct store
{
    int node;
    long double percent;
    int dirt;
};
vector<store> dinhke[MAXN];
void dfs(int k)
{
    visited[k] = true;
    for (auto x : dinhke[k])
    {
        if (visited[x.node] == false)
        {
            dfs(x.node);
            if (x.dirt == 1)
            {
                long double tmp = sqrt((long double)dp[x.node]);
                dp[k] = max(dp[k], (long double)tmp / x.percent);
            }

            else
            {
                dp[k] = max(dp[k], (long double)dp[x.node] / x.percent);
            }
        }
    }
}
int main()
{
    freopen("FISH.inp", "r", stdin);
    freopen("FISH.out", "w", stdout);
    memset(visited, false, sizeof(visited));
    cin >> m;
    for (int i = 1; i < m; ++i)
    {
        cin >> u >> v >> percent >> dirt;
        dinhke[u].push_back({v, (long double)percent / 100, dirt});
        dinhke[v].push_back({u, (long double)percent / 100, dirt});
    }
    for (int i = 1; i <= m; ++i)    
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = x;
        }
    }
    dfs(1);
    cout << fixed << setprecision(4) << (long double)dp[1];
}
