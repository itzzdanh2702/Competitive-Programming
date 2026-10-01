#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string S, T;
long long dp[3001][3001];

int main()
{
    FAST();
    cin >> S >> T;
    S = " " + S;
    T = " " + T;
    for (int i = 1; i <= S.size(); ++i)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= T.size(); ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= S.size(); ++i)
    {
        for (int j = 1; j <= T.size(); ++j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (S[i] == T[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            cout << "dp" << '[' << i << ']' << '[' << j << ']' << '=' << dp[i][j] << '\n';
        }
    }
    //cout << dp[S.size()][T.size()];
}
