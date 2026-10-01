#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll TC;
ll m, n;
ll a[MAXN], b[MAXN];
ll prefix[MAXN], suffix[MAXN];

int main()
{
    cin >> TC;
    while (TC--)
    {
        memset(prefix, 0, sizeof(prefix));
        memset(suffix, 0, sizeof(suffix));
        cin >> m;
        for (int i = 1; i <= m; ++i)
        {
            cin >> a[i];
            prefix[i] = prefix[i - 1] + a[i];
        }
        for (int i = m; i >= 1; --i)
        {
            suffix[i] = suffix[i + 1] + a[i];
        }

        ll best = -10000000, sum = 0;
        for (int i = 1; i <= m; i++)
        {
            sum = max(a[i], sum + a[i]);
            best = max(best, sum);
        }
        sum = 0;
        best = -10000000;
        ll best_start = 0, best_end = 0, current_start = 0;
        for (int i = 1; i <= m; i++)
        {
            if (sum + a[i] < a[i])
            {
                current_start = i;
                sum = a[i];
            }
            else
            {
                sum += a[i];
            }

            if (best < sum)
            {
                best = sum;
                best_start = current_start;
                best_end = i;
            }
        }
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        ll l = 1, r = n;
        while (l <= r)
        {
            if (b[l] > b[r])
            {
                if (b[l] > 0)
                {
                    if (prefix[m] - prefix[best_start - 1] > suffix[1] - suffix[best_end + 1])
                    {
                        if (prefix[m] - prefix[best_start - 1] + b[l] > best)
                        {
                            best = prefix[m] - prefix[best_start - 1] + b[l];
                        }
                        prefix[m] += b[l];
                    }
                    else
                    {
                        if (suffix[1] - suffix[best_end + 1] + b[l] > best)
                        {
                            best = suffix[1] - suffix[best_end + 1] + b[l];
                        }
                        suffix[1] += b[l];
                    }
                }
                else
                {
                    if (prefix[m] - prefix[best_start - 1] < suffix[1] - suffix[best_end + 1])
                    {
                        if (suffix[1] - suffix[best_end + 1] > best)
                        {
                            best = suffix[1] - suffix[best_end + 1];
                        }
                        prefix[m] += b[l];
                    }
                    else
                    {
                        if (prefix[m] - prefix[best_start - 1] > best)
                        {
                            best = prefix[m] - prefix[best_start - 1];
                        }
                        suffix[1] += b[l];
                    }
                }
                ++l;
            }
            else
            {
                if (b[r] > 0)
                {
                    if (prefix[m] - prefix[best_start - 1] > suffix[1] - suffix[best_end + 1])
                    {
                        if (prefix[m] - prefix[best_start - 1] + b[r] > best)
                        {
                            best = prefix[m] - prefix[best_start - 1] + b[r];
                        }
                        prefix[n] += b[r];
                    }
                    else
                    {
                        if (suffix[1] - suffix[best_end + 1] + b[r] > best)
                        {
                            best = suffix[1] - suffix[best_end + 1] + b[r];
                        }
                        suffix[1] += b[r];
                    }
                }
                else
                {
                    if (prefix[m] - prefix[best_start - 1] < suffix[1] - suffix[best_end + 1])
                    {
                        if (suffix[1] - suffix[best_end + 1] > best)
                        {
                            best = suffix[1] - suffix[best_end + 1];
                        }
                        prefix[m] += b[r];
                    }
                    else
                    {
                        if (prefix[m] - prefix[best_start - 1] > best)
                        {
                            best = prefix[m] - prefix[best_start - 1];
                        }
                        suffix[1] += b[r];
                    }
                }
                --r;
            }
        }
        cout << best << '\n';
    }
}