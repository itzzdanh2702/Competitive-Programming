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

ll n, k;
ll dp[MAXN];

int main()
{
    FAST();
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (i - j >= 0)
            {
                dp[i] = ((dp[i] % MOD) + (dp[i - j] % MOD)) % MOD;
            }
        }
    }
    cout << dp[n];
}