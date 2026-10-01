#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll n, ans = 0, s, h = 0, kq = 1, m, a[1005][1005], sl[1005][1005], ktra[1005][1005];
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};
vector<ll> vt1;
pair<ll, ll> root[1005][1005];
struct st
{
    ll fi, se, th;
};
bool cmp(st i, st j)
{
    return i.th < j.th;
}
vector<st> vt;
pair<ll, ll> findroot(ll u, ll v)
{
    if (root[u][v].fi == u && root[u][v].se == v)
        return {u, v};
    return findroot(root[u][v].fi, root[u][v].se);
}
void mergeroot(ll i, ll j, ll u, ll v)
{
    pair<ll, ll> uu = findroot(i, j), vv = findroot(u, v);
    if (uu != vv)
    {
        if (sl[uu.fi][uu.se] >= sl[vv.fi][vv.se])
        {
            sl[uu.fi][uu.se] += sl[vv.fi][vv.se];
            root[vv.fi][vv.se] = {uu.fi, uu.se};
        }
        else
        {
            sl[vv.fi][vv.se] += sl[uu.fi][uu.se];
            root[uu.fi][uu.se] = {vv.fi, vv.se};
        }
        if (h > 0)
            ans--;
    }
}
void check(ll i, ll j)
{
    ktra[i][j] = 1;
    h = 0;
    for (ll l = 0; l < 4; l++)
    {
        int i1 = i + x[l];
        int j1 = j + y[l];
        if (i1 <= n && i1 >= 1 && j1 <= m && j1 >= 1 && ktra[i1][j1] == 1)
        {
            
            mergeroot(i, j, i1, j1);
            h++;
        }
    }
    if (h == 0)
        ans++;
}
void duyet(ll k)
{
    while (vt[s].th > k)
    {
        check(vt[s].fi, vt[s].se);
        s--;
    }
}
int main()
{
	freopen("HONDAONHANTAO.inp","r",stdin);
	freopen("HONDAONHANTAO.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    s = n * m - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            vt1.push_back(a[i][j]);
            vt.push_back({i, j, a[i][j]});
            root[i][j] = {i, j};
            sl[i][j] = 1;
        }
    }
    sort(vt.begin(), vt.end(), cmp);
    sort(vt1.begin(), vt1.end());
    for (int i = vt1.size() - 2; i >= 0; i--)
    {
        if (vt1[i] != vt1[i + 1])
        {
            duyet(vt1[i]);
            kq = max(kq, ans);
        }
    }
    cout << kq;
    return 0;
}