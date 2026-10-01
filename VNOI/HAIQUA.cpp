#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 3 * 100005
const ll oo = 1e18;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
int cnt = 0;
ll t[MAXN], a[MAXN];
ll kq[MAXN];
ll prefix_sum[MAXN];
ll ma = -oo;
vector<ll> v[MAXN], v1;
bool check[MAXN];

ll kadane(ll arr[], ll n)
{
    ll tmp = -oo;
    ll sum = 0;
    for (int q = 1; q <= n; ++q)
    {
        sum = max(arr[q], arr[q] + sum);
        if (sum > tmp)
            tmp = sum;
    }
    return tmp;
}
void sub3()
{
    // chuan bi
    for (int i = 1; i <= n; ++i)
    {
        v[t[i]].push_back(i);
        if (!check[t[i]])
        {
            check[t[i]] = 1;
            v1.push_back(t[i]);
        }
    }
    for (auto x : v1)
    {
        cnt = 0;
        for (int i = 0; i < v[x].size(); ++i)
        {
            if (i == 0)
            {
                ++cnt;
                if (v[x][i] == 1)
                {
                    kq[cnt] = (1 - k) * a[v[x][i]];
                }
                else
                {
                    kq[cnt] = prefix_sum[v[x][i] - 1];
                    ++cnt;
                    kq[cnt] = (1 - k) * a[v[x][i]];
                }
            }
            else
            {
                ++cnt;
                if (v[x][i] - v[x][i - 1] != 1)
                {
                    kq[cnt] = prefix_sum[v[x][i] - 1] - prefix_sum[v[x][i - 1]];
                    ++cnt;
                    kq[cnt] = (1 - k) * a[v[x][i]];
                }
                else
                {
                    kq[cnt] = (1 - k) * a[v[x][i]];
                }
            }
        }
        kq[++cnt] = max(0LL, prefix_sum[n] - prefix_sum[v[x][v[x].size() - 1]]);
        ma = max(ma, kadane(kq, cnt));
    }
    if (v1.size() < k)
    {
        ma = max(ma, prefix_sum[n]);
    }
    cout << ma;
}
int main()
{
    FAST();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    sub3();
}