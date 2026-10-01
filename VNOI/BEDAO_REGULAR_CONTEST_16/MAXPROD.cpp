#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
ll a[MAXN];
ll b[MAXN];
ll ma = -oo;
ll tmp[MAXN];
ll store[MAXN];
ll S = 0;

void solve(ll x, ll y, ll pos)
{
    if (max(x, y) - min(x, y) >= k)
    {
        if (x > y)
        {
            y += k;
        }
        else
        {
            x += k;
        }
    }
    else
    {
        if (x > y)
        {
            ll tmp1 = k - (x - y);
            y = x;
            if (tmp1 & 1)
            {
                x += (tmp1 - 1) / 2;
                y += (tmp1 - 1) / 2 + 1;
            }
            else
            {
                x += tmp1 / 2;
                y += tmp1 / 2;
            }
        }
        else
        {
            ll tmp1 = k - (y - x);
            x = y;
            if (tmp1 & 1)
            {
                x += (tmp1 - 1) / 2;
                y += (tmp1 - 1) / 2 + 1;
            }
            else
            {
                x += tmp1 / 2;
                y += tmp1 / 2;
            }
        }
    }
    tmp[pos] = x * y;
}

int main()
{
    FAST();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        store[i] = a[i] * b[i];
        S += a[i] * b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        solve(a[i], b[i], i);
        ma = max(ma, tmp[i] - store[i]);
    }
    cout << S + ma;
    // cout << ma;
}