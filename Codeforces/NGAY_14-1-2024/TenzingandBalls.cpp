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
int n;
int a[MAXN], d[MAXN];
ll dp[MAXN], ans[MAXN];

int main(int argc, char const *argv[])
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        memset(ans, 0, sizeof(ans));
        ll ans1 = -oo;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            dp[i] = oo;
            ans[i] = -oo;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (d[a[i]])
            {
                ans[i] = max(ans[i - 1], i - dp[a[i]] + 1);
                dp[a[i]] = min(dp[a[i]], i - ans[i - 1]);
            }
            else
            {
                dp[a[i]] = i - ans[i - 1];
                ans[i] = ans[i - 1];
            }
            d[a[i]] = 1;
        }
        cout << ans[n] << '\n';
    }
    return 0;
}
