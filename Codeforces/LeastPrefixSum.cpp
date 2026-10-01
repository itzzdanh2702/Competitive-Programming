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
ll n, k;
ll a[MAXN];
ll pre[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        bool check = 0;
        ll pos1 = 0;
        ll pos2 = 0;
        ll res = 0;
        ll S = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = 1; i <= k; ++i)
        {
            if (pre[i] < pre[k])
            {
                pos1 = i;
            }
        }
        if (pos1 != 0)
        {
            priority_queue<ll> pq1;
            for (int i = pos1; i <= k; ++i)
            {
                if (a[i] >= 0)
                    pq1.push(a[i]);
            }
            while (!pq1.empty())
            {
                if ((pre[pos1] < pre[k]) and (pos1 >= 1))
                {
                    if (pq1.top() == a[k])
                        check = 1;
                    pre[k] = pre[k] - 2 * pq1.top();
                    ++res;
                    S += 2 * pq1.top();
                    pq1.pop();
                }
                else if (pre[pos1] >= pre[k])
                {
                    if (pos1 >= 1)
                    {
                        --pos1;
                        pq1.push(a[pos1]);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        ll S2 = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq2;
        for (int i = k + 1; i <= n; ++i)
        {
            pre[i] -= S;
        }
        for (int i = k + 1; i <= n; ++i)
        {
            if (pre[i] < pre[k])
            {
                pos2 = i;
                break;
            }
        }
        for (int i = k + 1; i <= pos2; ++i)
        {
            if (a[i] <= 0)
                pq2.push(a[i]);
        }

        while (!pq2.empty())
        {
            ll tmp = pq2.top();
            if ((pre[pos2] < pre[k]) and (pos2 <= n))
            {
                pq2.pop();
                pre[pos2] += 2 * abs(tmp);
                ++res;
                S2 += 2 * abs(tmp);
                if (pre[pos2] >= pre[k])
                {
                    if (pos2 <= n - 1)
                    {
                        ++pos2;
                        if (a[pos2] <= 0)
                        {
                            pq2.push(a[pos2]);
                        }
                        for (int i = pos2; i <= n; ++i)
                        {
                            pre[i] += S2;
                        }
                        S2 = 0;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if ((pre[pos2] >= pre[k]) and (pos2 <= n))
            {
                if (pos2 <= n - 1)
                {
                    ++pos2;
                    if (a[pos2] <= 0)
                    {
                        pq2.push(a[pos2]);
                    }
                    for (int i = pos2; i <= n; ++i)
                    {
                        pre[i] += S2;
                    }
                    S2 = 0;
                }
                else
                {
                    break;
                }
            }
            cout << res << '\n';
        }
    }
}