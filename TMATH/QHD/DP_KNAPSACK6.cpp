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

ll min_val = 1e9;
ll n;
ll S;
ll a[MAXN], dp[MAXN];
ll ans = 0;

int main()
{
    cin >> n >> S;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    dp[min_val] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = min_val; j <= S; ++j)
        {
            dp[i] = dp[i] + dp[j - a[i]];
        }
        ans += dp[i];
    }

    cout << ans;
}
