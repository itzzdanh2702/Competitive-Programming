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

string S;
int dp[MAXN][1];
int n;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n;
    cin >> S;
    S = " " + S;
    for (int i = 1; i <= n; ++i)
    {
        if (S[i] == 'A')
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + 1;
        }
        else
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << dp[i][0] << ' ';
    return 0;
}
// M với em Tuấn 