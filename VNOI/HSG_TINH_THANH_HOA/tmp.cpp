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

int n, m;
int a[1005][1005];
ll pre[1005][1005], pre1[1005][1005];
ll ans[1005][1005];
ll ma = -oo;

int main()
{
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            pre[i][j] = pre[i - 1][j - 1] + a[i][j];
            pre1[i][j] = pre1[i - 1][j + 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i + j - 1 <= n)
                ans[i][j] = pre1[i + j - 1][1];
            else
                ans[i][j] = pre1[m][j - m + i];
            if (j + n - i <= m)
                ans[i][j] += pre[n][j + n - i];
            else
                ans[i][j] += pre[i + m - j][m];
            ma = max(ma,ans[i][j] - a[i][j]); 
        }
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= m ; ++j)
        {
            cout << ans[i][j] - a[i][j] << ' ';
        }
        cout << '\n'; 
    }
    cout << ma; 
}
// hihii nhân cột mốc pvn bằng tuổi với mik, trước hết mik chúc cho pvn sẽ luôn mạnh khỏe, 