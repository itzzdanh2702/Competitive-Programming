#include <bits/stdc++.h>
using namespace std;
#define ll long long
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, m;
char a[305][305];
int pre[305][305][8];
ll dp[305][305][8];
ll ans = 0;
ll cal(int current_row, int current_column, int past_row, int past_column, int k)
{
    return dp[current_row][current_column][k] - dp[current_row][past_column - 1][k] - dp[past_row - 1][current_column][k] + dp[past_row - 1][past_column - 1][k];
}
int main()
{
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int j = 1; j <= m; ++j)
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= 7; ++k)
            {
                pre[i][j][k] = pre[i - 1][j][k];
                if (a[i][j] - '0' == k)
                    pre[i][j][k] += 1;
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 1; k <= 7; ++k)
                dp[i][j][k] = pre[i][j][k] + dp[i][j - 1][k];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int i1 = 1; i1 <= i; ++i1)
            {
                int pos = j;
                while (pos >= 1)
                {
                    bool check = 1;
                    for (int colour = 1; colour <= 7; ++colour)
                    {
                        if (!cal(i, j, i1, pos, colour))
                        {
                            check = 0;
                            break;
                        }
                    }
                    if (!check)
                        --pos;
                    else
                    {
                        ans += pos;
                        break;
                    }
                }
            }
    cout << ans;
}