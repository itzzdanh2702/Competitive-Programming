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
ll n;
ll dp[MAXN];

int main()
{
    FAST();
    cin >> n;
    dp[0] = dp[1] = 1;
    for(int i = 2 ; i <= n ; ++i)
    {
        dp[i] = ((dp[i - 1] % MOD) + (dp[i - 2] % MOD))%MOD;
    } 
    cout << dp[n];
}
