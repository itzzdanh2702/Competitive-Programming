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

ll TC;

int main()
{
    cin >> TC;
    while (TC--)
    {
        ll size1;
        ll ma = -1;
        ll m, n;
        string S, tmp;
        cin >> size1;
        cin >> S;
        tmp = S;
        m = S.size();
        n = S.size();
        reverse(S.begin(), S.end());
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (tmp[i - 1] == S[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            ma = max(ma, dp[i][m - i]);
        }
        cout << ma << '\n';
    }
}
