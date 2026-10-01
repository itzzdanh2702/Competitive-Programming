#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
#define MAXN 100005
#define oo 10000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
ll a[MAXN], b[MAXN];
ll ans;

ll find_pos(ll x, int pos_a, int pos_b, ll a[], ll b[])
{
    ll ans = 0;
    int tmp_pos = pos_b + 1;
    for (int i = pos_a - 1; i >= 1; --i)
    {
        while ((tmp_pos <= n) && (x >= a[i] + b[tmp_pos]))
        {
            ++tmp_pos;
        }
        ans += tmp_pos - pos_b - 1;
    }
    return ans;
}

bool check(ll p)
{
    pii pos;
    ll mi = oo, ans;
    for (int i = 1; i <= n; ++i)
    {
        int it = upper_bound(b + 1, b + n + 1, p - a[i]) - b - 1;
        if (it == 0)
            continue;
        if ((p - (b[it] + a[i]) >= 0) && (p - (b[it] + a[i]) < mi))
        {
            pos = {i, it};
            mi = p - (b[it] + a[i]);
            ans = b[it] + a[i];
        }
    }
    if (pos.fi * pos.se + find_pos(ans, pos.fi, pos.se, a, b) + find_pos(ans, pos.se, pos.fi, b, a) >= k)
        return true;
    return false;
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
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    ll l = 0, r = 1e10;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
            // cout << ans << ' ';
        }
        else
            l = mid + 1;
    }
    cout << ans;
}
//
/*
    1 2 3 4 5
    2 3 4 5 6
    14
    [3,5] 9 --> co 14 so nho hon 9
    9 8 7 6 7 8 9
    3 4 4 5 5 5 6 6 6 6 7 7 7 7 7 8 8 8 8 9 9 9 10 10 11
    co 3 so chac chan nho hon 5: 3 4 4
    6
    buoc 1: tim gia tri a[i] + b[j] <= mid
    buoc 2: tim vi tri cua gia tri a[i] + b[j] theo cac buoc nhu tren
    buoc 3: --> neu nhu k < so gia tri nho hon a[i] + b[j] + so gia tri nho hon hoac bang k trong .....
                    giam gia tri mid
                neu k >= .....
                    tang gia tri mid
                    ans = mid
    buoc 4: tim 2 gia tri lien ke ans trong tat ca cac tong
    buoc 5: tim vi tri cua 2 gia tri do
*/