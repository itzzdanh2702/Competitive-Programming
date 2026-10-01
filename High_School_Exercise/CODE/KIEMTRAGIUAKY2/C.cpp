#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll m, n;
ll a[MAXN];
ll b[MAXN];
ll dp[5005][5005][1][1];

int main()
{
    FAST();
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
    }
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i] % 2 == 1)
            {
                dp[i][j][0][0] = max(dp[i - 1][j][0][0], dp[i - 1][j][0][1]);
                dp[i][j][1][0] = max(dp[i - 1][j][1][0] + 2, dp[i - 1][j][1][0], dp[i - 1][j][0][0] + 1);
            }
            if (a[i] % 2 == 0)
            {
                dp[i][j][1][0] = max(dp[i - 1][j][1][0], dp[i - 1][j][1][1]);
                dp[i][j][0][0] = max(dp[i - 1][j][0][0] + 2, dp[i - 1][j][0][0], dp[i - 1][j][1][0] + 1);
            }
            if(b[j] % 2 == 1)
            {
                dp[i][j][0][1] = max(dp[i][j - 1][0][0], dp[i][j - 1][0][1]);
                dp[i][j][1][1] = max(dp[i][j - 1][1][1] + 2, dp[i][j - 1][1][1], dp[i][j - 1][0][1] + 1);
            }
            if(b[j] % 2 == 0)
            {
                dp[i][j][1][1] = max(dp[i][j - 1][1][0], dp[i][j - 1][1][1]);
                dp[i][j][0][1] = max(dp[i][j - 1][0][1] + 2, dp[i][j - 1][0][1], dp[i][j - 1][1][1] + 1);
            }
        }
    }
}