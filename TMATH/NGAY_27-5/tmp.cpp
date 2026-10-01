#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define fi first
#define se second
#define dim 3
#define tii tuple<int, int, int>
#define inf 0x3f
const ll nx = 2e3 + 9;
const ll bx = 1e3 + 9;
const ll mod = 1e9 + 7;

int n;
ll dp[nx][nx], res = 0;
pli a[nx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    freopen("tmp.inp","r",stdin);
    freopen("tmp.out","w",stdout);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1, greater<pii>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i].fi * abs(a[i].se - (n - (i - j) + 1)));
            else if (j == i)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i].fi * abs(a[i].se - j));
            else
                dp[i][j] = max({dp[i][j], dp[i - 1][j] + a[i].fi * abs(a[i].se - (n - (i - j) + 1)), dp[i - 1][j - 1] + a[i].fi * abs(a[i].se - j)});
            if (i == n)
                res = max(res, dp[i][j]);
        }
    }
    cout << res;
}
