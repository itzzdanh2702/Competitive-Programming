#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1e5 + 5;
ll TC;
ll n;
ll pre[MAXN];
ll dp[MAXN];
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> TC;
    while (TC--)
    {
        ll ma = -1;
        ll sum = 0;
        ll S = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
            S += a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = min(dp[i - 1], pre[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == n)
            {
                ll ma1 = -1;
                for (int j = 2; j <= n; ++j)
                {
                    ma1 = max(ma1, pre[n] - pre[j - 1]);
                }
                ma = max(ma,ma1);
            }
            else
                ma = max(ma, pre[i] - dp[i]);
        }
        if (ma >= S)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }
}
