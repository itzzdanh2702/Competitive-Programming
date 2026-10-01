#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll m, n, s, t, x, y, z, di;
vector<ll> g[100005];
ll d[100005], a[100005];
vector<ll> dinhke[100005];
set<ll> sp;
void bfs(ll u)
{
    d[u] = 0;
    queue<ll> qu;
    qu.push(u);
    while (qu.size())
    {
        ll tmp = qu.front();
        qu.pop();
        for (auto it : dinhke[tmp])
        {
            if (d[it] > max(d[tmp], abs(a[it] - a[tmp])))
            {
                d[it] = max(d[tmp], abs(a[it] - a[tmp]));
                qu.push(it);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> s >> t;
    for (ll i = 1; i <= m; ++i)
    {
        cin >> a[i];
        d[i] = 1e18;
    }
    while (n--)
    {
        cin >> x >> y;
        dinhke[x].push_back(y);
        dinhke[y].push_back(x);
    }
    bfs(s);
    if (d[t] == 1e18)
        cout << -1;
    else
        cout << d[t];
}
