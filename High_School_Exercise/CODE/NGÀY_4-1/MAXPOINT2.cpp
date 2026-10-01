#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, m;
int dem[MAXN];
int pre[MAXN];
int st[MAXN];
int t;
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = pre[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = max(st[id * 2], st[2 * id + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (v < l or r < u)
    {
        return -oo;
    }
    if (u <= l and r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;

    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int main()
{
    FAST();
    // freopen("MAXPOINT2.inp","r",stdin);
    // freopen("MAXPOINT2.out","w",stdout);
    cin >> n >> m;
    while (m--)
    {
        int u, v, k;
        cin >> u >> v >> k;
        dem[u] += k;
        dem[v + 1] -= k;
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + dem[i];
    }
    build(1, 1, n);
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        cout << get(1, 1, n, p, q) << " ";
    }
}
