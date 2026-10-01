#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

const int MAXN = 5e5+9;

using namespace std;

int n;
ll dp[MAXN];
pair <ll, ll> a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1);

    dp[1] = a[1].se;
    for(int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + a[i - 1].fi - a[i].fi + a[i].se;

    ll pre = 0, res = -1e18;
    for(int i = 1; i <= n; ++i)
    {
        res = max(res, dp[i] - pre);
        pre = min(pre, dp[i] - (a[i + 1].fi - a[i].fi));
    }
    cout << res;

    return 0;
}
