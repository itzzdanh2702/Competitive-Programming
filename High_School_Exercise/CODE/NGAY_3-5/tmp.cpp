/*
┏━━━━━━━━━━━━━━━━━━━━┓
*   By Trung113395   *
┗━━━━━━━━━━━━━━━━━━━━┛
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second
const ll nx = 1e4 + 9;
const ll bx = 1e9 + 6;
const ll mod = 1e9 + 7;
ll n, a[nx], mi = 1e18, ans = 1e18, dp[nx], t;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        mi = ans = 1e18;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            mi = min(mi, a[i]);
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 0; j < 5; j++)
            {
                ll tmp = (a[i] - mi + j) / 5;
                tmp += (((a[i] - mi + j) % 5) / 2);
                tmp += (((a[i] - mi + j) % 5) % 2);
                dp[j] += tmp;
            }
        }
        for (ll i = 0; i < 5; i++)
        {
            ans = min(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}