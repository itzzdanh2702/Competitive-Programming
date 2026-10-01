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

int n, dp[MAXN], dp1[MAXN], ans = -oo;
int a[MAXN], b[MAXN];
int incr[MAXN], decr[MAXN];

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int it = lower_bound(incr + 1, incr + dp[i - 1] + 1, a[i]) - incr;
        incr[it] = a[i];
        dp[i] = max(dp[i - 1], it);
    }
    decr[n + 1] = oo;
    for (int i = n; i >= 1; --i)
    {
        int it = lower_bound(decr + 1, decr + dp1[i + 1] + 1, a[i]) - decr;
        decr[it] = a[i];
        dp1[i] = max(dp1[i + 1], it);
    }
    cout << dp1[n] << ' ';
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > decr[dp1[i + 1]])
            ans = max(ans, dp[i] + dp1[i + 1]);
        cout << ans << ' ';
    }
    if (ans & 1)
        cout << ans;
    else
        cout << ans - 1;
}