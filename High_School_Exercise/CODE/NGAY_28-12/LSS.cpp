#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long
#define MAXN 1000005
#define oo 1000000000

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int m, n;
int a[MAXN];
int b[MAXN];
int pre[MAXN];
int ans;
int main()
{
    freopen("LSS.inp", "r", stdin);
    freopen("LSS.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int j = 1; j <= n; j++)
        cin >> b[j];

    for (int i = 1; i <= n; i++)
    {
        ll l = 1, r = m;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (pre[mid] <= b[i])
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << ' ';
    }
}