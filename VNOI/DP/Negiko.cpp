#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1e9 + 9;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll C[1001][1001], cnt[1001][1001][11], dp[1001][1001], ans = 0;
int n, m, k, a[1001], b[1001];

ll get(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

int main()
{
    FAST();
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    sort(a + 1, a + m + 1, greater<int>());
    sort(b + 1, b + n + 1, greater<int>());
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cnt[i][j][0] = 1;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i] > b[j])
            {
                for (int sz = 1; sz <= k; ++sz)
                {
                    cnt[i][j][sz] += get(get(cnt[i - 1][j][sz], cnt[i][j - 1][sz]), get(-cnt[i - 1][j - 1][sz], cnt[i - 1][j - 1][sz - 1]));
                    cnt[i][j][sz] %= MOD;
                }
            }
            else
            {
                for (int sz = 1; sz <= 10; ++sz)
                {
                    cnt[i][j][sz] += get(get(cnt[i - 1][j][sz], cnt[i][j - 1][sz]), -cnt[i - 1][j - 1][sz]);
                    cnt[i][j][sz] %= MOD;
                }
            }
        }
    }
    cout << cnt[m][n][k];
}
