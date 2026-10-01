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

int TC;
ll n, k;
ll a[MAXN], tmp[MAXN];

bool check(ll p)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int q = 1; q <= n; ++q)
            tmp[q] = a[q];
        bool ok = 0;
        ll cnt = 0;
        cnt += p - a[i];
        if (p - a[i] > k)
            continue;
        tmp[i] = p;
        // for dau co dinh max
        for (int j = i + 1; j <= n; ++j)
        {
            // for thu 2 lay cac vi tri lan can
            if (j == n)
            {
                if (tmp[j] >= tmp[j - 1] - 1)
                {
                    ok = 1;
                    break;
                }
            }
            if (j != n)
            {
                if (tmp[j] >= tmp[j - 1] - 1)
                {
                    // tmp[j] = tmp[j - 1] - 1;
                    // tmp[j] > tmp[j - 1];
                    // chung to max do thoa man
                    ok = 1;
                    break;
                }
                else
                {
                    cnt += tmp[j - 1] - 1 - tmp[j];
                    tmp[j] = tmp[j - 1] - 1;
                }
            }
        }

        if ((ok) && (cnt <= k))
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    FAST();
    // freopen("ToBecomeMax.inp", "r", stdin);
    // freopen("ToBecomeMax.out", "w", stdout);
    cin >> TC;
    while (TC--)
    {
        ll ans = -oo;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ans = max(ans, a[i]);
        }
        ll l = 0, r = 1e13;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (check(mid))
            {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}