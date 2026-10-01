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
int a[MAXN];
int dp[MAXN];

int main()
{
    FAST();
    freopen("decode.inp", "r", stdin);
    freopen("decode.out", "w", stdout);
    cin >> TC;
    memset(dp, 0, sizeof(dp));
    while (TC--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1)
            {
                dp[i + a[i]] = 1;
            }
            else
            {
                if (i - a[i] - 1 == 0)
                {
                    dp[i] = 1;
                }
                if (i - a[i] - 1 > 0)
                {
                    if (dp[i - a[i] - 1] != 0)
                    {
                        dp[i] = 1;
                    }
                }
                if (dp[i - 1] != 0)
                {
                    dp[i + a[i]] = 1;
                }
            }
        }
        if (dp[n] != 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        for (int i = 1; i <= n; ++i)
            dp[i] = 0;
    }
}