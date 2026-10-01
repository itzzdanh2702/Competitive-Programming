#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 14062008;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
ll x;
ll dp[MAXN];
bool visited[MAXN];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> x;
        visited[x] = true;
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (visited[i])
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = (dp[i - 1] % MOD) + (dp[i - 2] % MOD);
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
}