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

int TC;
string S;
int dp[301][301];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        memset(dp, 0, sizeof(dp));
        cin >> S;
        S = " " + S;
        for (int i = 1; i <= S.size(); ++i)
        {
            dp[i][i] = 1;
        }
        for (int i = 1; i <= S.size() - 1; ++i)
            if (S[i] == S[i + 1])
                dp[i][i + 1] = 1;

        for (int len = 2; len <= S.size() - 1; ++len)
        {
            for (int st = 1; st <= S.size(); ++st)
            {
                int en = st + len - 1;
                dp[st][en] = oo;
                if (S[st] == S[en])
                    dp[st][en] = dp[st + 1][en - 1];
                else
                {
                    for (int k = st; k <= en - 1; ++k)
                    {
                        dp[st][en] = min(dp[st][en], dp[st][k] + dp[k + 1][en]);
                    }
                }
            }
        }
        cout << dp[1][S.size()] << '\n';
    }
}