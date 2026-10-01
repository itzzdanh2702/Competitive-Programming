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
    cin >> n >> k;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (i < k)
            dp[i] += 2 * dp[i - 1];
        else
            dp[i] += ((2 * dp[i - 1] - dp[i - k - 1]) + (long long)MOD * MOD) % MOD;
        dp[i] %= MOD;
    }
    cout << dp[n];
}