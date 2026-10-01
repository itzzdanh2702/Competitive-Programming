#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 998244353;

int TC;
int l, r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MaximumSet.inp", "r", stdin);
    freopen("MaximumSet.out", "w", stdout);
    cin >> TC;
    while (TC--)
    {
        cin >> l >> r;
        int tmp = l, dem = 0;
        while (tmp <= r)
        {
            tmp *= 2;
            ++dem;
        }
        ll ans1 = 0;
        ll l1 = l, r1 = r;
        ll kq1 = 0;
        while (l1 <= r1)
        {
            ll mid1 = (l1 + r1) / 2;
            ll P = mid1;
            for (int i = 2; i <= dem; ++i)
            {
                P *= 2;
            }
            if (P <= r)
            {
                l1 = mid1 + 1;
                kq1 = mid1 - l + 1;
            }
            else
            {
                r1 = mid1 - 1;
            }
        }
        kq1 %= MOD;
        ll kq2 = 0;
        for (int i = 2; i <= dem; ++i)
        {
            ll ans3 = 0;
            ll l2 = l, r2 = r;
            while (l2 <= r2)
            {
                ll mid2 = (l2 + r2) / 2;
                ll ans2 = mid2;
                for (int j = 2; j <= dem; ++j)
                {
                    if (j == i)
                    {
                        ans2 *= 3;
                    }
                    else
                    {
                        ans2 *= 2;
                    }
                }
                if (ans2 <= r)
                {
                    l2 = mid2 + 1;
                    ans3 = mid2 - l + 1;
                }
                else
                {
                    r2 = mid2 - 1;
                }
            }
            kq2 += ans3;
            kq2 %= MOD;
        }
        cout << dem << ' ' << (kq1 + kq2) % MOD << '\n';
    }
}
