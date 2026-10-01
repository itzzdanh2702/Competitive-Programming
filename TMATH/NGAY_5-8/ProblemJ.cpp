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

int n, x;
int a[MAXN];
ll dp[MAXN];

int main(int argc, char const *argv[])
{
    FAST();
    freopen("COIN.INP","r",stdin);
    freopen("COIN.OUT","w",stdout);
    
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    dp[0] = 1;

    for (int j = 1; j <= n; ++j)
    {
        for (int i = 1; i <= x; ++i)
        {
            if (i >= a[j])
            {
                dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
            }
        }
    }

    cout << dp[x];
    return 0;
}
