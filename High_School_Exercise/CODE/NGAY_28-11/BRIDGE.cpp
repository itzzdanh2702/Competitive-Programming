#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[1000][1000], m, n, u, v, trace[100005], k, dem = 0, g, ans;
vector<ll> dinhke[100005];
vector<ll> vec;
bool visited[100005];
void dfs(int k)
{
    visited[k] = true;
    for (int x : dinhke[k])
    {
        if (!visited[x])
        {
            trace[x] = u;
            dfs(x);
        }
    }
}

int main()
{
    freopen("bridge.inp", "r", stdin);
    freopen("bridge.out", "w", stdout);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        dinhke[u].push_back(v);
        dinhke[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1;
}