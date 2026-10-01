#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200005;
long long dp[MAXN][2], x[MAXN], y[MAXN];

ll i, n, s, j;
ll TC;
ll a[MAXN];

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n >> s;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i == 1 || i == n)
                x[i] = y[i] = a[i];
            else if (a[i] <= s)
                x[i] = 0, y[i] = a[i];
            else
                x[i] = s, y[i] = a[i] - s;
        }
        dp[1][0] = dp[1][1] = 0;
        for (i = 2; i <= n; i++)
        {
            dp[i][0] = min(dp[i - 1][0] + y[i - 1] * x[i], dp[i - 1][1] + x[i - 1] * x[i]);
            dp[i][1] = min(dp[i - 1][0] + y[i - 1] * y[i], dp[i - 1][1] + x[i - 1] * y[i]);
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}