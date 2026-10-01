#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1e6 + 5;

ll n, q;
ll c[MAXN], sum[MAXN], k, m, res = 1e18;
int pos(ll l, ll r)
{
    ll kq = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (c[mid] <= k)
        {
            l = mid + 1;
            kq = mid;
        }
        else
            r = mid - 1;
    }
    return kq;
}

void chat(ll l, ll r)
{
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (c[mid] <= 2 * k - (c[n - m + mid + 1]))
            l = mid + 1;
        else
            r = mid - 1;
        res = min(res, sum[mid] + 2 * k * (n - (n - m + mid)) - (sum[n] - sum[n - m + mid]));
    }
}

int main()
{
    freopen("B.Inp", "r", stdin);
    freopen("B.Out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + c[i];
    }
    while (q--)
    {
        cin >> k >> m;
        res = 1e18;
        chat(0, min(pos(1, n), (int)(m)));
        cout << res << "\n";
    }
}