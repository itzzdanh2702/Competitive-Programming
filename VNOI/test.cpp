#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 3 * 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, k;
int a[MAXN];
ll pre[MAXN];
ll dp[4][MAXN];
ll ma[4][MAXN];
ll mi;
ll ans;
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = pre[i] + ma[0][i - 1];
        dp[1][i] = pre[i] + ma[1][i - 1];
        dp[2][i] = k * pre[i] + ma[2][i - 1];
        dp[3][i] = pre[i] + ma[3][i - 1];
        ma[0][i] = max({0LL, ma[0][i - 1], -pre[i]});
        ma[1][i] = max(ma[1][i - 1], max(0LL,k * dp[0][i]) - pre[i]);
        ma[2][i] = max(ma[2][i - 1], max(0LL,dp[0][i]) - k * pre[i]);
        ma[3][i] = max(ma[3][i - 1], dp[2][i] - pre[i]);
        ans = max({ans, dp[0][i], dp[1][i], dp[2][i], dp[3][i]});
    }
    cout << ans;
    return 0;
    /*
    mi = min(mi,pre[i]);
    tmp = pre[i] - mi;
    f[0][i] = tmp;
    f[1][i] = pre[i] - pre[j - 1] + k * f[0][j - 1];
            = pre[i] + (k * f[0][j - 1] - pre[j - 1]);
    f[2][i] = k * (pre[i] - pre[j - 1]) + f[0][j - 1];
            = k * pre[i]  + (f[0][j - 1] - k * pre[j - 1]);
    f[3][i] = pre[i] - pre[j - 1] + f[2][j - 1];
    */
}