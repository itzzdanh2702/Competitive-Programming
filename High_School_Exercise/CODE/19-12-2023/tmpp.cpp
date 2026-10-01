#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 5000 + 5, Inf = 0x3f3f3f3f3f3f3f3f;
ll n = 0, m = 0, a[N] = {}, dp[N] = {};

inline void init()
{
    for (ll i = 0; i <= n; i++)
        a[i] = 0, dp[i] = Inf;
    n = m = 0;
}

inline void solve()
{
    int cnt = 0; 
    scanf("%lld", &n);
    for (ll i = 1, x = 0; i <= n; i++)
    {
        scanf("%lld", &x);
        if (x < n)
            a[x]++; 
    }
    while (a[m])
        m++;
    dp[m] = 0;
    for (ll i = m; i >= 1; i--)
    {
        for (ll j = 0; j < i; j++)
        {
            dp[j] = min(dp[j], dp[i] + i * (a[j] - 1) + j);
        }

    }
    printf("%lld\n", dp[0]);
}

ll T = 0;

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    scanf("%lld", &T);
    for (ll i = 0; i < T; i++)
        init(), solve();
    return 0;
}