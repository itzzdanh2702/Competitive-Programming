#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
ll m, n, l, d[10001], kq = 0, r, s, t, u, o;
vector<pair<ll, ll>> v[10001];
ll dx[4] = {-1, 0, 0, 1};
ll dy[4] = {0, -1, 1, 0};
bool vs[10001];
ll res;
ll ans[10001];
char a[10001];
void dfs(ll u)
{
    vs[u] = true;
    for (auto x : v[u])
    {
        if (!vs[x.fi])
        {
            dfs(x.fi);
            res += ans[u] * (d[x.fi] + 1) + (ans[x.fi] + (d[x.fi] + 1) * x.se) * d[u];
            ans[u] += ans[x.fi] + (d[x.fi] + 1) * x.se;
            d[u] += d[x.fi] + 1;
        }
    }
    res += ans[u];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        v[x + 1].pb({y + 1, w});
        v[y + 1].pb({x + 1, w});
    }
    dfs(1);
    cout << res;
}
