#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll nmax = 1e6;
const ll nmax1 = 1e9;
#define pii pair<ll, ll>
#define fi first
#define se second

ll n, m, p, x, s, t, mid, ans;
ll a[nmax], d[nmax];

vector<pii> dinhke[nmax];
vector<ll> v1;
queue<ll> qu;

bool bfs(int u, int val)
{
    fill(d, d + nmax, 1e18);
    d[u] = 0;
    qu.push(u);
    while (!qu.empty())
    {
        ll tmp = qu.front();
        qu.pop();
        for (auto it : dinhke[tmp])
        {
            if ((it.se >= val) and (d[it.fi] == 1e18))
            {
                d[it.fi] = 0;
                qu.push(it.fi);
            }
        }
    }
    if (d[t] == 0)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> s >> t;
    while (n--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        dinhke[u].push_back({v, w});
        dinhke[v].push_back({u, w});
    }
    fill(d, d + nmax, 1e18);
    ll l = 1, r = nmax1;

    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (bfs(s, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (ans == 0)
        cout << "-1";
    else
        cout << ans;
}