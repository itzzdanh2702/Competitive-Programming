#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
ll d[100005], n, m, s, t, q;
vector<ii> a[100005];
void dijkstra(ll s)
{
    fill(d + 1, d + n + 1, 1e18);
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (q.size())
    {
        ll u = q.top().se;
        ll dist = q.top().fi;
        q.pop();
        if (dist != d[u])
            continue;
        for (auto i : a[u])
        {
            ll x = i.fi;
            ll y = i.se;
            if (d[x] > max(d[u], y))
            {
                d[x] = max(d[u], y);
                q.push({d[x], x});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    while (m--)
    {
        ll u, v, w, dir;
        cin >> u >> v >> w >> dir;
        a[u].push_back({v, w});
        if (dir == 0)
            a[v].push_back({u, w});
    }
    dijkstra(s);
    ll res = d[t];
    dijkstra(t);
    res = max(res, d[s]);
    // for(int i=1;i<=n;i++) cout<<d[i]<<" ";
    if (res == 1e18)
        cout << -1;
    else
        cout << res;
}