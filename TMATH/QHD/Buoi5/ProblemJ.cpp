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

int n;
ll a[MAXN];
ll sum[MAXN];
ll dp[MAXN];
ll ans = -oo;
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = max(dp[i - 3] + sum[i] - sum[i - 3], sum[i] - sum[i - 3]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}