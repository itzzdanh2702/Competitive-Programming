#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 5 * 10001
#define oo 100000000000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, m;
ll a[MAXN];
ll b[MAXN];
ll c[MAXN];
ll dp[105][MAXN];
ll ans = oo;
int main()
{
    freopen("MINEORE.inp", "r", stdin);
    freopen("MINEORE.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= m; ++i)
        cin >> c[i];
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = oo;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == 1)
                if (c[i] == a[j])
                    dp[i][j] = min(dp[i][j - 1], b[j]);
                else
                    dp[i][j] = dp[i][j - 1];
            else if (c[i] == a[j])
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + b[j]);
            else
                dp[i][j] = dp[i][j - 1];
    for (int i = 1; i <= n; ++i)
        if (dp[m][i] > 0)
            ans = min(ans, dp[m][i]);
    if (ans == oo)
        cout << "-1";
    else
        cout << ans;
}