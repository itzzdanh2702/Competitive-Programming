#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define inf 0x3f
const ll nx = 109;
const ll bx = 1e4 + 9;
int n, m, a[bx], b[nx][nx], dp[nx][nx], ans = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    memset(dp, inf, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = b[i][j];
            //dp[j][i] = min(dp[j][i], b[j][i]);
        }
    }
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int k = 1; k <= n; k++)    
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (int i = 1; i < m; i++)
        ans += dp[a[i]][a[i + 1]];
    cout << ans;
}