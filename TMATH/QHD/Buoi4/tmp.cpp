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

int n, m, k;
int cnt = 0;
int a[1505][1505];
ll ans = -oo;
ll pre[1505][1505], pre1[1505][1505];
ll S = 0;

int main()
{
    FAST();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            pre[j][i] = pre[j - 1][i] + a[j][i];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            pre1[i][j] = pre1[i][j - 1] + pre[i][j];
        }
    }
    for (int i = k; i <= n; ++i)
    {
        for (int j = k; j <= m; ++j)
        {
            ans = max(ans, pre1[i][j] - pre1[i - k][j] - pre1[i][j - k] + pre1[i - k][j - k]);
        }
    }
    cout << ans;
    // 4 3 2 1  
    // 4 3 2 3 
}