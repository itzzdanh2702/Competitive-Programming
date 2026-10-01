#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2 * 100000;

ll a[MAXN];
ll n, k;
ll sum_odd[MAXN], sum_even[MAXN];
ll total_even[MAXN], total_odd[MAXN]; // even : chan , odd : le;
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
    sum_odd[0] = sum_even[0] = total_even[0] = total_odd[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            sum_even[i] = sum_even[i - 1] + a[i];
            sum_odd[i] = sum_odd[i - 1];
            total_even[i] = total_even[i - 1] + 1;
            total_odd[i] = total_odd[i - 1];
        }
        else
        {
            sum_odd[i] = sum_odd[i - 1] + a[i];
            sum_even[i] = sum_even[i - 1];
            total_odd[i] = total_odd[i - 1] + 1;
            total_even[i] = total_even[i - 1];
        }
        val[i] = sum_even[i] - sum_odd[i];
    }
    pos[0].push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        pos[val[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        ll ans = 0;
        ll l = 1, r = i;
        if (a[i] % 2 == 0)
        {
            ll pos_odd = 0;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (total_odd[mid] == total_odd[i])
                {
                    r = mid - 1;
                }
                else
                {
                    pos_odd = mid; // tim vi tri le gan nhat
                    l = mid + 1;
                }
            }
            for (int p = 1; p <= k; ++p)
            {
                ll pos_equal = 0;
                if (pos[val[i] - p].size() > 0)
                {
                    ll l = 0, r = pos[val[i] - p].size() - 1;
                    while (l <= r)
                    {
                        ll mid = (l + r) / 2;

                        if (pos[val[i] - k][mid] < pos_odd)
                        {
                            l = mid + 1;
                            pos_equal = mid + 1;
                        }
                        else if (pos[val[i] - k][mid] > pos_odd)
                        {
                            r = mid - 1;
                        }
                        else
                        {
                            pos_equal = mid + 1;
                            break;
                        }
                    }
                    ans += pos_equal;
                }
                else
                    continue;
            }
            dp[i] = ans;
        }
        else
        {
            ll pos_even = 0;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (total_even[mid] == total_even[i])
                {
                    r = mid - 1;
                }
                else
                {
                    pos_even = mid; // tim vi tri chan gan nhat
                    l = mid + 1;
                }
            }
            for (int p = 1; p <= k; ++p)
            {
                ll pos_equal = 0;
                if (pos[val[i] - p].size() > 0)
                {
                    ll l = 0, r = pos[val[i] - p].size() - 1;
                    while (l <= r)
                    {
                        ll mid = (l + r) / 2;

                        if (pos[val[i] - p][mid] < pos_even)
                        {
                            l = mid + 1;
                            pos_equal = mid + 1;
                        }
                        else if (pos[val[i] - p][mid] > pos_even)
                        {
                            r = mid - 1;
                        }
                        else
                        {
                            pos_equal = mid + 1;
                            break;
                        }
                    }
                    ans += pos_equal;
                }
                else
                    continue;
            }
            dp[i] = ans;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt += dp[i];
    }
    cout << cnt;
}
