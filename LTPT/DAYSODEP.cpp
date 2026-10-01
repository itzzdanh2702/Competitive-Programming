#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2 * 100000 + 5;

ll a[MAXN];
ll n, k;
ll sum_odd[MAXN], sum_even[MAXN]; // even : chan , odd : le;
ll cnt = 0;
ll val[MAXN], dp[MAXN];
vector<ll> pos[MAXN];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sum_odd[0] = sum_even[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            sum_even[i] = sum_even[i - 1] + a[i];
            sum_odd[i] = sum_odd[i - 1];
        }
        else
        {
            sum_odd[i] = sum_odd[i - 1] + a[i];
            sum_even[i] = sum_even[i - 1];
        }
        val[i] = sum_even[i] - sum_odd[i];
    }
    if (n <= 2 * 1000)
    {
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if ((sum_even[j] - sum_even[i - 1] > 0) and (sum_odd[j] - sum_odd[i - 1] > 0))
                {
                    if (sum_even[j] - sum_even[i - 1] - sum_odd[j] + sum_odd[i - 1] <= k)
                    {
                        if (sum_even[j] - sum_even[i - 1] - sum_odd[j] + sum_odd[i - 1] >= 0)
                            cnt++;
                    }
                }
            }
        }
        cout << cnt;
    }
    else if (n > 2 * 1000)
    {

        map<ll, ll> d;
        for (int i = 1; i <= n; i++)
        {
            if (i >= pos)
                ans += d[f[i] - g[i]];
            for (int j = 0; j <= k; j++)
            {
                d[f[i] - g[i] + j]++;
            }
        }
        cout << ans << '\n';
    }
}
