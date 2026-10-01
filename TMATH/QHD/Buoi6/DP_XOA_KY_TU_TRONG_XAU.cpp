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
int dp[21][21];
string S, T;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int ans = -oo;
        memset(dp, 0, sizeof(dp));
        cin >> S >> T;
        int n = S.size();
        int m = T.size();
        S = " " + S;
        T = " " + T;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (S[i] == T[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        ans = max(0, ans);
        cout << m + n - ans * 2 << '\n';
        /*
            dp[i][j] : do dai xau con chung dai nhat ket thuc truoc i va truoc j
        */
    }
    return 0;
}
